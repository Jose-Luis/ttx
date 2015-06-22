/// @file NodeSystem.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/NodeSystem.hpp>

NodeSystem::NodeSystem(IActionState& theState):
   ISystem(NODE_SYSTEM, theState)
{}

NodeSystem::~NodeSystem()
{}

void NodeSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<Entity*>(PARENT,0);
   theEntity->mProperties.add<Entity*>(ROOT,0);
   theEntity->mProperties.add<ChildrenContainer>(CHILDREN,ChildrenContainer());
}

void NodeSystem::handleInit(GQE::IEntity* theEntity)
{
   GQE::IEntity* parent = theEntity->mProperties.get<Entity*>(PARENT);
   Entity* root = theEntity;

   if(parent)
   {
      root = parent->mProperties.get<Entity*>(ROOT);
      theEntity->mProperties.set<Entity*>(ROOT,root);
      ChildrenContainer* children = parent->mProperties.getPointer<ChildrenContainer>(CHILDREN);
      children->push_front(theEntity);
      GQE::Uint32 order = parent->getOrder();
      theEntity->setOrder(order++); //Don't touch otherwise CRASH!!
   }

   theEntity->mProperties.set<Entity*>(ROOT,root);
}

void NodeSystem::handleEvents(sf::Event theEvent)
{}

void NodeSystem::updateFixed()
{}

void NodeSystem::updateVariable(float theElapsedTime)
{}

void NodeSystem::draw()
{}

void NodeSystem::handleCleanup(GQE::IEntity* theEntity)
{
   GQE::IEntity* parent = theEntity->mProperties.get<Entity*>(PARENT);

   if(parent)
   {
      ChildrenContainer* children = parent->mProperties.getPointer<ChildrenContainer>(CHILDREN);
      children->remove(theEntity);
   }

   ChildrenContainer* children = theEntity->mProperties.getPointer<ChildrenContainer>(CHILDREN);

   for(auto child : *children)
   {
      if( child->mProperties.get<bool>(INDEPENDENT) )
      {
         child->destroy();
      }
      else
      {
         child->mProperties.set<Entity*>(PARENT, 0);
         child->mProperties.set<Entity*>(ROOT, 0);
         child->setOrder(0);
      }
   }
}
