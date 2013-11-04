/// @file B2Proto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  B2PROTO_INC
#define  B2PROTO_INC

#include <Box2D/Box2D.h>
#include <GQE/Entity/classes/Prototype.hpp>

class B2Proto: virtual public GQE::Prototype
{
   public:

      B2Proto(GQE::typePrototypeID theID);

   protected:

      b2BodyDef mBodyDef;
      std::vector<b2FixtureDef> mFixturesDef;
};

#endif   // ----- #ifndef B2PROTO_INC  -----

