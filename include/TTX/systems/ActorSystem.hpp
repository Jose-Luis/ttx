#ifndef  ACTORSYSTEM_INC
#define  ACTORSYSTEM_INC

#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <TTX/Types.hpp>
#include <TTX/systems/ISystem.hpp>
#include <TTX/classes/objects/IPropeller.hpp>
#include <TTX/classes/objects/WeaponManager.hpp>

class ActorSystem: public ISystem
{
public:

   ActorSystem (IActionState& theState);
   virtual ~ActorSystem();

   void addProperties(GQE::IEntity* theEntity);

   void handleEvents(sf::Event theEvent);

   void updateFixed(void);

   void updateVariable(float theElapsedTime);

   void draw(void);

protected:

   virtual void handleInit(GQE::IEntity* theEntity);

   virtual void handleCleanup(GQE::IEntity* theEntity);
};

#endif
