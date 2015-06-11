#include <TTX/prototypes/ShipPropeller.hpp>

ShipPropeller::ShipPropeller(Particles& theSystem):
   PhysicProto("ShipPropeller")
{
   mProperties.add<EntityID>("Name", "Propeller");

   b2FixtureDef anFixture1;
   mShape.SetAsBox(0.375, 0.28125);
   anFixture1.shape = &mShape;
   anFixture1.density = 3;
   anFixture1.friction = 0.5;
   anFixture1.restitution = 0;
   anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP;
   anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::ENEMY_SHIP | ObjectCategories::ENEMY_BULLET;
   mFixturesDef.push_back(anFixture1);

   mBodyDef.type = b2_dynamicBody;
   mJointDef.localAnchorB = b2Vec2(0, 0.4);
   mProperties.add<b2JointDef*>("JointDef", &mJointDef);

   mProperties.add<GQE::typePropertyID>("AnchorPoint", "PropellerAnchor");

   Propeller* propeller = new Propeller(theSystem);
   propeller->setEmitterID("ShipPropeller");
   propeller->setLinearPower(8192);
   propeller->setTurnPower(32768);

   mProperties.add<IPropeller*>("Propeller", propeller);

   mProperties.add<sf::IntRect>("TexRect",sf::IntRect(42,96,12,9));
   mProperties.add("Resistance", 5.f);
   mProperties.add("Health", 150.f);
   mProperties.add<MoveData>("MoveData", MoveData());

}
