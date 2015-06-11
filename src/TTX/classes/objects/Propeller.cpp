#include <TTX/classes/objects/Propeller.hpp>
#include<iostream>
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  constructor
// Description:
//------------------------------------------------------------------------------
Propeller::Propeller(Particles& theSystem):
   mOn(true),
   mLinearPower(1),
   mTurnPower(1),
   mParticles(theSystem)
{
   mFocus = mParticles.createFocus("ShipPropeller");
   mParticles.addFocus(mFocus);
}

Propeller::~Propeller()
{
   if(mFocus)
   mFocus->kill();
}

Propeller* Propeller::clone()
{
   Propeller* newPropeller = new Propeller(*this);
   auto focus = mParticles.createFocus("ShipPropeller");
   newPropeller->setFocus(focus);   
   mParticles.addFocus(focus);
   return newPropeller;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  setTurnPower
// Description:
//------------------------------------------------------------------------------
void Propeller::setTurnPower(float theTurnPower)
{
   mTurnPower = theTurnPower;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  setLinearPower
// Description:
//------------------------------------------------------------------------------
void Propeller::setLinearPower(float theLinearPower)
{
   mLinearPower = theLinearPower;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  setFocus
// Description:  A stupid method
//------------------------------------------------------------------------------
void Propeller::setFocus(mpe::FocusPtr theFocus)
{
   mFocus = theFocus;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  setEmitterID
// Description:  setter
//------------------------------------------------------------------------------
void Propeller::setEmitterID(mpe::EmitterID theEmitterID)
{
   mEmitterID = theEmitterID;
}
////------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  getEmitterID
// Description:  getter
//------------------------------------------------------------------------------
mpe::EmitterID Propeller::getEmitterID()
{
   return mEmitterID;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  switchOff
// Description:  switch off the propeller
//------------------------------------------------------------------------------
void Propeller::switchOff()
{
   mOn = false;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  switchOn
// Description:  switch on the propeller
//------------------------------------------------------------------------------
void Propeller::switchOn()
{
   mOn = true;
}
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  impulse
// Description:  impluse the body
//------------------------------------------------------------------------------
void Propeller::impulse(b2Body* theBody,MoveData theMoveData)
{
   b2Vec2 anDirection(theMoveData.x, theMoveData.y);

   if(mOn && theBody)
   {
      float anPower = anDirection.LengthSquared();

      if(anPower)
      {
         if(theMoveData.move)
         {
            theBody->ApplyForceToCenter(mLinearPower * anDirection);
         }

         if(theMoveData.turn)
         {
            theBody->SetFixedRotation(false);
            theBody->ApplyTorque(theBody->GetLocalVector(anDirection).x * mTurnPower);
         }
         else
         {
            theBody->SetFixedRotation(true);

         }

         b2Vec2 anPosition = theBody->GetWorldCenter();
         mFocus->setPosition(mpe::Vec2(anPosition.x, anPosition.y));
         float  anAngle = theBody->GetAngle() * TODEG;
         mFocus->setAngle(anAngle);
      }

      mFocus->setPPS(anPower * 32);
   }
}
