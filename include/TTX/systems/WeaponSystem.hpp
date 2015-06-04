
// =====================================================================================
//        Class:  WeaponSystem
//  Description:
// =====================================================================================
#ifndef  HEALTHSYSTEM_INC
#define  HEALTHSYSTEM_INC

#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <TTX/Types.hpp>
#include <TTX/systems/ISystem.hpp>

class WeaponSystem: public ISystem
{
public:

   WeaponSystem (IActionState& theState);                      // constructor
   ~WeaponSystem();

   void addProperties(GQE::IEntity* theEntity);

   /**
    * HandleEvents is responsible for letting each Instance class have a
    * chance to handle theEvent specified.
    * @param[in] theEvent to handle
    */
   void handleEvents(sf::Event theEvent);

   /**
    * UpdateFixed is called a specific number of times every game loop and
    * this method will allow each Instance class a chance to have its
    * UpdateFixed method called for each game loop iteration.
    */
   void updateFixed(void);

   /**
    * UpdateVariable is called every time the game loop draws a frame and
    * includes the elapsed time between the last UpdateVariable call for
    * use with equations that use time as a variable. (e.g. physics velocity
    * and acceleration equations).
    */
   void updateVariable(float theElapsedTime);

   /**
    * Draw is called during the game loop after events and the fixed update
    * loop calls are completed and depends largely on the speed of the
    * computer to determine how frequently it will be called. This gives the
    * EntityManager a chance to call the Draw method for each Instance
    * class.
    */
   void draw(void);

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


}; // -----  end of class WeaponSystem  -----

#endif   // ----- #ifndef CONTROLLERSYSTEM_INC  -----
