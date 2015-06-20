#ifndef WEAPONMANAGER_INC
#define WEAPONMANAGER_INC

#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>
#include <set>
#include <GQE/Core/utils/CRC32.hpp>
#include <TTX/gameStates/IActionState.hpp>
#include <TTX/classes/objects/Weapon.hpp>

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

   WeaponID getWeapon();

   void manage(Input theFireData);

   void changeWeapon();

   void changeWeapon(WeaponID);

   void addWeapon(GQE::IEntity* theWeapon);

   void removeWeapon(WeaponID theWeapon);

   void removeWeapon(GQE::IEntity* theWeapon);

private:

   GQE::IEntity* mActor;
   std::map<WeaponID,std::set<GQE::IEntity*>> mWeaponMap;
   WeaponID mActiveWeapon;
   IActionState* mState;
};

#endif
