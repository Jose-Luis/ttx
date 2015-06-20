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

   mProperties.add<b2BodyDef*>(BODYDEF, &mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>(FIXTUREDEF, &mFixturesDef);
   mProperties.add<Position2D>(POSITION,Position2D());
   mProperties.add<Position2D>(INITIAL_IMPULSE,Position2D());
}

