/**
 * Provides the SpaceDots GameStateOne example in the GQE library.
 *
 * @file src/GameStateOne.cpp
 * @author Ryan Lindeman
 * @date 20120323 - Initial Release
 * @date 20120421 - Make sure SFML 2 doesn't use its default font since it will crash on exit
 * @date 20120512 - Use new RAII Asset style
 */
#ifndef   GAME_STATE_HPP_INCLUDED
#define   GAME_STATE_HPP_INCLUDED

#include <GQE/Core/assets/FontAsset.hpp>
#include <GQE/Core/assets/ImageAsset.hpp>
#include <GQE/Core/assets/SoundAsset.hpp>
#include <GQE/Core/classes/StatManager.hpp>
#include <GQE/Core/Core_types.hpp>
#include <GQE/Core/interfaces/IApp.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <Box2D/Box2D.h>
#include <TTX/classes/physics/CollisionListener.hpp>

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>
#include <TTX/systems/PhysicSystem.hpp>
#include <TTX/systems/PropellerSystem.hpp>
#include <TTX/systems/PlayerSystem.hpp>
#include <TTX/systems/RenderSystem.hpp>
#include <TTX/systems/AnimationSystem.hpp>
#include <TTX/systems/HealthSystem.hpp>
#include <TTX/systems/ActorSystem.hpp>
#include <TTX/systems/WeaponSystem.hpp>
#include <TTX/systems/NodeSystem.hpp>
#include <TTX/systems/InputSystem.hpp>
#include <TTX/prototypes/Box.hpp>
#include <TTX/prototypes/BasicShip.hpp>
#include <TTX/prototypes/Player.hpp>
#include <TTX/prototypes/SimpleBullet.hpp>
#include <TTX/prototypes/Machinegun.hpp>
#include <TTX/prototypes/ShipPropeller.hpp>
#include <TTX/classes/mapLoader/MapLoader.hpp>

class GameStateOne : public IActionState
{
public:
   GameStateOne(GQE::IApp& theApp);

   virtual ~GameStateOne(void);

   virtual void doInit(void);

   virtual void reInit(void);

   virtual void handleEvents(sf::Event theEvent);

   void updateSelected(sf::Event theEvent);

   virtual void updateFixed(void);

   virtual void updateVariable(float theElapsedTime);

   virtual void draw(void);

protected:

   virtual void handleCleanup(void);

private:

   sf::View mView;
   b2ContactListener* mCollisionListener;

   GQE::IEntity* mPlayer;
   GQE::ISystem* mRenderSystem;
   GQE::ISystem* mPlayerSystem;
   GQE::ISystem* mPropellerSystem;
   GQE::ISystem* mPhysicSystem;
   GQE::ISystem* mAnimationSystem;
   GQE::ISystem* mHealthSystem;
   GQE::ISystem* mActorSystem;
   GQE::ISystem* mWeaponSystem;
   GQE::ISystem* mNodeSystem;
   GQE::ISystem* mInputSystem;
#ifndef  NDEBUG
   GQE::StatManager mStatManager;
#endif
};

#endif // GAME_STATE_HPP_INCLUDED

/**
 * @class GameStateOne
 * @ingroup Examples
 **/
