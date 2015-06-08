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

#include <vector>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <GQE/Core/assets/FontAsset.hpp>
#include <GQE/Core/assets/ImageAsset.hpp>
#include <GQE/Core/assets/SoundAsset.hpp>
#include <GQE/Core/Core_types.hpp>
#include <GQE/Core/interfaces/IApp.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <Box2D/Box2D.h>

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>
#include <TTX/systems/PhysicSystem.hpp>
#include <TTX/systems/PropellerSystem.hpp>
#include <TTX/systems/PlayerSystem.hpp>
#include <TTX/systems/RenderSystem.hpp>
#include <TTX/systems/AnimationSystem.hpp>
#include <TTX/systems/HealthSystem.hpp>
#include <TTX/prototypes/Rombo.hpp>
#include <TTX/prototypes/Box.hpp>
#include <TTX/prototypes/Ground.hpp>
#include <TTX/prototypes/BasicShip.hpp>
#include <TTX/prototypes/Player.hpp>
#include <TTX/prototypes/SimpleBullet.hpp>
#include <TTX/prototypes/Machinegun.hpp>
#include <TTX/classes/mapLoader/MapLoader.hpp>

/// Provides the TicTacToe GameStateOne example
class GameStateOne : public IActionState
{
public:
   /**
    * GameStateOne constructor
    * @param[in] theApp is a pointer to the App class.
    */
   GameStateOne(GQE::IApp& theApp);

   /**
    * GameStateOne deconstructor
    */
   virtual ~GameStateOne(void);

   /**
    * DoInit is responsible for initializing this State
    */
   virtual void doInit(void);

   /**
    * ReInit is responsible for Reseting this state when the
    * StateManager::resetActiveState() method is called.  This way a Game
    * State can be restarted without unloading and reloading the game assets
    */
   virtual void reInit(void);

   /**
    * HandleEvents is responsible for handling input events for this
    * State when it is the active State.
    * @param[in] theEvent to process from the App class Loop method
    */
   virtual void handleEvents(sf::Event theEvent);

   /**
    * UpdateSelected is responsible for clearing the previously selected
    * edge and changing the image of the newly selected edge.
    * @param[in] theEvent that specifies the new mouse position
    */
   void updateSelected(sf::Event theEvent);

   /**
    * UpdateFixed is responsible for handling all State fixed update needs for
    * this State when it is the active State.
    */
   virtual void updateFixed(void);

   /**
    * UpdateVariable is responsible for handling all State variable update
    * needs for this State when it is the active State.
    * @param[in] theElapsedTime since the last Draw was called */
   virtual void updateVariable(float theElapsedTime);

   /**
    * Draw is responsible for handling all Drawing needs for this State
    * when it is the Active State.
    */
   virtual void draw(void);

protected:
   /**
    * HandleCleanup is responsible for performing any cleanup required before
    * this State is removed.
    */
   virtual void handleCleanup(void);

private:

   sf::View mView;
   b2ContactListener* mCollisionListener;

   GQE::IEntity* mPlayer;


   /*#ifndef  NDEBUG
      sf::Clock mFpsClock;
      float mAcum;
      int mCont;
      sf::Text mFpsText;
   #endif */
};

#endif // GAME_STATE_HPP_INCLUDED

/**
 * @class GameStateOne
 * @ingroup Examples
 **/
