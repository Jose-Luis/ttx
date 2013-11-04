/// @file Weapon.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-05-07
#ifndef WEAPON_8FPXBSUG
#define WEAPON_8FPXBSUG

#include <TTX/Types.hpp>
#include <TTX/gameStates/IActionState.hpp>

class Weapon
{
public:
    Weapon();
    virtual ~Weapon();
    void fire(Position2D thePosition, IActionState& theState);
    void loadAmunition(int theAmu);
    void setPosition(Position2D thePosition);

private:


    WeaponID      mID;
    AmunitionID   mAmunitionType;
    float         mCadency;
    float         mPower;
    float         mLastTime;
    int           mAmunition;
    int           mAmuLoaded;
    Position2D    mPosition;
};
#endif /* end of include guard: WEAPON_8FPXBSUG */
