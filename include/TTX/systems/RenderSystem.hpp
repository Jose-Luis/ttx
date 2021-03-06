/// @file RenderSystem.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <SFML/Graphics.hpp>
#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>
#include <GQE/Core/utils/CRC32.hpp>
#include <GQE/Entity/interfaces/IEntity.hpp>
#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <TTX/systems/ISystem.hpp>
#include <TTX/classes/render/RenderManager.hpp>

#ifndef RenderSYSTEM_INC
#define RenderSYSTEM_INC


/// The RenderSystem for managing all Instance rendering in a game
class RenderSystem : public ISystem
{
public:
   /**
    * RenderSystem Constructor.
    * @param[in] theApp is the current GQE app.
    */
   RenderSystem(IActionState& theState, RenderManager& theRenderManager, float theFactor);

   /**
    * ISystem Destructor.
    */
   virtual ~RenderSystem();

   /**
    * AddProperties is responsible for adding the properties used by this
    * ISystem derived class to the IEntity derived class provided.
    * @param[in] theEntity to add the properties to.
    */
   virtual void addProperties(GQE::IEntity* theEntity);

   /**
    * HandleEvents is responsible for letting each Instance class have a
    * chance to handle theEvent specified.
    * @param[in] theEvent to handle
    */
   virtual void handleEvents(sf::Event theEvent);

   /**
    * UpdateFixed is called a specific number of times every game loop and
    * this method will allow each Instance class a chance to have its
    * UpdateFixed method called for each game loop iteration.
    */
   virtual void updateFixed(void);

   /**
    * UpdateVariable is called every time the game loop draws a frame and
    * includes the elapsed time between the last UpdateVariable call for
    * use with equations that use time as a variable. (e.g. physics velocity
    * and acceleration equations).
    */
   virtual void updateVariable(float theElapsedTime);

   /**
    * Draw is called during the game loop after events and the fixed update
    * loop calls are completed and depends largely on the speed of the
    * computer to determine how frequently it will be called. This gives the
    * EntityManager a chance to call the Draw method for each Instance
    * class.
    */
   virtual void draw(void);

protected:
   /**
    * HandleInit is called to allow each derived ISystem to perform any
    * initialization steps when a new IEntity is added.
    */
   virtual void handleInit(GQE::IEntity* theEntity);

   /**
    * HandleCleanup is called when the IEntity that was added is finally
    * dropped from this ISystem and gives the derived ISystem class a chance
    * to perform any custom work before the IEntity is deleted.
    */
   virtual void handleCleanup(GQE::IEntity* theEntity);

private:
   RenderManager& mRenderManager;
   float mFactor;
   static sf::IntRect mDummyRect;

};

#endif
