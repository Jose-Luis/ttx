/// @file AttachSystem.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/AttachSystem.hpp>

AttachSystem::AttachSystem(IActionState& theState, b2World& theWorld):
   ISystem("AttachSystem", theState),
   mWorld(theWorld)
{}

AttachSystem::~AttachSystem()
{}

void AttachSystem::addProperties(GQE::IEntity* theEntity)
{

   theEntity->mProperties.add<GQE::IEntity*>("Parent", nullptr);
   theEntity->mProperties.add<Transform>("LocalTransform", Transform(0, 0, 0));
   theEntity->mProperties.add<Transform>("Transform", Transform(0, 0, 0));
   theEntity->mProperties.add<b2JointDef*>("JointDef", 0);
   theEntity->mProperties.add<b2Joint*>("Joint", 0);
   theEntity->mProperties.add<bool>("DirtyTransformBit", false);
}

void AttachSystem::handleInit(GQE::IEntity* theEntity)
{
   GQE::IEntity* anParentEntity = theEntity->mProperties.get<GQE::IEntity*>("Parent");
   theEntity->mProperties.set<bool>("DirtyTransformBit", true);

   if(1 < anParentEntity->getOrder())
   {
      Transform anLocalTransform = theEntity->mProperties.get<Transform>("LocalTransform");
      anLocalTransform = anLocalTransform + anParentEntity->mProperties.get<Transform>("Transform");
      theEntity->mProperties.set<Transform>("Transform", anLocalTransform);

      b2Body* anParentBody = anParentEntity->mProperties.get<b2Body*>("b2Body");
      b2Body* anBody = theEntity->mProperties.get<b2Body*>("b2Body");
      anBody->SetTransform(anParentBody->GetPosition() + b2Vec2(anLocalTransform.x, anLocalTransform.y), anParentBody->GetAngle() + anLocalTransform.angle);

      b2JointDef* aJointDef = theEntity->mProperties.get<b2JointDef*>("JointDef");

      aJointDef->bodyA = anParentBody;
      aJointDef->bodyB = anBody;
      b2Joint* aJoint = mWorld.CreateJoint(aJointDef);
      theEntity->mProperties.set<b2Joint*>("Joint", aJoint);

   }

}
void AttachSystem::handleEvents(sf::Event theEvent)
{}

void AttachSystem::updateFixed()
{
   //std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   //anIter = mEntities.begin();

   //while(anIter != mEntities.end())
   //{
   //std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

   //while(anQueue != anIter->second.end())
   //{

   //GQE::IEntity* anEntity = *anQueue;
   //GQE::IEntity* anParentEntity = anEntity->mProperties.get<GQE::IEntity*>("Parent");
   //bool needUpdate = anEntity->mProperties.get<bool>("DirtyTransformBit");

   //if(anParentEntity && needUpdate)
   //{
   //Transform anLocalTransform = anEntity->mProperties.get<Transform>("LocalTransform");
   //anLocalTransform = anLocalTransform + anParentEntity->mProperties.get<Transform>("Transform");
   //anEntity->mProperties.set<Transform>("Transform", anLocalTransform);
   //}

   //anQueue++;
   //}

   //anIter++;
   //}
}

void AttachSystem::updateVariable(float theElapsedTime)
{}

void AttachSystem::draw()
{
}

void AttachSystem::handleCleanup(GQE::IEntity* theEntity)
{} 

