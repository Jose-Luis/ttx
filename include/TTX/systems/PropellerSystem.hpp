
/**
 * Provides the PropellerSystem class for handing all IEntity rendering in a game.
 *
 * @file src/GQE/Entity/systems/PropellerSystem.cpp
 * @author Jacob Dix
 * @date 20120611 - Initial Release
 * @date 20120616 - Adjustments for new PropertyManager class
 * @date 20120618 - Use IEntity not Instance and changed AddPrototype to AddProperties
 * @date 20120622 - Changed HandleInit and HandleCleanup
 * @date 20120623 - Improved documentation and adjusted some properties
 */
#include <GQE/Entity/interfaces/ISystem.hpp>
#include <GQE/Core/utils/CRC32.hpp>
#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>
#include <TTX/classes/objects/Propeller.hpp>
#include <TTX/classes/particles/Particles.hpp>
#include <TTX/classes/particles/Affectors.hpp>
#include <TTX/systems/ISystem.hpp>
#include <MPE/MPE.hpp>
#include <GT/GT.hpp>

#ifndef PROPELLERSYSTEM_INC
#define PROPELLERSYSTEM_INC

/// The PropellerSystem for managing all Instance rendering in a game
class PropellerSystem : public ISystem
{
public:
   /**
    * PropellerSystem Constructor.
    * @param[in] theApp is the current GQE app.
    */
   PropellerSystem(IActionState& theState, Particles& theParticles);
   /**
    * ISystem Destructor.
    */
   virtual ~PropellerSystem();

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
   Particles& mParticles;

}; // class PropellerSystem

#endif // RENDER_SYSTEM_HPP_INCLUDED

/**
 * @class GQE::PropellerSystem
 * @ingroup Entity
 * The PropellerSystem class is used to render each IEntity as a Propeller and
 * provides the following properties (which are used in other ISystem classes):
 * - bVisible: A boolean indicating this IEntity is currently visible
 * - fRotation: The float representing the current IEntity rotation
 * - rPropellerRect: The sf::IntRect to use on the Image provided
 * - vOrigin: The sf::Vector2f representing the origin for all transformations
 * - vPosition: The sf::Vector2f representing the current IEntity position
 * - vScale: The sf::Vector2f representing the scale to apply to the Image (defaults to 1.0,1.0)
 * - Propeller: The sf::Propeller that represents this IEntity
 * The PropellerSystem can be combined with the MovementSystem to cause each
 * IEntity to be moved around in the game.
 *
 * Copyright (c) 2010-2012 Jacob Dix
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
