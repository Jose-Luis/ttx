#include <TTX/classes/listeners/weapons/SimpleWeaponListener.hpp>

void SimpleWeaponListener::update(Input::Data theInput)
{
   if(theInput.Afire)
   {
      auto position = mEntity->mProperties.get<Position2D>(POSITION);

      float time(mState->getElapsedTime());

      if (time - mLastTime > mCadency && mAmunition)
      {

         Position2D anImpulse(std::sin(position.angle * TORAD)*mPower,
               -std::cos(position.angle * TORAD)*mPower,
               0);

         mState->addInstance(mAmunitionType, position, anImpulse);
         mAmunition--;
         mLastTime = time;
      }
   }
}

SimpleWeaponListener::SimpleWeaponListener():
   mAmunitionType(SIMPLE_BULLET_PROTO),
   mCadency(1),
   mPower(1024),
   mAmunition(std::numeric_limits<uint32_t>::infinity())
{
}

void SimpleWeaponListener::setAmmunitionType(AmunitionID theAmmu)
{
   mAmunitionType = theAmmu;
}

void SimpleWeaponListener::setCadency(float theCadency)
{
   mCadency = theCadency;
}

void SimpleWeaponListener::setPower(float thePower)
{
   mPower = thePower;
}