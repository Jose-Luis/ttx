#ifndef  PMACHINEGUN_INC
#define  PMACHINEGUN_INC

#include <TTX/Types.hpp>
#include <Box2D/Box2D.h>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/prototypes/components/PhysicProto.hpp>
#include <TTX/classes/render/Animation.hpp>

class Machinegun:   public PhysicProto, public RenderProto, public HealthProto
{

public:

   Machinegun():
      GQE::Prototype("pMachinegun"),
      PhysicProto("pMachinegun"),
      RenderProto("pMachinegun"),
      HealthProto("pMachinegun")
   {
      b2FixtureDef anFixture1;
      mShape1.SetAsBox(1, 1);
      anFixture1.shape = &mShape1;
      anFixture1.density = 1;
      anFixture1.friction = 0.5;
      anFixture1.restitution = 0;
      anFixture1.filter.categoryBits = ObjectCategories::FRIENDLY_SHIP ;
      anFixture1.filter.maskBits = ObjectCategories::SCENE;

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

      mProperties.set("LocalPosition", Position2D(0.5, 0.5, 0));
      mProperties.set<b2JointDef*>("JointDef", &mJointDef);
      mProperties.set<EntityID>("Name","Machinegun");
      mProperties.set("FatherAnchorPoint","WeaponAnchor");

      mJointDef.localAnchorB = b2Vec2(0, -1);
      mJointDef.collideConnected = true;
   }
private:


   b2WeldJointDef mJointDef;
   b2PolygonShape  mShape1;
   std::vector<sf::IntRect> mAnimation1;
};

#endif   // ----- #ifndef PBOX_INC  ----- 
