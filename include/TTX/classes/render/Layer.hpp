
/**
 * @file Layer.hpp
 * @brief A class for group the render utilities
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-24
 */
#ifndef LAYER_E0A1ST95
#define LAYER_E0A1ST95

#include <SFML/Graphics.hpp>
#include <string>

typedef std::string LayerID;

struct Layer 
{
   /**
    * @brief Layer 
    */
   Layer(){};
   /**
    * @brief Layer 
    * @param theID
    * @param theTexure
    */
   Layer(LayerID theID,sf::Texture* theTexure)
   {
      mID = theID;
      mVertices.setPrimitiveType(sf::Quads);
      mStates.texture = theTexure;
   }
   /**
    * @brief ~Layer 
    */
   ~Layer (){};
   /**
    * @brief draw 
    * @param theWindow
    */
   void draw(sf::RenderWindow& theWindow)
   {
      theWindow.draw(mVertices,mStates);
   }
   /****** Variables ******/
   LayerID mID;
   bool mUpdatable;
   bool mVisible;
   sf::VertexArray mVertices;
   sf::RenderStates mStates;

};
#endif /* end of include guard: LAYER_E0A1ST95 */
