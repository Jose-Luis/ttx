#include <TTX/classes/objects/Propeller.hpp>
#include<iostream>
//------------------------------------------------------------------------------
//       Class:  Propeller
//      Method:  constructor
// Description:   
//------------------------------------------------------------------------------
Propeller::Propeller():
   mOn(true),
   mLinearPower(1),
   mTurnPower(1),
   mInnerPosition(b2Vec2(0,0))
{}
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
//      Method:  setBody
// Description:  setter 
//------------------------------------------------------------------------------
void Propeller::setBody(b2Body* theBody)
{
   mBody = theBody;
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
//      Method:  setInnerPosition
// Description:  setter 
//------------------------------------------------------------------------------
void Propeller::setInnerPosition(b2Vec2 theInnerPosition)
{
   mInnerPosition = theInnerPosition;
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
void Propeller::impulse(MoveData theMoveData)
{
   b2Vec2 anDirection(theMoveData.x,theMoveData.y);

   if(mOn && mBody)
   {
      float anPower = anDirection.LengthSquared();
      if(anPower)
      {
         if(theMoveData.move)
         {
            mBody->ApplyForceToCenter(mLinearPower * anDirection);
         }
         if(theMoveData.turn)
         {
            mBody->ApplyTorque(mBody->GetLocalVector(anDirection).x * mTurnPower);
         }
         b2Vec2 anPosition = mBody->GetWorldCenter(); 
         mFocus->setPosition(mpe::Vec2(anPosition.x,anPosition.y));
         float  anAngle = mBody->GetAngle() * TODEG;
         mFocus->setAngle(anAngle);
      }
      mFocus->setPPS(anPower * 32);
   }
}
