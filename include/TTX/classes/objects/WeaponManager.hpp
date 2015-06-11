#ifndef WEAPONMANAGER_INC
#define WEAPONMANAGER_INC

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>

class IWeapon;

class WeaponManager
{
   WeaponManager(IActionState& theState);

   GQE::IEntity* getPrimaryWeapon();
   GQE::IEntity* getSecondaryWeapon();

   void fire(FireData theFireData);

   void changePrimaryWeapon();
   void changeSecondaryWeapon();

   void addPrimaryWeapon(GQE::IEntity* theWeapon);

   private:

   int mPrimary,mSecondary;
   std::vector<GQE::IEntity*> mPrimaryWeapons;
   std::vector<GQE::IEntity*> mSecondaryWeapons;
   IActionState& mState;
}

#endif
