// =====================================================================================
//
//       Filename:  B2ObjectSystem.cpp
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
#include <GQE/Entity/classes/Instance.hpp>
#include <TTX/systems/B2ObjectSystem.hpp>
#include <vector>


B2ObjectSystem::B2ObjectSystem(GQE::IApp& theApp):
   ISystem("B2ObjectSystem", theApp)
{}

B2ObjectSystem::~B2ObjectSystem()
{}

void B2ObjectSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<b2Body*>("b2Body", NULL);
   theEntity->mProperties.add<std::vector<b2Fixture*> >("b2Fixtures", NULL);
   theEntity->
}

void B2ObjectSystem::updateFixed()
{}

void B2ObjectSystem::updateVariable(float theElapsedTime)
{}

void B2ObjectSystem::handleInit(GQE::IEntity* theEntity)
{}

void B2ObjectSystem::handleCleanup(GQE::IEntity* theEntity)
{}

void B2ObjectSystem::handleEvents(sf::Event theEvent)
{}

void B2ObjectSystem::draw(void)
{}


