#include <TTX/classes/objects/WeaponManager.hpp>

WeaponManager::WeaponManager(IActionState& theState):
   mState(theState)
{}

GQE::IEntity* WeaponManager::getPrimaryWeapon()
{
   auto primary = mPrimaryWeapons[mPrimary];
   while(!primary && mPrimaryWeapons.size())
   {
      mPrimaryWeapons.erase(mPrimaryWeapons.begin() + mPrimary);
      changePrimaryWeapon();
   }
   return primary;
}

GQE::IEntity* WeaponManager::getSecondaryWeapon()
{
   auto secondary = mSecondaryWeapons[mSecondary];
   while(!secondary && mSecondaryWeapons.size())
   {
      mSecondaryWeapons.erase(mSecondaryWeapons.begin() + mSecondary);
      changeSecondaryWeapon();
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
      mState.deactivateEntity(mPrimaryWeapons[previousPrimary]);
      mState.activeEntity(getPrimaryWeapon());
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
      mState.deactivateEntity(mSecondaryWeapons[previousSecondary]);
      mState.activeEntity(getSecondaryWeapon());
   }
}

void WeaponManager::addPrimaryWeapon(GQE::IEntity* theWeapon)
{
  mPrimaryWeapons.push_back(theWeapon);
}

