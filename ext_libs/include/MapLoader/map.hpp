#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <map>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Map
{
   public:
      Map();
      virtual ~Map();
      //Loads the map. Returns false if it fails.
      bool loadFromFile(std::string filename);
      //Draws the map to the provided window.
      void draw(sf::RenderWindow &window);

   private:

      int mWidth, mHeight, mTileWidth, mTileHeight, mSpacing, mMargin, mFirstTileID;
      sf::Texture mTilesetTexture;
      sf::VertexArray mTilesVertex;
};

#endif 
