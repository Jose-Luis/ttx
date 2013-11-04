// =====================================================================================
// 
//       Filename:  B2Ground.hpp
// 
//    Description:   
// 
//        Version:  1.0
//        Created:  21/10/12 01:54:58
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  YOUR NAME (), 
//        Company:  
// 
// =====================================================================================

#ifndef  B2GROUND_INC
#define  B2GROUND_INC

#include <GQE/Entity/classes/Prototype.hpp>
#include <Box2D/Box2D.h>

class B2Ground: public GQE::Prototype
{
   public:
      B2Ground():
         GQE::Prototype("B2Ground"),
         mImage("resources/ground.png")
   {
      sf::Sprite anSprite(mImage.getAsset());
      float anWidth,anHeight;
      mProperties.add<sf::Sprite>("Sprite",anSprite);   
      anWidth = anSprite.getTexture()->getSize().x;
      anHeight = anSprite.getTexture()->getSize().y;
      mProperties.add<sf::IntRect>("rSpriteRect",sf::IntRect(0,0,anWidth,anHeight));   
     mProperties.add<sf::Vector2f>("vOrigin",sf::Vector2f(500,5));
      b2BodyDef anBodyDef;
      anBodyDef.position.Set(600,-450);

      anShape.SetAsBox(500.0f,5.0f);

      b2FixtureDef anFixtureDef;
      anFixtureDef.shape = &anShape;

      std::vector<b2FixtureDef> anFixturesDef;
      anFixturesDef.push_back(anFixtureDef);

      mProperties.add<b2BodyDef>("b2BodyDef",anBodyDef);
      mProperties.add<std::vector<b2FixtureDef> >("b2Fixtures",anFixturesDef);
   }
   private:
      GQE::ImageAsset mImage;
      b2PolygonShape anShape; // Must be here o no lost the reference of the pointer 

};
#endif   // ----- #ifndef B2PROTO_INC  -----
