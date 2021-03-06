#ifndef  SIMPLEBULLET_INC
#define  SIMPLEBULLET_INC

#include <TTX/prototypes/PhysicProto.hpp>
#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>

class SimpleBullet: public PhysicProto
{

public:
   SimpleBullet():
      PhysicProto(SIMPLE_BULLET_PROTO)
   {
      b2FixtureDef anFixture1;
      mShape1.m_radius = 0.50;
      anFixture1.shape = &mShape1;
      anFixture1.density = 3;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 1;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_BULLET;
      anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::ENEMY_SHIP;
      mFixturesDef.push_back(anFixture1);
      mBodyDef.type = b2_dynamicBody;
      mBodyDef.bullet = true;
      mBodyDef.fixedRotation = true;

      mProperties.add(TEXTURE_RECT, sf::IntRect(24, 72, 8, 8));
      mProperties.add(HEALTH, 1.f);
      mProperties.add(RESISTANCE, 1.f);
   }
private:
   b2CircleShape mShape1;
};

#endif   // ----- #ifndef PBOX_INC  ----- 
