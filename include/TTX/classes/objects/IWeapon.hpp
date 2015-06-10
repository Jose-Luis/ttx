#ifndef IWEAPON_INC
#define IWEAPON_INC

class FireData;

class IWeapon
{
   virtual void fire(FireData) = 0;
};

#endif
