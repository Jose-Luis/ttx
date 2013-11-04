
#ifndef  PGROUND_INC
#define  PGROUND_INC

#include <TTX/prototypes/components/B2Proto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>

class Ground: public B2Proto, public RenderProto
{

   public:

      Ground():
         GQE::Prototype("pGround"),
         B2Proto("pGround"),
         RenderProto("pGround")
   {
      mShape1.SetAsBox(16,0.5);
      b2FixtureDef anFixture1;
      anFixture1.shape = &mShape1;
      mBodyDef.type = b2_staticBody;
      mFixturesDef.push_back(anFixture1);

      mProperties.set("rTexRect",sf::Rect<int> (0,80,512,16));
  }
   private:
      b2PolygonShape mShape1;
};

#endif   // ----- #ifndef PBOX_INC  -----

