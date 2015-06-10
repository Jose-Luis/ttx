#ifndef  PTRIANGLE_INC
#define  PTRIANGLE_INC

#include <TTX/prototypes/PhysicProto.hpp>
#include <TTX/classes/objects/Propeller.hpp>

class BasicShip: public PhysicProto
{
public:

   BasicShip();

private:

   b2PolygonShape  mShape1, mShape2, mShape3;
};

#endif   // ----- #ifndef PBOX_INC  -----
