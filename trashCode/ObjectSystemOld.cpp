// =====================================================================================
//
//       Filename:  ObjectSystem.cpp
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

#include <TTX/systems/ObjectSystem.hpp>

ObjectSystem::ObjectSystem(GQE::IApp& theApp):
   ISystem("ObjectSystem", theApp),
   mWorld(b2Vec2(0.0f, -10.0f))
{
   mTimeStep = theApp.getUpdateRate();
   mVelocityIterations = 6;
   mPositionIterations = 2;
}

ObjectSystem::ObjectSystem(GQE::IApp& theApp, b2World theWorld):
   ISystem("ObjectSystem", theApp),
   mWorld(theWorld)
{
   mTimeStep = theApp.getUpdateRate();
   mVelocityIterations = 6;
   mPositionIterations = 2;
}

ObjectSystem::~ObjectSystem()
{}

void ObjectSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<b2Body*>("b2Body", 0);
}

void ObjectSystem::updateFixed()
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

         // Increment the IEntity iterator second
         anQueue++;

         b2Body* anBody = anEntity->mProperties.get<b2Body*>("b2Body");

         sf::Vector2f anPosition(anBody->GetPosition().x, -(anBody->GetPosition().y));
         float anRotation(-(anBody->GetAngle() * (180 / b2_pi)));

         anEntity->mProperties.set<sf::Vector2f>("vPosition", anPosition);
         anEntity->mProperties.set<float>("fRotation", anRotation);
         std::cout << anPosition.x;
         std::cout << anPosition.y;
      }  // while(anQueue != anIter->second.end())

      // Increment map iterator
      anIter++;
   }
}

void ObjectSystem::updateVariable(float theElapsedTime)
{}

void ObjectSystem::handleInit(GQE::IEntity* theEntity)
{
   b2BodyDef* anBodyDef = theEntity->mProperties.get<b2BodyDef*>("b2BodyDef");;
   std::vector<b2FixtureDef>& anFixturesDef = theEntity->mProperties.get<std::vector<b2FixtureDef>&>("b2FixturesDef");;

   b2Body* anBody = mWorld.CreateBody(anBodyDef);
   std::vector<b2FixtureDef>::iterator anIter;

   anBody->SetUserData(&(theEntity->getID()));

   for(anIter = anFixturesDef.begin(); anIter != anFixturesDef.end(); anIter++)
   {
      anBody->CreateFixture(*anIter);
   }

   theEntity->mProperties.set<b2Body*>("b2Body", anBody);
}

void ObjectSystem::handleCleanup(GQE::IEntity* theEntity)
{}

void ObjectSystem::handleEvents(sf::Event theEvent)
{}
void ObjectSystem::draw(void)
{}


