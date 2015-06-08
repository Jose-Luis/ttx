#include <TTX/prototypes/Machinegun.hpp>

Machinegun::Machinegun():
      GQE::Prototype("MachinegunLeft"),
      PhysicProto("MachinegunLeft"),
      RenderProto("MachinegunLeft"),
      HealthProto("MachinegunLeft")
   {
      mProperties.set<EntityID>("Name", "Machinegun");

      b2FixtureDef anFixture1;
      mShape1.SetAsBox(0.4, 0.4);
      anFixture1.shape = &mShape1;
      anFixture1.density = 0.5;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 0;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP ;
      anFixture1.filter.maskBits = ObjectCategories::SCENE;

      mBodyDef.type = b2_dynamicBody;
      mProperties.set("rTexRect", sf::IntRect(32, 96, 6, 12));
      mFixturesDef.push_back(anFixture1);

      mProperties.set("Resistance", 5.f);
      mProperties.set("Health", 150.f);

      mProperties.set<b2JointDef*>("JointDef", &mJointDef);
      mProperties.add<GQE::typePropertyID>("AnchorPoint", "WeaponAnchorLeft");

      mJointDef.localAnchorB = b2Vec2(0, 0.4);
   }
