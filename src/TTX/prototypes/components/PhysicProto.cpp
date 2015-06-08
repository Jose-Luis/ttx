/// @file HealthProto.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/components/PhysicProto.hpp>

PhysicProto::PhysicProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mBodyDef.active = false;
   mProperties.add<EntityID>("Name", "");
   mProperties.add<GQE::IEntity*>("FatherNode", 0);
   mProperties.add<ChildrenContainer>("ChildrenNodes", ChildrenContainer());

   mProperties.add<Position2D>("Position", Position2D(0, 0, 0));
   mProperties.add<Position2D>("LocalPosition", Position2D(0, 0, 0));

   mProperties.add<b2BodyDef*>("BodyDef", &mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>("FixturesDef", &mFixturesDef);
   mProperties.add<GQE::typePropertyID>("FatherAnchorPoint", "");
   mProperties.add<b2JointDef*>("JointDef", &mJointDef);
   mProperties.add<b2Body*>("Body", 0);
   mProperties.add<b2Joint*>("Joint", 0);

   mProperties.add<bool>("Independent", false);

   mSystemIDs.push_back("PhysicSystem");
}

