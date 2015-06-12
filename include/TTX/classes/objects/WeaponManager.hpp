#ifndef WEAPONMANAGER_INC
#define WEAPONMANAGER_INC

#include <TTX/Types.hpp>
#include <set>
#include <TTX/gameStates/IActionState.hpp>
#include <TTX/classes/objects/Weapon.hpp>
#include <TTX/classes/objects/WeaponMachinegun.hpp>

class WeaponManager
{
public:

   struct Input
   {
      FireData mFireData;
      bool mChange;

      Input():
         mChange(false)
      {}
   };

   WeaponManager();

   WeaponManager(IActionState* theState);

   GQE::IEntity* getWeapon();

   void manage(Input theFireData);

   void changeWeapon();

   void changeWeapon(WeaponID);

   void addWeapon(GQE::IEntity* theWeapon);

   void removeWeapon(WeaponID theWeapon);

private:

   GQE::IEntity* mActor;
   std::map<WeaponID,GQE::IEntity*> mWeaponMap;
   WeaponID mActiveWeapon;
   IActionState* mState;
};

#endif
