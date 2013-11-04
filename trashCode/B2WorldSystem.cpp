// =====================================================================================
// 
//       Filename:  B2WorldSystem.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  15/10/12 18:43:09
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  YOUR NAME (), 
//        Company:  
// 
// =====================================================================================

#include <GQE/Entity/classes/Instance.hpp>
#include <GQE/Entity/interfaces/IEntity.hpp>
#include <TTX/systems/B2WorldSystem.hpp>


B2WorldSystem::B2WorldSystem(GQE::IApp& theApp):
   ISystem("B2WorldSystem",theApp)
{}

B2WorldSystem::~B2WorldSystem()
{}

void B2WorldSystem::addProperties(GQE::IEntity *theEntity)
{
   theEntity->mProperties.add<b2Vec2>("gravity",b2Vec2(0.0f,0.0f));
   theEntity->mProperties.add<bool>("doSleep",true);
   theEntity->mProperties.add<float>("timeStep",);
   theEntity->mProperties.add<int32>("velocityIternations",6);
   theEntity->mProperties.add<int32>("positionIternations",2);
   theEntity->mProperties.add<b2World>("b2World",b2World(b2Vec2(0.0f,0.0f),true);
   theEntity->
}

void B2WorldSystem::updateFixed()
{
    std::map<const Uint32, std::deque<IEntity*>>::iterator anIter;
    anIter = mEntities.begin();
    while(anIter != mEntities.end())
    {
      std::deque<IEntity*>::iterator anQueue = anIter->second.begin();
      while(anQueue != anIter->second.end())
      {
        // get the IEntity address first
        GQE::IEntity* anEntity = *anQueue;

        // Increment the IEntity iterator second
        anQueue++;

        b2World anWorld =anEntity->mProperties.get<b2World>("b2World");
        anWorld.
}


void B2WorldSystem::updateVariable(float theElapsedTime)
{}

void B2WorldSystem::handleInit(GQE::IEntity* theEntity)
{}

void B2WorldSystem::handleCleanup(GQE::IEntity* theEntity)
{}

void B2WorldSystem::handleEvents(sf::Event theEvent)
{}

void B2WorldSystem::draw(void)
{}


