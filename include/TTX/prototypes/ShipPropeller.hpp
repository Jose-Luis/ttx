#ifndef SHIPPROPELLER_INC
#define SHIPPROPELLER_INC

#include<Box2D/Box2D.h>
#include<TTX/prototypes/PhysicProto.hpp>
#include<TTX/classes/objects/Propeller.hpp>

class ShipPropeller: public PhysicProto
{
   public:
      ShipPropeller(Particles& theSystem);

   private:

      b2WeldJointDef mJointDef;
      b2PolygonShape  mShape;
};

#endif
