#include <TTX/systems/WeaponSystem.hpp>

WeaponSystem::WeaponSystem(IActionState& theState):
   ISystem("WeaponSystem", theState)
{}

WeaponSystem::~WeaponSystem()
{}

void WeaponSystem::addProperties(GQE::IEntity* theEntity)
{}

void WeaponSystem::handleInit(GQE::IEntity* theEntity)
{}

void WeaponSystem::handleEvents(sf::Event theEvent)
{}

void WeaponSystem::updateFixed()
{}

void WeaponSystem::updateVariable(float theElapsedTime)
{}

void WeaponSystem::draw()
{}

void WeaponSystem::handleCleanup(GQE::IEntity* theEntity)
{
   //Weapon* mg = theEntity->mProperties.getPointer<Weapon>("Weapon");
   //if(mg)
   //{
      //WeaponManager* wm = mg->getManager();
      //if(wm)
      //{
         //wm->removeWeapon(theEntity);
      //}
   //}
}

/**
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
