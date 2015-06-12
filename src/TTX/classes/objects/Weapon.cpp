#include <TTX/classes/objects/Weapon.hpp>
#include <TTX/classes/objects/WeaponManager.hpp>
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  Weapon
// Description:  default constructor
//------------------------------------------------------------------------------
Weapon::Weapon():
   mID("Submachinegun"),
   mAmunitionType("SimpleBullet"),
   mCadency(0.1),
   mPower(64),
   mLastTime(0),
   mAmunition(1000),
   mManager(0)
{
}
Weapon::Weapon(WeaponID theID,AmunitionID theAmuID,float thePower,float theCadency):
   mID(theID),
   mAmunitionType(theAmuID),
   mCadency(theCadency),
   mPower(thePower)
{}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  ~Weapon
// Description:  deconstructor
//------------------------------------------------------------------------------
Weapon::~Weapon()
{
   if(mManager)
   mManager->removeWeapon(mID);
}
//------------------------------------------------------------------------------
//       Class:  Weapon
//      Method:  fire
// Description:  A stupid method
//------------------------------------------------------------------------------
void Weapon::fire(Position2D thePosition, IActionState* theState,FireData theFireData)
{
   float anTime = theState->getElapsedTime();

   if (anTime - mLastTime > mCadency && mAmunition)
   {

      Position2D anImpulse(std::sin(thePosition.angle * TORAD)*mPower,
                           -std::cos(thePosition.angle * TORAD)*mPower,
                           0);

      theState->addInstance(mAmunitionType, thePosition, anImpulse);
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
void Weapon::setWeaponManager(WeaponManager* theManager)
{
   mManager = theManager;
}

WeaponID Weapon::getID()
{
   return mID;
}
