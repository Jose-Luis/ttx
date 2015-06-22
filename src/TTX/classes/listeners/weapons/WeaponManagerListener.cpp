#include <TTX/classes/listeners/weapons/WeaponManagerListener.hpp>

WeaponManagerListener::WeaponManagerListener()
{}

void WeaponManagerListener::changeWeapon()
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

void WeaponManagerListener::addWeapon(GQE::IEntity* theWeapon)
{
   auto weaponID = theWeapon->mProperties.get<EntityID>(NAME);
   auto mapIter = mWeaponMap.find(weaponID);
   if(mapIter == mWeaponMap.end())
   {
      mapIter = mWeaponMap.insert(std::pair<WeaponID,std::set<GQE::IEntity*>>(weaponID,std::set<GQE::IEntity*>())).first;
   }
   mapIter->second.insert(theWeapon);
   if(mActiveWeapon == NONE)
      mActiveWeapon = weaponID;
}

void WeaponManagerListener::update(Input::Data theInputData)
{
   if(theInputData.changeNext)
      changeWeapon();
      if(mActiveWeapon != NONE)
      {
         for(auto setIter : mWeaponMap.find(mActiveWeapon)->second)
         {
            setIter->mProperties.get<InputListener*>(INPUT_LISTENER)->update(theInputData);
         }
      }
}

void WeaponManagerListener::removeWeapon(WeaponID theWeapon)
{
   mWeaponMap.erase(theWeapon);
   if(!mWeaponMap.empty())
      mActiveWeapon = mWeaponMap.begin()->first;
   else
      mActiveWeapon = NONE;
}

void WeaponManagerListener::removeWeapon(GQE::IEntity* theWeapon)
{
   auto weaponID = theWeapon->mProperties.get<EntityID>(NAME);
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
