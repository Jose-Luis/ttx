/// @file InputSystem.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/Definition.hpp>
#include <TTX/Types.hpp>
#include <GQE/Entity/interfaces/IEntity.hpp>
#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <TTX/systems/ISystem.hpp>

#ifndef INPUTSYSTEM_INC
#define INPUTSYSTEM_INC


/// The InputSystem for managing all father-child relations between entities  in a game

class InputSystem : public ISystem
{
public:
   /**
    * InputSystem Constructor.
    * @param[in] theApp is the current GQE app.
    */
   InputSystem(IActionState& theState);

   /**
    * ISystem Destructor.
    */
   virtual ~InputSystem();

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

};

#endif
