/// @file AnimationSystem.cpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/AnimationSystem.hpp>

AnimationSystem::AnimationSystem(IActionState& theState):
   ISystem("AnimationSystem",theState)
{}

AnimationSystem::~AnimationSystem()
{}

void AnimationSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<sf::IntRect>("rTexRect",sf::IntRect(0,0,0,0));
}

void AnimationSystem::handleInit(GQE::IEntity* theEntity)
{}

void AnimationSystem::handleEvents(sf::Event theEvent)
{}

void AnimationSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();

   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();
      while(anQueue != anIter->second.end())
      {
         GQE::IEntity* anEntity = *anQueue;

         Animation* anAnimation = anEntity->mProperties.getPointer<Animation>("rAnimation");
         sf::IntRect anTexRect = anAnimation->getFrame();
         anAnimation->update(SPU);
         anEntity->mProperties.set("rTexRect",anTexRect);

         anQueue++;
      } 
      anIter++;
   } 
}

void AnimationSystem::updateVariable(float theElapsedTime)
{}

void AnimationSystem::draw()
{
  }

void AnimationSystem::handleCleanup(GQE::IEntity* theEntity)
{}
