#include <TTX/classes/objects/WeaponManager.hpp>

WeaponManager::WeaponManager()
{}

WeaponManager::WeaponManager(IActionState* theState):
   mPrimary(0),
   mSecondary(0),
   mState(theState)
{}

GQE::IEntity* WeaponManager::getPrimaryWeapon()
{
   GQE::IEntity* primary = 0;
   if(0 < mPrimaryWeapons.size())
   {
      primary = mPrimaryWeapons[mPrimary];
      while(!primary)
      {
         mPrimaryWeapons.erase(mPrimaryWeapons.begin() + mPrimary);
         changePrimaryWeapon();
      }
   }
   return primary;
}

GQE::IEntity* WeaponManager::getSecondaryWeapon()
{
   GQE::IEntity* secondary = 0;
   if(0 < mSecondaryWeapons.size())
   {
      secondary = mSecondaryWeapons[mSecondary];
      while(!secondary)
      {
         mSecondaryWeapons.erase(mSecondaryWeapons.begin() + mSecondary);
         changeSecondaryWeapon();
      }
   }
   return secondary;
}

void WeaponManager::changePrimaryWeapon()
{
   int count = mPrimaryWeapons.size();
   int previousPrimary = mPrimary;

   mPrimary++;
   mPrimary %= count;
   if(previousPrimary != mPrimary)
   {
      mState->deactivateEntity(mPrimaryWeapons[previousPrimary]);
      mState->activeEntity(getPrimaryWeapon());
   }
}

void WeaponManager::changeSecondaryWeapon()
{
   int count = mSecondaryWeapons.size();
   int previousSecondary = mSecondary;

   mSecondary++;
   mSecondary %= count;
   if(previousSecondary != mSecondary)
   {
      mState->deactivateEntity(mSecondaryWeapons[previousSecondary]);
      mState->activeEntity(getSecondaryWeapon());
   }
}

void WeaponManager::addPrimaryWeapon(GQE::IEntity* theWeapon)
{
   mPrimaryWeapons.push_back(theWeapon);
}

void WeaponManager::manage(WeaponManager::Input theFireData)
{
   if(theFireData.mChange[0])
      changePrimaryWeapon();
   if(theFireData.mChange[1])
      changeSecondaryWeapon();
   if(theFireData.mFireData[0].mFire)
   {
      auto primary = getPrimaryWeapon();
      if(primary)
      {
         auto position = primary->mProperties.get<Position2D>("Position");
         primary->mProperties.get<IWeapon*>("Weapon")->fire(position,mState,theFireData.mFireData[0]);
      }
   }
   if(theFireData.mFireData[1].mFire)
   {
      auto secondary = getSecondaryWeapon();
      if(secondary)
      {
         auto position = secondary->mProperties.get<Position2D>("Position");
         secondary->mProperties.get<IWeapon*>("Weapon")->fire(position,mState,theFireData.mFireData[1]);
      }
   }

}
