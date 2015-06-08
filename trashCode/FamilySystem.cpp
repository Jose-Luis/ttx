/// @file FamilySystem.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/FamilySystem.hpp>

FamilySystem::FamilySystem(IActionState& theState):
   ISystem("FamilySystem", theState)
{}

FamilySystem::~FamilySystem()
{}

void FamilySystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<sf::IntRect>("rTexRect", sf::IntRect(0, 0, 0, 0));
}

void FamilySystem::handleInit(GQE::IEntity* theEntity)
{
   GQE::IEntity* anParentEntity = theEntity->mProperties.get<GQE::IEntity*>("Parent");

   if(anParentEntity)
   {
      ChildrenContainer* aChildrenMap = anParentEntity->mProperties.getPointer<ChildrenContainer>("Children");
      EntityID aName = theEntity->mProperties.get<EntityID>("Name");
      aChildrenMap->insert(std::pair<EntityID, GQE::IEntity*>( aName, theEntity ));
      GQE::Uint32 anOrder = anParentEntity->getOrder();
      theEntity->setOrder(anOrder++); //Don't touch otherwise CRASH!!
   }
}

void FamilySystem::handleEvents(sf::Event theEvent)
{}

void FamilySystem::updateFixed()
{}

void FamilySystem::updateVariable(float theElapsedTime)
{}

void FamilySystem::draw()
{}

void FamilySystem::handleCleanup(GQE::IEntity* theEntity)
{
   GQE::IEntity* aParentEntity = theEntity->mProperties.get<GQE::IEntity*>("Parent");

   if(aParentEntity)
   {
      ChildrenContainer* aChildrenMap = aParentEntity->mProperties.getPointer<ChildrenContainer>("Children");
      EntityID aChildName = theEntity->mProperties.get<EntityID>("Name");
      aChildrenMap->erase(aChildrenMap->find(aChildName));
   }

   ChildrenContainer* aChildrenMap = theEntity->mProperties.getPointer<ChildrenContainer>("Children");

   for(auto aChild : *aChildrenMap)
   {
      GQE::IEntity* anEntity = aChild.second;
      bool independent = anEntity->mProperties.get<bool>("Independent");

      if(!independent)
      {
         anEntity->destroy();
      }
      else
      {
         anEntity->mProperties.set<GQE::IEntity*>("Parent", 0);
         anEntity->setOrder(0);
      }
   }
}
