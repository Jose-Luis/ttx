#ifndef  PHYSICPROTO_INC
#define  PHYSICPROTO_INC

#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>
#include <Box2D/Box2D.h>
#include <GQE/Core/utils/CRC32.hpp>
#include <GQE/Entity/classes/Prototype.hpp>

class PhysicProto:  public GQE::Prototype
{

public:

   PhysicProto(GQE::typePrototypeID theID);

protected:

   b2BodyDef mBodyDef;
   std::vector<b2FixtureDef> mFixturesDef;
};

#endif 
