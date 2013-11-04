// =====================================================================================
// 
//       Filename:  B2ObjectDefSystem.cpp
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
#include <TTX/systems/B2ObjectDefSystem.hpp>
#include <vector>


B2ObjectDefSystem::B2ObjectDefSystem(GQE::IApp& theApp):
   ISystem("B2ObjectDefSystem",theApp)
{}

B2ObjectDefSystem::~B2ObjectDefSystem()
{}

void B2ObjectDefSystem::addProperties(GQE::IEntity *theEntity)
{
   theEntity->mProperties.add<b2BodyDef*>("b2BodyDef",NULL);
   theEntity->mProperties.add<std::vector<b2FixtureDef*> >("b2FixtureDef",NULL);
}

void B2ObjectDefSystem::updateFixed()
{}

void B2ObjectDefSystem::updateVariable(float theElapsedTime)
{}

void B2ObjectDefSystem::handleInit(GQE::IEntity* theEntity)
{}

void B2ObjectDefSystem::handleCleanup(GQE::IEntity* theEntity)
{}

void B2ObjectDefSystem::handleEvents(sf::Event theEvent)
{}

void B2ObjectDefSystem::draw(void)
{}
