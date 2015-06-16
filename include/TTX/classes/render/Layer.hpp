
/**
 * @file Layer.hpp
 * @brief A class for group the render utilities
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-24
 */
#ifndef LAYER_E0A1ST95
#define LAYER_E0A1ST95

#include <TTX/Types.hpp>
#include <SFML/Graphics.hpp>
#include <string>

struct Layer
{

   Layer() {};

   Layer(Id theID, sf::Texture* theTexure)
   {
      mID = theID;
      mVertices.setPrimitiveType(sf::Quads);
      mStates.texture = theTexure;
   }

   ~Layer () {};

   void draw(sf::RenderWindow& theWindow)
   {
      theWindow.draw(mVertices, mStates);
   }

   Id mID;
   bool mUpdatable;
   bool mVisible;
   sf::VertexArray mVertices;
   sf::RenderStates mStates;

};
#endif
