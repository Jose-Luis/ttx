#include <TTX/prototypes/BasicShip.hpp>

BasicShip::BasicShip():
      PhysicProto("BasicShip")
   {
      mBodyDef.type = b2_dynamicBody;
      mBodyDef.linearDamping = 8.0f;
      mBodyDef.angularDamping = 40.0f;

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

      Propeller anPropeller;
      anPropeller.setEmitterID("ShipPropeller");
      anPropeller.setLinearPower(8192);
      anPropeller.setTurnPower(32768);


      mProperties.add<EntityID>("Name", "BasicShip");
      mProperties.add<Propeller>("pPropeller", anPropeller);
      mProperties.add<b2Vec2>("WeaponAnchorLeft", b2Vec2(-0.8,-0.2));
      mProperties.add<b2Vec2>("WeaponAnchorRight", b2Vec2(0.8,-0.2));
      mProperties.add("TexRect", sf::Rect<int>(0, 96, 32, 32));
      mProperties.add("Resistance", 100.f);
      mProperties.add("Health", 100.f);
      mFixturesDef.push_back(anFixture1);
   }
