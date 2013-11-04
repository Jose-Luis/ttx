#include <TTX/systems/PropellerSystem.hpp>
/**
 * @file PropellerSystem.cpp
 * @brief PropellerSystem class
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-25
 */
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  constructor
// Description:   
//------------------------------------------------------------------------------
PropellerSystem::PropellerSystem(IActionState& theState, Particles& theParticles):
   ISystem("PropellerSystem",theState),
   mParticles(theParticles)
{
  
   std::shared_ptr<DisolveAffector> anAffector;
   anAffector = DisolveAffector::create(32);
   mParticles.addAffector(anAffector); 
}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  deconstructor
// Description:   
//------------------------------------------------------------------------------
PropellerSystem::~PropellerSystem()
{}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  addProperties
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<b2Vec2>("vMoveDirection",b2Vec2(0,0));
}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  handleInit
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::handleInit(GQE::IEntity* theEntity)
{
   Propeller* anPropeller = theEntity->mProperties.getPointer<Propeller>("pPropeller");
   b2Body* anBody = theEntity->mProperties.get<b2Body*>("b2Body");
   anPropeller->setBody(anBody);
   std::shared_ptr<mpe::Focus> anFocus;
   anFocus = mParticles.createFocus(anPropeller->getEmitterID()); 
   mParticles.addFocus(anFocus);
   anPropeller->setFocus(anFocus);

}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  handleEvents
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::handleEvents(sf::Event theEvent)
{
}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  updateFixed
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();
   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();
      while(anQueue != anIter->second.end())
      {
         // get the IEntity address first
         GQE::IEntity* anEntity = *anQueue;

         // Increment the IEntity iterator second
         anQueue++;

         b2Vec2 anDirection = anEntity->mProperties.get<b2Vec2>("vMoveDirection");
            Propeller* anPropeller = anEntity->mProperties.getPointer<Propeller>("pPropeller");
            anPropeller->impulse(anDirection);
      }  
      anIter++;
   }
}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  updateVariable
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::updateVariable(float theElapsedTime)
{
}
//------------------------------------------------------------------------------
//       Class:  PropellerSystem
//      Method:  draw
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::draw()
{
}
//------------------------------------------------------------------------------
//       Class:  handleCleanup
//      Method:  MethodName
// Description:   
//------------------------------------------------------------------------------
void PropellerSystem::handleCleanup(GQE::IEntity* theEntity)
{
  delete (theEntity->mProperties.get<Propeller*>("pPropeller"));
}
/* Copyright (C) 
 * 2013 - Jose Luis Lavado
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

