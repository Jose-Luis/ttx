#ifndef  PTRIANGLE_INC
#define  PTRIANGLE_INC

#include <TTX/prototypes/PhysicProto.hpp>
#include <TTX/classes/objects/Propeller.hpp>
#include <TTX/classes/objects/WeaponManager.hpp>

class BasicShip: public PhysicProto
{
public:

   BasicShip(IActionState* theState);

private:

   b2PolygonShape  mShape1;
};

#endif   // ----- #ifndef PBOX_INC  -----
