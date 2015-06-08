#ifndef  SIMPLEBULLET_INC
#define  SIMPLEBULLET_INC

#include <TTX/prototypes/components/PhysicProto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/Types.hpp>

class SimpleBullet: public PhysicProto, public RenderProto, public HealthProto
{

public:
   SimpleBullet():
      GQE::Prototype("pSimpleBullet"),
      PhysicProto("pSimpleBullet"),
      RenderProto("pSimpleBullet"),
      HealthProto("pSimpleBullet")
   {
      b2FixtureDef anFixture1;
      mShape1.m_radius = 0.50;
      anFixture1.shape = &mShape1;
      anFixture1.density = 3;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 1;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_BULLET;
      anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::ENEMY_SHIP;

      mBodyDef.type = b2_dynamicBody;
      mBodyDef.bullet = true;
      mBodyDef.fixedRotation = true;
      mProperties.set("rTexRect", sf::IntRect(24, 72, 8, 8));
      mProperties.set("Health", 1.f);
      mProperties.set("Resistance", 1.f);
      mFixturesDef.push_back(anFixture1);
   }
private:
   b2CircleShape mShape1;
};

#endif   // ----- #ifndef PBOX_INC  ----- 
