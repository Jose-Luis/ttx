#ifndef  PMACHINEGUN_INC
#define  PMACHINEGUN_INC

#include <TTX/Definition.hpp>
#include <TTX/Types.hpp>
#include <Box2D/Box2D.h>
#include <TTX/prototypes/PhysicProto.hpp>
#include <TTX/classes/render/Animation.hpp>
#include <TTX/classes/objects/Weapon.hpp>

class Machinegun:   public PhysicProto
{

public:
   Machinegun();

private:

   b2WeldJointDef mJointDef;
   b2PolygonShape  mShape1;
};

#endif   // ----- #ifndef PBOX_INC  -----
