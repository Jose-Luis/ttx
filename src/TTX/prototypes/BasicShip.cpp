#include <TTX/prototypes/BasicShip.hpp>

BasicShip::BasicShip(IActionState* theState):
      PhysicProto(BASIC_SHIP_PROTO)
   {
      mProperties.add<EntityID>(NAME, BASIC_SHIP_PROTO);
      
      mBodyDef.type = b2_dynamicBody;
      mBodyDef.linearDamping = 8.0f;
      mBodyDef.angularDamping = 64.0f;

      b2FixtureDef anFixture1;
      b2Vec2 vertices[3];
      vertices[0].Set(0.0f, -1.0f);
      vertices[1].Set(1.0f, 1.0f);
      vertices[2].Set(-1.0f, 1.0f);
      int32 count = 3;
      mShape1.Set(vertices, count);
      anFixture1.shape = &mShape1;
      anFixture1.density = 10.0f;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 0;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP;
      anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::ENEMY_SHIP;

      mProperties.add<b2Vec2>(ID32_("WeaponAnchorLeft"), b2Vec2(-0.8,-0.2));
      mProperties.add<b2Vec2>(ID32_("WeaponAnchorRight"), b2Vec2(0.8,-0.2));
      mProperties.add<b2Vec2>(ID32_("PropellerAnchor"), b2Vec2(0.0,0.8));
      mProperties.add<WeaponManager>(WEAPON_MANAGER, WeaponManager(theState));

      mProperties.add(TEXTURE_RECT, sf::Rect<int>(0, 96, 32, 32));
      mProperties.add(RESISTANCE, 100.f);
      mProperties.add(HEALTH, 100.f);
      mFixturesDef.push_back(anFixture1);
   }
