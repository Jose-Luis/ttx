/// @file Weapon.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-05-07
#ifndef WEAPON_8FPXBSUG
#define WEAPON_8FPXBSUG

#include <TTX/Types.hpp>
#include <TTX/classes/objects/IWeapon.hpp>
#include <TTX/gameStates/IActionState.hpp>

class Machinegun: public IWeapon
{
public:
   Machinegun();
   virtual ~Machinegun();
   void fire(FireData theFireData);
   void loadAmunition(int theAmu);
   void getAmmunitionCount();

private:

   int mAmmuCount;
};
#endif /* end of include guard: WEAPON_8FPXBSUG */
