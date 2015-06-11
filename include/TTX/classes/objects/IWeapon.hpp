#ifndef IWEAPON_INC
#define IWEAPON_INC

class Position2D;
class IActionState;
class FireData;

class IWeapon
{
   public:
      virtual void fire(Position2D,IActionState*,FireData) = 0;
};

#endif
