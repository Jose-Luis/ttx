#ifndef WEAPONMACHINEGUN_INC
#define WEAPONMACHINEGUN_INC

#include <TTX/Types.hpp>
#include <TTX/classes/objects/IWeapon.hpp>
#include <TTX/gameStates/IActionState.hpp>
class WeaponManager;
class WeaponMachinegun: public IWeapon
{
public:
   WeaponMachinegun();
   virtual ~WeaponMachinegun();
   void fire(Position2D,IActionState*,FireData);
   void loadAmunition(int);
   void getAmmunitionCount();
   void setWeaponManager(WeaponManager*);
   WeaponManager* getManager() {return mManager;}

private:

   int mAmmuCount;
   WeaponManager* mManager;
};
#endif /* end of include guard: WEAPON_8FPXBSUG */
