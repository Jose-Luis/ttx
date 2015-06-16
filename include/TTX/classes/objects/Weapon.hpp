/// @file Weapon.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-05-07
#ifndef WEAPON_8FPXBSUG
#define WEAPON_8FPXBSUG

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>
class WeaponManager;

class Weapon
{
public:
   Weapon();
   Weapon(WeaponID,AmunitionID,float,float,GQE::typeAssetID);
   virtual ~Weapon();
   void fire(Position2D , IActionState* , FireData);
   void loadAmunition(int theAmu);
   void setPosition(Position2D thePosition);
   void setWeaponManager(WeaponManager*);
   WeaponID getID();
   WeaponManager* getManager(){return mManager;}

private:


   WeaponID      mID;
   AmunitionID   mAmunitionType;
   float         mCadency;
   float         mPower;
   float         mLastTime;
   int           mAmunition;
   int           mAmuLoaded;
   WeaponManager* mManager;
   sf::Sound*    mSound;
};
#endif /* end of include guard: WEAPON_8FPXBSUG */
