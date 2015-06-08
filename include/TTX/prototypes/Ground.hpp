
#ifndef  PGROUND_INC
#define  PGROUND_INC

#include <TTX/prototypes/components/PhysicProto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>

class Ground: public PhysicProto, public RenderProto
{

public:

   Ground():
      GQE::Prototype("pGround"),
      PhysicProto("pGround"),
      RenderProto("pGround")
   {
      mShape1.SetAsBox(16, 0.5);
      b2FixtureDef anFixture1;
      anFixture1.shape = &mShape1;
      mBodyDef.type = b2_staticBody;
      mFixturesDef.push_back(anFixture1);

      mProperties.set("rTexRect", sf::Rect<int> (0, 80, 512, 16));
   }
private:
   b2PolygonShape mShape1;
};

#endif   // ----- #ifndef PBOX_INC  -----

