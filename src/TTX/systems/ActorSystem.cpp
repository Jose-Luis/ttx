// =====================================================================================
//
//       Filename:  ActorSystem.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  30/10/12 00:26:44
//       Revision:  none
//       Compiler:  g++
//
//         Author:  YOUR NAME (),
//        Company:
//
// =====================================================================================

#include <TTX/systems/ActorSystem.hpp>

ActorSystem::ActorSystem(IActionState& theState):
   ISystem("ActorSystem", theState)
{}
ActorSystem::~ActorSystem()
{}
void ActorSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<GQE::IEntity*>("Player", 0);
   theEntity->mProperties.add<MoveData>("MoveData", MoveData());
   theEntity->mProperties.add<FireData>("FireData", FireData());
}

void ActorSystem::handleEvents(sf::Event theEvent)
{}

void ActorSystem::updateFixed()
{
   //std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   //std::vector<sf::Vector2f> anPositions;
   //sf::Vector2f anCenterPosition;

   //anIter = mEntities.begin();

   //while(anIter != mEntities.end())
   //{
      //std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

      //while(anQueue != anIter->second.end())
      //{
         //GQE::IEntity* anEntity = *anQueue;

         //anQueue++;
      //}

      //anIter++;
   //}
}

void ActorSystem::draw(void)
{}
void ActorSystem::updateVariable(float theElapsedTime)
{}
void ActorSystem::handleInit(GQE::IEntity* theEntity)
{}
void ActorSystem::handleCleanup(GQE::IEntity* theEntity)
{
   GQE::IEntity* aPlayer = theEntity->mProperties.get<GQE::IEntity*>("Player");
   if(aPlayer)
      aPlayer->mProperties.set<GQE::IEntity*>("Actor",0);
}
