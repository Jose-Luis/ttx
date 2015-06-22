#include <TTX/prototypes/ShipPropeller.hpp>

ShipPropeller::ShipPropeller(Particles& theSystem):
   PhysicProto(SHIP_PROPELLER_PROTO)
{
   mProperties.add<EntityID>(NAME, PROPELLER);

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
   mProperties.add<b2JointDef*>(JOINTDEF, &mJointDef);

   mProperties.add<GQE::typePropertyID>(ANCHOR_POINT, BACK_ANCHOR);

   mProperties.add<EntityInputListener*>(INPUT_LISTENER,new ShipPropellerListener());
   mProperties.add<sf::IntRect>(TEXTURE_RECT,sf::IntRect(42,96,12,9));
   mProperties.add(RESISTANCE, 5.f);
   mProperties.add(HEALTH, 15.f);
   mProperties.add<MoveData>(MOVE_DATA, MoveData());

}
