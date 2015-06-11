#include <TTX/classes/objects/WeaponMachinegun.hpp>

WeaponMachinegun::WeaponMachinegun()
{}

WeaponMachinegun::~WeaponMachinegun()
{}

void WeaponMachinegun::fire(Position2D thePosition,IActionState* theState,FireData theFireData)
{
   //float anTime = theState->getElapsedTime();
   

   //if (anTime - mLastTime > mCadency && mAmunition)
   //{
      //float anCos = std::cos(thePosition.angle);
      //float anSin = std::sin(thePosition.angle);

      //float anX = mPosition.x * anCos - mPosition.y * anSin;
      //float anY = mPosition.y * anCos + mPosition.x * anSin;

      //Position2D anPosition = Position2D(thePosition.x + anX,
                                         //thePosition.y + anY,
                                         //thePosition.angle + mPosition.angle);

      Position2D anImpulse(std::cos(thePosition.angle)*2,
                           std::sin(thePosition.angle)*2,
                           0);

   theState->addInstance("SimpleBullet",thePosition,anImpulse);
      //theState.addInstance(mAmunitionType, anPosition, anImpulse);
      //mAmunition--;
      //mLastTime = anTime;
   //}
}

void WeaponMachinegun::loadAmunition(int theAmu)
{}

