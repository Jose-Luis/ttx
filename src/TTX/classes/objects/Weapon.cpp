#include <TTX/classes/objects/Weapon.hpp>
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  Weapon
// Description:  default constructor
//------------------------------------------------------------------------------
Weapon::Weapon():
    mID("Submachinegun"),
    mAmunitionType("pSimpleBullet"),
    mCadency(0.1),
    mPower(64),
    mLastTime(0),
    mAmunition(1000),
    mPosition(0,0,0)
{

}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  ~Weapon
// Description:  deconstructor
//------------------------------------------------------------------------------
Weapon::~Weapon()
{
}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  fire
// Description:  A stupid method
//------------------------------------------------------------------------------
void Weapon::fire(Position2D thePosition,IActionState& theState)
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

      theState.addInstance(mAmunitionType,anPosition,anImpulse);
      mAmunition--;
      mLastTime = anTime;
    }
}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  loadAmunition
// Description:  add ammunition
//------------------------------------------------------------------------------
void Weapon::loadAmunition(int theAmu)
{
    mAmunition += theAmu;
}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  setPosition
// Description:  A stupid method 
//------------------------------------------------------------------------------
void Weapon::setPosition(Position2D thePosition)
{
   mPosition = thePosition;
}
