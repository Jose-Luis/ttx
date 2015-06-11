#ifndef WEAPONMANAGER_INC
#define WEAPONMANAGER_INC

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>
#include <TTX/classes/objects/IWeapon.hpp>


class WeaponManager
{
public:

   struct Input
   {
      Input()
      {
         mChange[0] = false;
         mChange[1] = false;
      };

      FireData mFireData[2];
      bool mChange[2];
   };

   WeaponManager();

   WeaponManager(IActionState* theState);

   GQE::IEntity* getPrimaryWeapon();
   GQE::IEntity* getSecondaryWeapon();

   void manage(Input theFireData);

   void changePrimaryWeapon();
   void changeSecondaryWeapon();

   void addPrimaryWeapon(GQE::IEntity* theWeapon);

private:

   GQE::IEntity* mActor;
   int mPrimary, mSecondary;
   std::vector<GQE::IEntity*> mPrimaryWeapons;
   std::vector<GQE::IEntity*> mSecondaryWeapons;
   IActionState* mState;
};

#endif
