/// @file PhysicNodegcProto.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  PHYSICPROTO_INC
#define  PHYSICPROTO_INC

#include <TTX/Types.hpp>
#include <Box2D/Box2D.h>
#include <GQE/Entity/classes/Prototype.hpp>


class PhysicProto:  virtual public GQE::Prototype
{

public:

   PhysicProto(GQE::typePrototypeID theID);

protected:

   b2BodyDef mBodyDef;
   b2JointDef mJointDef;
   std::vector<b2FixtureDef> mFixturesDef;
};

#endif   // ----- #ifndef RENDERPROTO_INC  -----
