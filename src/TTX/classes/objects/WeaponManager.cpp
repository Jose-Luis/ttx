#include <TTX/classes/objects/WeaponManager.hpp>

WeaponManager::WeaponManager()
{}

WeaponManager::WeaponManager(IActionState* theState):
   mActiveWeapon("none")
   mState(theState)
{
}

GQE::IEntity* WeaponManager::getWeapon()
{
   if(mActiveWeapon != "none")
      return mWeaponMap[mActiveWeapon];
   else
      return 0;

}

void WeaponManager::changeWeapon()
{
   if(mActiveWeapon != "none")
   {
      auto iterA = mWeaponMap.find(mActiveWeapon);
      auto iterB = iterA;
      iterB++;
      if(iterB == mWeaponMap.end())
         iterB = mWeaponMap.begin();

      if(iterA != iterB)
      {
         mState->deactivateEntity(iterA->second);
         mState->activeEntity(iterB->second);
      }
   }
}

void WeaponManager::addWeapon(GQE::IEntity* theWeapon)
{
   WeaponID weaponID = theWeapon->mProperties.getPointer<Weapon>("Weapon")->getID();
   auto iter = mWeaponMap.insert(std::pair<WeaponID,GQE::IEntity*>(weaponID,theWeapon)).first;
   theWeapon->mProperties.getPointer<Weapon>("Weapon")->setWeaponManager(this);
   if(mActiveWeapon == "none")
      mActiveWeapon = iter->first;
}

void WeaponManager::manage(WeaponManager::Input theInputData)
{
   if(theInputData.mChange)
      changeWeapon();
   if(theInputData.mFireData.mFire)
   {
      if(mActiveWeapon != "none")
      {
         Position2D position = mWeaponMap[mActiveWeapon]->mProperties.get<Position2D>("Position");
         mWeaponMap[mActiveWeapon]->mProperties.getPointer<Weapon>("Weapon")->fire(position,mState,theInputData.mFireData);
      }
   }
}

void WeaponManager::removeWeapon(WeaponID theWeapon)
{
   mWeaponMap.erase(theWeapon);
   if(!mWeaponMap.empty())
      mActiveWeapon = mWeaponMap.begin()->first;
   else
      mActiveWeapon = "none";
}
