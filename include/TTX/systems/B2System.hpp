// =====================================================================================
//
//       Filename:  B2System.hpp
//
//    Description:
//
//        Version:  1.0
//        Created:  15/10/12 11:50:56
//       Revision:  none
//       Compiler:  g++
//
//         Author:  YOUR NAME (),
//        Company:
//
// =====================================================================================

#ifndef  B2SYSTEM_INC
#define  B2SYSTEM_INC

#include <cstdio>
#include <iostream>
#include <vector>
#include <Box2D/Box2D.h>
#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Entity/Entity_types.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <TTX/prototypes/components/B2Proto.hpp>
#include <TTX/Types.hpp>
#include <TTX/systems/ISystem.hpp>

class B2System: public ISystem
{
public:

   B2System (IActionState& theState);                         // constructor
   B2System (IActionState& theState, b2World& theWorld);           // constructor

   virtual ~B2System ();

   /**
    * RegisterPrototype is responsible for adding the properties to a prototype.
    * @param[in] thePrototype is the prototype to use.
    */
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
   b2World& mWorld;
   float mTimeStep;
   int32 mVelocityIterations;
   int32 mPositionIterations;
};
#endif //  ----- #ifndef B2SYSTEM_INC  -----
