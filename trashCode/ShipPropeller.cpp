
#include <TTX/classes/propellers/ShipPropeller.hpp>

ShipPropeller::ShipPropeller()
{
   setLinearPower(8192);
   setTurnPower(2);
}

void ShipPropeller::impulse(GQE::IEntity* theEntity,b2Vec2 theDirection)
{
   b2Body* anBody = theEntity->mProperties.get<b2Body*>("b2Body");
   if(mOn && anBody)
   {
      mPower = theDirection.LengthSquared() * 32;
      if(mPower)
      {
         theDirection *= mLinearPower;
         anBody->ApplyForceToCenter(theDirection);
         anBody->ApplyTorque(anBody->GetLocalVector(theDirection).x * mTurnPower);
         mPosition = anBody->GetWorldCenter(); 
         mAngle = anBody->GetAngle() * TODEG;
      }
   }
}
void ShipPropeller::update(float theElapsedTime)
{
   mFocus->setPosition(gt::Vec2D(mPosition.x,mPosition.y));
   mFocus->setAngle(gt::Angle(mAngle));
   mFocus->setPPS(mPower);
}
//------------------------------------------------------------------------------
//       Class:  ShipPropeller
//      Method:  
// Description:  setter 
//------------------------------------------------------------------------------
void ShipPropeller::setBody (b2Body* theBody)
{
   mBody = theBody;
   return;
}
