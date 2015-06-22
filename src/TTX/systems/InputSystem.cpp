#include <TTX/systems/InputSystem.hpp>

InputSystem::InputSystem(IActionState& theState):
   ISystem(INPUT_SYSTEM,theState)
{}

InputSystem::~InputSystem()
{}

void InputSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<Input*>(INPUT,0);
   theEntity->mProperties.add<EntityInputListener*>(INPUT_LISTENER,0);
}

void InputSystem::draw(void)
{}

void InputSystem::handleCleanup(GQE::IEntity* theEntity)
{

   theEntity->mProperties.get<EntityInputListener*>(INPUT_LISTENER)->drop();
}

void InputSystem::handleEvents(sf::Event theEvent)
{}

void InputSystem::handleInit(GQE::IEntity* theEntity)
{
   Entity* root = theEntity->mProperties.get<Entity*>(ROOT);
   Input* input = root->mProperties.get<Input*>(INPUT);
   if(input)
   {
      auto listener = theEntity->mProperties.get<EntityInputListener*>(INPUT_LISTENER)->clone();

      if(listener)
      {
         listener->setEntity(theEntity);
         listener->setState(&mState);
         input->addListener(listener);
         theEntity->mProperties.set<EntityInputListener*>(INPUT_LISTENER,listener);
      }
   }
}

void InputSystem::updateFixed(void)
{}

void InputSystem::updateVariable(float theElapsedTime)
{}

