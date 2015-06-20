/// @file EntityListenerSystem.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/EntityListenerSystem.hpp>

EntityListenerSystem::EntityListenerSystem(IActionState& theState):
   ISystem(ENTITY_LISTENER_SYSTEM, theState)
{}

EntityListenerSystem::~EntityListenerSystem()
{}

void EntityListenerSystem::addProperties(GQE::IEntity* theEntity)
{}

void EntityListenerSystem::handleInit(GQE::IEntity* theEntity)
{
   auto entityListener = theEntity->mProperties.getPointer<EntityInputListener>(INPUT_LISTENER);
   entityListener->setEntity(theEntity);
   entityListener->setState(&mState);
}

void EntityListenerSystem::handleEvents(sf::Event theEvent)
{}

void EntityListenerSystem::updateFixed()
{}

void EntityListenerSystem::updateVariable(float theElapsedTime)
{}

void EntityListenerSystem::draw()
{}

void EntityListenerSystem::handleCleanup(GQE::IEntity* theEntity)
{

   auto entityListener = theEntity->mProperties.getPointer<EntityInputListener>(INPUT_LISTENER);
   if(entityListener)
      entityListener->drop();
}
