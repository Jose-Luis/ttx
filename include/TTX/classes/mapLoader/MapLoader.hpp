#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <TinyXML2/tinyxml2.h>
#include <fstream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <TTX/classes/render/RenderManager.hpp>
#include <TTX/Types.hpp>
#include <Box2D/Box2D.h>

class MapLoader
{
   //Loads the map. Returns false if it fails.
public:
   MapLoader(std::string theFileName);
   ~MapLoader();
   void loadTiles(RenderManager& theRenderManager);
   void loadShapes(b2World& theWorld);
private:
   tinyxml2::XMLDocument mMap;
};

#endif
