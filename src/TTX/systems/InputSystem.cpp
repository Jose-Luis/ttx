#include <TTX/systems/InputSystem.hpp>

InputSystem::InputSystem(IActionState& theState):
   ISystem(INPUT_SYSTEM,theState)
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::addProperties(GQE::IEntity* theEntity)
{
}

void InputSystem::draw(void)
{
}

void InputSystem::handleCleanup(GQE::IEntity* theEntity)
{
}

void InputSystem::handleEvents(sf::Event theEvent)
{
}

void InputSystem::handleInit(GQE::IEntity* theEntity)
{
}

void InputSystem::updateFixed(void)
{
}

void InputSystem::updateVariable(float theElapsedTime)
{
}

