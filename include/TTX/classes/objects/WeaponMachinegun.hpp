/// @file Weapon.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-05-07
#ifndef WEAPONMACHINEGUN_INC
#define WEAPONMACHINEGUN_INC

#include <TTX/Types.hpp>
#include <TTX/classes/objects/IWeapon.hpp>
#include <TTX/gameStates/IActionState.hpp>

class WeaponMachinegun: public IWeapon
{
public:
   WeaponMachinegun();
   virtual ~WeaponMachinegun();
   void fire(Position2D,IActionState*,FireData);
   void loadAmunition(int theAmu);
   void getAmmunitionCount();

private:

   int mAmmuCount;
};
#endif /* end of include guard: WEAPON_8FPXBSUG */
