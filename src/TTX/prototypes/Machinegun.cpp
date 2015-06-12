#include <TTX/prototypes/Machinegun.hpp>

Machinegun::Machinegun():
      PhysicProto("Machinegun")
   {
      b2FixtureDef anFixture1;
      mShape1.SetAsBox(0.4, 0.4);
      anFixture1.shape = &mShape1;
      anFixture1.density = 0.5;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 0;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP ;
      anFixture1.filter.maskBits = ObjectCategories::SCENE;
      mBodyDef.type = b2_dynamicBody;
      mFixturesDef.push_back(anFixture1);
      mJointDef.localAnchorB = b2Vec2(0, 0.4);

      mProperties.add<EntityID>("Name", "Machinegun");
      mProperties.add<GQE::typePropertyID>("AnchorPoint", "");
      mProperties.add("TexRect", sf::IntRect(32, 96, 6, 12));
      mProperties.add("Weapon",Weapon());
      mProperties.add("Resistance", 5.f);
      mProperties.add("Health", 150.f);
      mProperties.add<b2JointDef*>("JointDef", &mJointDef);
   }
