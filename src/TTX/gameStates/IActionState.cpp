/**
 * Provides the SpaceDots GameState example in the GQE library.
 *
 * @file src/IActionState.cpp
 * @author Ryan Lindeman
 * @date 20120323 - Initial Release
 * @date 20120421 - Make sure SFML 2 doesn't use its default font since it will crash on exit
 * @date 20120512 - Use new RAII Asset style
 */
#include <TTX/gameStates/IActionState.hpp>

IActionState::IActionState(GQE::typeStateID theStateID, GQE::IApp& theApp):
    GQE::IState(theStateID, theApp),
    mWorld(b2Vec2(0.0f, 0.0f))
{
    mWorld.SetAllowSleeping(true);
}

IActionState::~IActionState()
{}

GQE::Instance* IActionState::addInstance(GQE::typePrototypeID thePrototype,
                                         Position2D           thePosition,
                                         Position2D           theInitialImpulse)
{
    GQE::Prototype* prototype = mPrototypes.getPrototype(thePrototype);
    prototype->mProperties.set<Position2D>(POSITION, thePosition);
    prototype->mProperties.set<Position2D>(INITIAL_IMPULSE, theInitialImpulse);

    return prototype->makeInstance();
}

GQE::IEntity* IActionState::addPlayer(int                  theJoy,
        GQE::typePrototypeID thePrototype,
        Position2D           thePosition)
{
    GQE::IEntity* player = 0;
    GQE::IEntity* actor = 0;

    if(mPlayers.find(theJoy) == mPlayers.end())
    {
        player = mPrototypes.getPrototype(PLAYER_PROTO)->makeInstance();
        GQE::Prototype* actorProto = mPrototypes.getPrototype(thePrototype);
        actorProto->mProperties.set<Position2D>(POSITION, thePosition);
        actor = actorProto->makeInstance();

        player->mProperties.set<GQE::IEntity*>(ACTOR,actor);
        player->mProperties.set<int>(JOYSTICK, theJoy);
        actor->mProperties.set<GQE::IEntity*>(PLAYER,player);
    }

    return player;
}

void IActionState::deactivateEntity(GQE::IEntity* theEntity)
{
   if(theEntity)
   {
      theEntity->mProperties.set<bool>(VISIBLE,false);
      b2Body* body = theEntity->mProperties.get<b2Body*>(BODY);
      body->SetActive(false);
   }
}

void IActionState::activeEntity(GQE::IEntity* theEntity)
{
   if(theEntity)
   {
      theEntity->mProperties.set<bool>(VISIBLE,true);
      b2Body* body = theEntity->mProperties.get<b2Body*>(BODY);
      body->SetActive(true);
   }
}

void IActionState::attachEntities(GQE::IEntity* theFather,GQE::IEntity* theChild,GQE::typePropertyID theChildName)
{
   b2Body* childBody = theChild->mProperties.get<b2Body*>(BODY);
   if(childBody)
   {
      childBody->SetActive(false);
      theChild->mProperties.add(FATHER_NODE,0);
      theChild->mProperties.set<GQE::IEntity*>(FATHER_NODE,theFather);

      GQE::Uint32 order = theFather->getOrder();
      theChild->setOrder(order++); //Don't touch otherwise CRASH!!
      theFather->mProperties.add(theChildName,0);
      theFather->mProperties.set<GQE::IEntity*>(theChildName, theChild);

      b2Body* fatherBody = theFather->mProperties.get<b2Body*>(BODY);

      b2JointDef*  jointDef = theChild->mProperties.get<b2JointDef*>(JOINTDEF);

      if(jointDef)
      {
         switch(jointDef->type)
         {
            case b2JointType::e_weldJoint:
               {
                  GQE::typePropertyID anchorPoint = theChild->mProperties.get<GQE::typePropertyID>(ID32_("AnchorPoint"));
                  b2Vec2 fatherAnchorPoint = theFather->mProperties.get<b2Vec2>(anchorPoint);
                  b2WeldJointDef* weldJointDef = static_cast<b2WeldJointDef*>(jointDef);
                  weldJointDef->localAnchorA = fatherAnchorPoint;
                  b2Vec2 localPosition = fatherBody->GetPosition() + fatherAnchorPoint + weldJointDef->localAnchorB;
                  childBody->SetTransform(localPosition,fatherBody->GetAngle());
                  break;
               }
            default:
               break;
         }


         jointDef->bodyA = fatherBody;
         jointDef->bodyB = childBody;
         b2Joint* joint = mWorld.CreateJoint(jointDef);
         theChild->mProperties.set<b2Joint*>(JOINT, joint);
      }
      childBody->SetActive(true);
   }
}


Particles& IActionState::getParticles()
{
   return mParticles;
}

