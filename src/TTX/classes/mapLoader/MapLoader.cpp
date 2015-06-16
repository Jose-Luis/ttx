#include <TTX/classes/mapLoader/MapLoader.hpp>
//------------------------------------------------------------------------------
//       Class:  MapLoader
//      Method:  loadMap
// Description:
//------------------------------------------------------------------------------
MapLoader::MapLoader(std::string theFileName)
{
   if (tinyxml2::XML_NO_ERROR != mMap.LoadFile(theFileName.c_str()))
   {
      std::cout << "Loading level \"" << theFileName << "\" failed." << std::endl;
   }
}
//------------------------------------------------------------------------------
//       Class:  MapLoader
//      Method:
// Description:  A stupid method
//------------------------------------------------------------------------------
MapLoader::~MapLoader ()
{
}
//------------------------------------------------------------------------------
//       Class:  MapLoader
//      Method:  loadTiles
// Description:
//------------------------------------------------------------------------------
void MapLoader::loadTiles( RenderManager& theRenderManager)
{

   tinyxml2::XMLElement* anMap = mMap.FirstChildElement("map");

   if (anMap == NULL)
   {
      return;
   }

   int anWidth, anHeight, anTileWidth, anTileHeight;

   //Set up misc anMap properties.
   anWidth      = anMap->IntAttribute("width");
   anHeight     = anMap->IntAttribute("height");
   anTileWidth  = anMap->IntAttribute("tilewidth");
   anTileHeight = anMap->IntAttribute("tileheight");

   //Layers
   tinyxml2::XMLElement* anLayer = anMap->FirstChildElement("layer");

   while (anLayer)
   {
      LayerID anLayerID = BACKGROUND;
      int anColumns = (theRenderManager.getLayer(anLayerID).mStates.texture->getSize().x) / anTileWidth;
      float anOpacity = anLayer->FloatAttribute("opacity");

      if (!anOpacity)
      {
         anOpacity = 1;
      }

      anOpacity *= 255;

      tinyxml2::XMLElement* layerDataElement = anLayer->FirstChildElement("data");

      if (layerDataElement == NULL)
      {
         std::cout << "Bad map. No layer information found." << std::endl;
         return;
      }

      tinyxml2::XMLElement* tileElement = layerDataElement->FirstChildElement("tile");

      if (tileElement == NULL)
      {
         std::cout << "Bad map. No tile information found." << std::endl;
         return;
      }

      int anX = 0;
      int anY = 0;

      while (tileElement)
      {
         int anTileGID = tileElement->IntAttribute("gid") - 1;

         if ( 0 <= anTileGID)
         {
            int anTextureX = anTileGID % anColumns;
            int anTextureY = anTileGID / anColumns;

            sf::Vector2f anPositions[4];
            anPositions[0] = sf::Vector2f((anX + 0) * anTileWidth, (anY + 0) * anTileHeight);
            anPositions[1] = sf::Vector2f((anX + 0) * anTileWidth, (anY + 1) * anTileHeight);
            anPositions[2] = sf::Vector2f((anX + 1) * anTileWidth, (anY + 1) * anTileHeight);
            anPositions[3] = sf::Vector2f((anX + 1) * anTileWidth, (anY + 0) * anTileHeight);

            sf::Vector2f anTexCoords[4];
            anTexCoords[0] = sf::Vector2f((anTextureX + 0) * anTileWidth, (anTextureY + 0) * anTileHeight);
            anTexCoords[1] = sf::Vector2f((anTextureX + 0) * anTileWidth, (anTextureY + 1) * anTileHeight);
            anTexCoords[2] = sf::Vector2f((anTextureX + 1) * anTileWidth, (anTextureY + 1) * anTileHeight);
            anTexCoords[3] = sf::Vector2f((anTextureX + 1) * anTileWidth, (anTextureY + 0) * anTileHeight);

            sf::Color anColor[4];
            anColor[0] = sf::Color(255, 255, 255, anOpacity);
            anColor[1] = sf::Color(255, 255, 255, anOpacity);
            anColor[2] = sf::Color(255, 255, 255, anOpacity);
            anColor[3] = sf::Color(255, 255, 255, anOpacity);

            for (int i = 0; i < 4; i++)
            {
               theRenderManager.addVertex(anLayerID, sf::Vertex(anPositions[i], anColor[i], anTexCoords[i]));
            }
         }

         tileElement = tileElement->NextSiblingElement("tile");
         //increment x, y
         anX++;

         if (anX >= anWidth)//if x has "hit" the end (right) of the map, reset it to the start (left)
         {
            anX = 0;
            anY++;

            if (anY >= anHeight)
            {
               anY = 0;
            }
         }
      }

      anLayer = anLayer->NextSiblingElement("layer");
   }

   return;
}
//------------------------------------------------------------------------------
//       Class:  MapLoader
//      Method:
// Description:  load the static shapes of the World
//------------------------------------------------------------------------------
void MapLoader::loadShapes (b2World& theWorld)
{
   tinyxml2::XMLElement* anMap = mMap.FirstChildElement("map");

   if (anMap == NULL)
   {
      return;
   }

   tinyxml2::XMLElement* anShapes = anMap->FirstChildElement("objectgroup");

   if (anShapes == NULL)
   {
      return;
   }

   while( strcmp(anShapes->Attribute("name"), "Shapes") != 0 )
   {
      anShapes = anShapes->NextSiblingElement("objectgroup");

      if(anShapes == NULL)
      {
         return;
      }
   }

   tinyxml2::XMLElement* anObject = anShapes->FirstChildElement("object");

   while (anObject)
   {
      int anX0 = anObject->IntAttribute("x");
      int anY0 = anObject->IntAttribute("y");
      tinyxml2::XMLElement* anPoints = anObject->FirstChildElement("polyline");

      const char* anCharPoint = anPoints->Attribute("points");
      const char* anCharPtr = strchr(anCharPoint, ',');
      char anCoor[10];
      int nPoints = 0;

      b2BodyDef anSceneDef;
      anSceneDef.type = b2_staticBody;
      b2Body* anScene = theWorld.CreateBody(&anSceneDef);

      while(anCharPtr != NULL)
      {
         nPoints++;
         anCharPtr = strchr(anCharPtr + 1, ',');
      }

      b2Vec2* anPointsArray = (b2Vec2*)malloc(nPoints * sizeof(b2Vec2));

      int anLength;
      int i;

      for (i = 0; i < nPoints - 1; i++)
      {
         anCharPtr = strchr(anCharPoint, ',');
         anLength = anCharPtr - anCharPoint;
         strncpy(anCoor, anCharPoint, anLength);
         anCoor[anLength] = '\0';
         anPointsArray[i].x = (atof(anCoor) + anX0) / 16;
         anCharPoint = anCharPtr + 1;
         anCharPtr = strchr(anCharPoint, ' ');
         anLength = anCharPtr - anCharPoint;
         strncpy(anCoor, anCharPoint, anLength);
         anCoor[anLength] = '\0';
         anPointsArray[i].y = (atof(anCoor) + anY0) / 16;
         anCharPoint = anCharPtr + 1;
      }

      anCharPtr = strchr(anCharPoint, ',');
      anLength =  anCharPtr - anCharPoint;
      strncpy(anCoor, anCharPoint, anLength);
      anCoor[anLength] = '\0';
      anPointsArray[i].x = (atof(anCoor) + anX0) / 16;
      anCharPoint = anCharPtr + 1;
      anPointsArray[i].y = (atof(anCharPoint) + anY0) / 16;

      b2FixtureDef anChainFixture;
      b2ChainShape anChainShape;
      anChainFixture.filter.categoryBits = ObjectCategories::SCENE;
      anChainFixture.filter.maskBits = ObjectCategories::ALL;
      anChainFixture.shape = & anChainShape;
      anChainShape.CreateChain(anPointsArray, nPoints);
      anScene->CreateFixture(&anChainFixture);

      anObject = anObject->NextSiblingElement("object");

   }


   return;
}
