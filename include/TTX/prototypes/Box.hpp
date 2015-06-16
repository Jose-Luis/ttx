#ifndef  PBOX2_INC
#define  PBOX2_INC

#include <TTX/Types.hpp>
#include <TTX/prototypes/PhysicProto.hpp>
#include <TTX/classes/render/Animation.hpp>

class Box: public PhysicProto
{

public:

   Box():
      PhysicProto(BOX_PROTO)
   {
      b2FixtureDef anFixture1;
      mShape1.SetAsBox(1, 1);
      anFixture1.shape = &mShape1;
      anFixture1.density = 1;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 0;
      anFixture1.filter.categoryBits = ObjectCategories::ENEMY_SHIP;
      anFixture1.filter.maskBits = ObjectCategories::SCENE | ObjectCategories::FRIENDLY_BULLET | ObjectCategories::FRIENDLY_SHIP;

      mBodyDef.type = b2_dynamicBody;
      mFixturesDef.push_back(anFixture1);
      mAnimation1.push_back(sf::IntRect(96, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(128, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(160, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(192, 0, 32, 32));
      Animation anAnimation(&mAnimation1);
      anAnimation.mLoop = true;
      anAnimation.mFPS = 2;
      mProperties.add<Animation>(ANIMATION, anAnimation);

      mProperties.add(TEXTURE_RECT, sf::IntRect(96, 0, 32, 32));
      mProperties.add(RESISTANCE, 5.f);
      mProperties.add(HEALTH, 150.f);
   }
private:


   b2PolygonShape  mShape1;
   std::vector<sf::IntRect> mAnimation1;




};

#endif   // ----- #ifndef PBOX_INC  ----- 
