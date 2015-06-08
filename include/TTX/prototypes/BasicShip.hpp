#ifndef  PTRIANGLE_INC
#define  PTRIANGLE_INC

#include <TTX/prototypes/components/PhysicProto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/classes/objects/Propeller.hpp>
#include <TTX/classes/objects/Weapon.hpp>

class BasicShip: public PhysicProto, public RenderProto, public HealthProto
{
public:

   BasicShip():
      GQE::Prototype("pBasicShip"),
      PhysicProto("pBasicShip"),
      RenderProto("pBasicShip"),
      HealthProto("pBasicShip")
   {

      mBodyDef.type = b2_dynamicBody;
      mBodyDef.linearDamping = 8.0f;
      mBodyDef.angularDamping = 32.0f;

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
      anPropeller.setTurnPower(16384);

      Weapon anWeapon;
      anWeapon.setPosition(Position2D(-0.75, 0, -HALF_PI));

      mProperties.add<Propeller>("pPropeller", anPropeller);
      mProperties.add<Weapon>("wWeapon", anWeapon);
      mProperties.add<b2Vec2>("WeaponAnchorLeft", b2Vec2(-0.7,-1.2));
      mProperties.set("rTexRect", sf::Rect<int>(0, 96, 32, 32));

      mProperties.set("Resistance", 100.f);
      mProperties.set("Health", 100.f);
      mFixturesDef.push_back(anFixture1);
      mSystemIDs.push_back("PropellerSystem");

   }
private:

   b2PolygonShape  mShape1, mShape2, mShape3;
};

#endif   // ----- #ifndef PBOX_INC  -----
