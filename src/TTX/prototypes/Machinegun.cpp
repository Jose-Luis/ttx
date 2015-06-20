#include <TTX/prototypes/Machinegun.hpp>

Machinegun::Machinegun():
   PhysicProto(MACHINEGUN_PROTO)
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

   mProperties.add<EntityID>(NAME, MACHINEGUN_PROTO);
   mProperties.add<GQE::typePropertyID>(ID32_("AnchorPoint"), ID32_(""));
   mProperties.add(TEXTURE_RECT, sf::IntRect(32, 96, 6, 12));
   mProperties.add(INPUT_LISTENER, SimpleWeaponListener());
   mProperties.add(RESISTANCE, 5.f);
   mProperties.add(HEALTH, 150.f);
   mProperties.add<b2JointDef*>(JOINTDEF, &mJointDef);
}
