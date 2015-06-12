/// @file HealthProto.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/PhysicProto.hpp>

PhysicProto::PhysicProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mBodyDef.active = false;

   mProperties.add<b2BodyDef*>                ("BodyDef", &mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>("FixturesDef", &mFixturesDef);
   mProperties.add<Position2D>("Position",Position2D());
   mProperties.add<Position2D>("InitialImpulse",Position2D());
}

