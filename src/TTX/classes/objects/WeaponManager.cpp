#include <TTX/classes/objects/WeaponManager.hpp>

WeaponManager::WeaponManager()
{}

WeaponManager::WeaponManager(IActionState* theState):
   mActiveWeapon("none"),
   mState(theState)
{
}

WeaponID WeaponManager::getWeapon()
{
   return mActiveWeapon;
}

void WeaponManager::changeWeapon()
{
   if(mActiveWeapon != "none")
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
   WeaponID weaponID = theWeapon->mProperties.getPointer<Weapon>("Weapon")->getID();
   auto mapIter = mWeaponMap.find(weaponID);
   if(mapIter == mWeaponMap.end())
   {
      mapIter = mWeaponMap.insert(std::pair<WeaponID,std::set<GQE::IEntity*>>(weaponID,std::set<GQE::IEntity*>())).first;
   }
   mapIter->second.insert(theWeapon);
   theWeapon->mProperties.getPointer<Weapon>("Weapon")->setWeaponManager(this);
   if(mActiveWeapon == "none")
      mActiveWeapon = weaponID;
}

void WeaponManager::manage(WeaponManager::Input theInputData)
{
   if(theInputData.mChange)
      changeWeapon();
   if(theInputData.mFireData.mFire)
   {
      if(mActiveWeapon != "none")
      {
         for(auto setIter : mWeaponMap.find(mActiveWeapon)->second)
         {
            Position2D position = setIter->mProperties.get<Position2D>("Position");
            setIter->mProperties.getPointer<Weapon>("Weapon")->fire(position,mState,theInputData.mFireData);
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
      mActiveWeapon = "none";
}

void WeaponManager::removeWeapon(GQE::IEntity* theWeapon)
{
   WeaponID weaponID = theWeapon->mProperties.getPointer<Weapon>("Weapon")->getID();
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
            mActiveWeapon = "none";
      }
   }
}
