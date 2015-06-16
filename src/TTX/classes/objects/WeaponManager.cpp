#include <TTX/classes/objects/WeaponManager.hpp>

WeaponManager::WeaponManager()
{}

WeaponManager::WeaponManager(IActionState* theState):
   mActiveWeapon(NONE),
   mState(theState)
{
}

WeaponID WeaponManager::getWeapon()
{
   return mActiveWeapon;
}

void WeaponManager::changeWeapon()
{
   if(mActiveWeapon != NONE)
   {
      auto iterA = mWeaponMap.find(mActiveWeapon);
      auto iterB = iterA;
      do
      {
         iterB++;
         if(iterB == mWeaponMap.end())
            iterB = mWeaponMap.begin();
      }
      while(iterB->second.empty());

      if(iterA != iterB)
      {
         for(auto setIter : iterA->second)
            mState->deactivateEntity(setIter);
         for(auto setIter : iterA->second)
            mState->activeEntity(setIter);
      }
   }
}

void WeaponManager::addWeapon(GQE::IEntity* theWeapon)
{
   WeaponID weaponID = theWeapon->mProperties.getPointer<Weapon>(WEAPON)->getID();
   auto mapIter = mWeaponMap.find(weaponID);
   if(mapIter == mWeaponMap.end())
   {
      mapIter = mWeaponMap.insert(std::pair<WeaponID,std::set<GQE::IEntity*>>(weaponID,std::set<GQE::IEntity*>())).first;
   }
   mapIter->second.insert(theWeapon);
   theWeapon->mProperties.getPointer<Weapon>(WEAPON)->setWeaponManager(this);
   if(mActiveWeapon == NONE)
      mActiveWeapon = weaponID;
}

void WeaponManager::manage(WeaponManager::Input theInputData)
{
   if(theInputData.mChange)
      changeWeapon();
   if(theInputData.mFireData.mFire)
   {
      if(mActiveWeapon != NONE)
      {
         for(auto setIter : mWeaponMap.find(mActiveWeapon)->second)
         {
            Position2D position = setIter->mProperties.get<Position2D>(POSITION);
            setIter->mProperties.getPointer<Weapon>(WEAPON)->fire(position,mState,theInputData.mFireData);
         }
      }
   }
}

void WeaponManager::removeWeapon(WeaponID theWeapon)
{
   mWeaponMap.erase(theWeapon);
   if(!mWeaponMap.empty())
      mActiveWeapon = mWeaponMap.begin()->first;
   else
      mActiveWeapon = NONE;
}

void WeaponManager::removeWeapon(GQE::IEntity* theWeapon)
{
   WeaponID weaponID = theWeapon->mProperties.getPointer<Weapon>(WEAPON)->getID();
   auto iter = mWeaponMap.find(weaponID);
   if(iter != mWeaponMap.end())
   {
      iter->second.erase(theWeapon);
      if(iter->second.empty())
      {
         mWeaponMap.erase(weaponID);
         if(!mWeaponMap.empty())
            mActiveWeapon = mWeaponMap.begin()->first;
         else
            mActiveWeapon = NONE;
      }
   }
}
