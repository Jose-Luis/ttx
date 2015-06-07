// =====================================================================================
//
//       Filename:  PhysicSystem.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  15/10/12 12:30:05
//       Revision:  none
//       Compiler:  g++
//
//         Author:  YOUR NAME (),
//        Company:
//
// =====================================================================================

#include <TTX/systems/PhysicSystem.hpp>


PhysicSystem::PhysicSystem(IActionState& theState, b2World& theWorld):
   ISystem("PhysicSystem", theState),
   mWorld(theWorld)
{
   mTimeStep = SPU;
   mVelocityIterations = 6;
   mPositionIterations = 2;
}

PhysicSystem::~PhysicSystem()
{}

void PhysicSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<Position2D>("Position", Position2D(0, 0, 0));
   theEntity->mProperties.add<b2Body*>("Body", 0);
   theEntity->mProperties.add<bool>("Independent", false);
}


void PhysicSystem::updateFixed()
{
   mWorld.Step(mTimeStep, mVelocityIterations, mPositionIterations);

   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();

   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

      while(anQueue != anIter->second.end())
      {
         // get the IEntity address first
         GQE::IEntity* anEntity = *anQueue;

         b2Body* anBody    = anEntity->mProperties.get<b2Body*>("Body");
         b2Vec2 anPosition = anBody->GetPosition();
         float anAngle     = anBody->GetAngle();

         anEntity->mProperties.set<Position2D>("Position", Position2D(anPosition.x, anPosition.y, anAngle * TODEG));

         // Increment the IEntity iterator second
         anQueue++;
      }

      anIter++;
   }

}

void PhysicSystem::updateVariable(float theElapsedTime)
{}

void PhysicSystem::handleInit(GQE::IEntity* theEntity)
{
   GQE::IEntity* aFather = theEntity->mProperties.get<GQE::IEntity*>("FatherNode");

   if (aFather)
   {
      EntityID aName = theEntity->mProperties.get<EntityID>("Name");
      //GQE::typePropertyID aFatherAnchorPoint = theEntity->mProperties.get<GQE::typePropertyID>("FatherAnchorPoint");
      //b2Vec2 aAnchorPoint = aFather->mProperties.get<b2Vec2>(aFatherAnchorPoint);
       
      //ChildrenContainer* aChildrenMap = aFather->mProperties.getPointer<ChildrenContainer>("ChildrenNodes");
      //if(aChildrenMap->find(aName) != aChildrenMap->end())
      //{
         //theEntity->destroy();
      //}
      //else
      //{
         Position2D aLocalPosition = theEntity->mProperties.get<Position2D>("LocalPosition");
         b2Body* aFatherBody = aFather->mProperties.get<b2Body*>("Body");
         b2Vec2 aFatherPos = aFatherBody->GetPosition();
         theEntity->mProperties.set<Position2D>("Position",Position2D(aFatherPos.x,aFatherPos.y,0) + aLocalPosition);
         setBody(theEntity);

         //aChildrenMap->insert(std::pair<EntityID, GQE::IEntity*>( aName, theEntity ));
         GQE::Uint32 anOrder = aFather->getOrder();
         theEntity->setOrder(anOrder++); //Don't touch otherwise CRASH!!


         b2Body* aBody = theEntity->mProperties.get<b2Body*>("Body");
         //aBody->SetTransform(aFatherBody->GetPosition() + b2Vec2(aLocalPosition.x, aLocalPosition.y), aFatherBody->GetAngle() + aLocalPosition.angle);

         b2JointDef*  aJointDef = theEntity->mProperties.get<b2JointDef*>("JointDef");

         if(aJointDef)
         {
            aJointDef->bodyB = aFatherBody;
            aJointDef->bodyA = aBody;
            b2Joint* aJoint = mWorld.CreateJoint(aJointDef);
            theEntity->mProperties.set<b2Joint*>("Joint", aJoint);
         }
      //}
   }
   
   else
   {
      setBody(theEntity);
   }

         b2Body* aBody = theEntity->mProperties.get<b2Body*>("Body");
         aBody->SetActive(true);
}

void PhysicSystem::handleCleanup(GQE::IEntity* theEntity)
{
   mWorld.DestroyBody(theEntity->mProperties.get<b2Body*>("Body"));
   //GQE::IEntity* aParentEntity = theEntity->mProperties.get<GQE::IEntity*>("FatherNode");

   //if(aParentEntity)
   //{
      //ChildrenContainer* aChildrenMap = aParentEntity->mProperties.getPointer<ChildrenContainer>("ChildrenNodes");
      //EntityID aChildName = theEntity->mProperties.get<EntityID>("Name");
      //aChildrenMap->erase(aChildrenMap->find(aChildName));
   //}

   //ChildrenContainer* aChildrenMap = theEntity->mProperties.getPointer<ChildrenContainer>("ChildrenNodes");

   //for(auto aChild : *aChildrenMap)
   //{
      //GQE::IEntity* anEntity = aChild.second;
      //bool independent = anEntity->mProperties.get<bool>("Independent");

      //if(!independent)
      //{
         //anEntity->destroy();
      //}
      //else
      //{
         //anEntity->mProperties.set<GQE::IEntity*>("FatherNode",0);
         //anEntity->setOrder(0);
      //}
   //}
}

void PhysicSystem::handleEvents(sf::Event theEvent)
{}
void PhysicSystem::draw(void)
{}

void PhysicSystem::setBody(GQE::IEntity* theEntity)
{

   b2BodyDef* anBodyDef = theEntity->mProperties.get<b2BodyDef*>("BodyDef");
   std::vector<b2FixtureDef>* anFixturesDef = theEntity->mProperties.get<std::vector<b2FixtureDef>*>("FixturesDef");

   Position2D anPosition = theEntity->mProperties.get<Position2D>("Position");
   Position2D anImpulse = theEntity->mProperties.get<Position2D>("InitialImpulse");

   anBodyDef->position.Set(anPosition.x, anPosition.y);
   anBodyDef->angle = anPosition.angle;

   b2Body* anBody = mWorld.CreateBody(anBodyDef);
   anBody->SetUserData(theEntity);

   if(anImpulse.x + anImpulse.y + anImpulse.angle != 0)
   {
      anBody->ApplyLinearImpulse(b2Vec2(anImpulse.x, anImpulse.y), anBody->GetPosition());
   }

   for(auto anFixtureDef : *anFixturesDef)
   {
      anBody->CreateFixture(&anFixtureDef);
   }

   theEntity->mProperties.set<b2Body*>("Body", anBody);
}


void PhysicSystem::attachNodes(GQE::IEntity* theFather,
                               GQE::IEntity* theChild,
                               GQE::typePropertyID theAnchorPoint,
                               GQE::typePropertyID theNodeName)
{}


void PhysicSystem::deattachNode(GQE::IEntity*)
{}
