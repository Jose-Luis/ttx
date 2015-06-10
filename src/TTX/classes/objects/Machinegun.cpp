#include <TTX/classes/objects/Machinegun.hpp>
//------------------------------------------------------------------------------
//       Class:  Machinegun
//      Method:  Machinegun
// Description:  default constructor
//------------------------------------------------------------------------------
Machinegun::Machinegun():
{

}
//------------------------------------------------------------------------------
//       Class:  Machinegun
//      Method:  ~Machinegun
// Description:  deconstructor
//------------------------------------------------------------------------------
Machinegun::~Machinegun()
{
}
//------------------------------------------------------------------------------
//       Class:  Machinegun
//      Method:  fire
// Description:  A stupid method
//------------------------------------------------------------------------------
void Machinegun::fire(FireData theFireData)
{
   float anTime = theState.getElapsedTime();

   if (anTime - mLastTime > mCadency && mAmunition)
   {
      float anCos = std::cos(thePosition.angle);
      float anSin = std::sin(thePosition.angle);

      float anX = mPosition.x * anCos - mPosition.y * anSin;
      float anY = mPosition.y * anCos + mPosition.x * anSin;

      Position2D anPosition = Position2D(thePosition.x + anX,
                                         thePosition.y + anY,
                                         thePosition.angle + mPosition.angle);

      Position2D anImpulse(std::cos(anPosition.angle)*mPower,
                           std::sin(anPosition.angle)*mPower,
                           0);

      theState.addInstance(mAmunitionType, anPosition, anImpulse);
      mAmunition--;
      mLastTime = anTime;
   }
}
//------------------------------------------------------------------------------
//       Class:  Machinegun
//      Method:  loadAmunition
// Description:  add ammunition
//------------------------------------------------------------------------------
void Machinegun::loadAmunition(int theAmu)
{
   mAmunition += theAmu;
}
//------------------------------------------------------------------------------
//       Class:  Machinegun
//      Method:  setPosition
// Description:  A stupid method
//------------------------------------------------------------------------------
