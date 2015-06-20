#include <TTX/systems/ActorSystem.hpp>

ActorSystem::ActorSystem(IActionState& theState):
   ISystem(ACTOR_SYSTEM, theState)
{}

ActorSystem::~ActorSystem()
{}

void ActorSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<GQE::IEntity*>(PLAYER, 0);
   theEntity->mProperties.add<Position2D>(POSITION,Position2D(0,0,0));
   theEntity->mProperties.add<Input>(INPUT, Input());
}

void ActorSystem::handleEvents(sf::Event theEvent)
{}

void ActorSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   std::vector<sf::Vector2f> anPositions;
   sf::Vector2f anCenterPosition;

   anIter = mEntities.begin();

   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

      while(anQueue != anIter->second.end())
      {
         GQE::IEntity* anEntity = *anQueue;

         Input* input = anEntity->mProperties.getPointer<Input>(INPUT);
         input->publish();
      }

      anQueue++;
   }

   anIter++;
}

void ActorSystem::draw(void)
{}

void ActorSystem::updateVariable(float theElapsedTime)
{}

void ActorSystem::handleInit(GQE::IEntity* theEntity)
{}

void ActorSystem::handleCleanup(GQE::IEntity* theEntity)
{
   GQE::IEntity* aPlayer = theEntity->mProperties.get<GQE::IEntity*>(PLAYER);
   if(aPlayer)
      aPlayer->mProperties.set<GQE::IEntity*>(ACTOR,0);
}
