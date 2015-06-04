#ifndef  PMACHINEGUN_INC
#define  PMACHINEGUN_INC

#include <TTX/Types.hpp>
#include <Box2D/Box2D.h>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/prototypes/components/AttachedProto.hpp>
#include <TTX/classes/render/Animation.hpp>

class Machinegun:   public AttachedProto, public RenderProto, public HealthProto
{

public:

   Machinegun():
      GQE::Prototype("pMachinegun"),
      AttachedProto("pMachinegun"),
      RenderProto("pMachinegun"),
      HealthProto("pMachinegun")
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
      mProperties.set("rTexRect", sf::IntRect(96, 0, 32, 32));
      mFixturesDef.push_back(anFixture1);
      mAnimation1.push_back(sf::IntRect(96, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(128, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(160, 0, 32, 32));
      mAnimation1.push_back(sf::IntRect(192, 0, 32, 32));
      Animation anAnimation(&mAnimation1);
      anAnimation.mLoop = true;
      anAnimation.mFPS = 2;
      mProperties.add<Animation>("rAnimation", anAnimation);
      mSystemIDs.push_back("AnimationSystem");
      mProperties.set("Resistance", 5.f);
      mProperties.set("Health", 150.f);

      mProperties.set("LocalTransform", b2Transform(b2Vec2( 0.5, 0.5 ), b2Rot()));
      mProperties.set<b2JointDef*>("JointDef", &mJointDef);
      mJointDef.localAnchorA = b2Vec2(-1, -1);
   }
private:


   b2WeldJointDef mJointDef;
   b2PolygonShape  mShape1;
   std::vector<sf::IntRect> mAnimation1;
};

#endif   // ----- #ifndef PBOX_INC  ----- 
