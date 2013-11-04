   
#ifndef  PROMBO_INC
#define  PROMBO_INC

#include <TTX/prototypes/components/B2Proto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>

class Rombo: public B2Proto, public RenderProto
{

   public:

      Rombo():
         GQE::Prototype("pRombo"),
         B2Proto("pRombo"),
         RenderProto("pRombo")
      {
         b2FixtureDef anFixture1;
        b2Vec2 vertices[3];
        vertices[0].Set(0.0f,-2.0f);
        vertices[1].Set(1.0f,0.0f);
        vertices[2].Set(0.0f,2.0f);
        vertices[3].Set(-1.0f,0.0f);
        int32 count=4;
        mShape1.Set(vertices,count);
         anFixture1.shape = &mShape1;
         anFixture1.density = 0.10f;
         anFixture1.friction = 0.5;
         anFixture1.restitution = 0;
         mBodyDef.type = b2_dynamicBody;
         mBodyDef.bullet = true;
         mBodyDef.linearDamping =5.0f;
         mBodyDef.angularDamping =25.0f;

         mFixturesDef.push_back(anFixture1);
         mProperties.set("rTexRect",sf::Rect<int>(64,0,32,64));
   }
   private:

         b2PolygonShape  mShape1;
};

#endif   // ----- #ifndef PBOX_INC  -----
