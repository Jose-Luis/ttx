/**
 * @file RenderManager.hpp
 * @brief A class for group the render utilities
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-24
 */
#ifndef RENDERMANAGER_YJUY1HTM
#define RENDERMANAGER_YJUY1HTM

#include <TTX/classes/render/Layer.hpp>
#include <map>

class RenderManager
{
public:
   /**
    * @brief RenderManager
    * @param theWindow
    */
   RenderManager() {};
   /**
    * @brief ~RenderManager
    */
   ~RenderManager () {};
   /**
    * @brief addLayer
    * @param theID
    * @param theTexture
    */
   void addLayer(LayerID theID, sf::Texture* theTexture)
   {
      Layer anLayer(theID, theTexture);
      mLayers.insert(std::pair<LayerID, Layer>(theID, anLayer));
   }
   /**
    * @brief drawLayer
    * @param theID
    */
   void drawLayer(LayerID theID, sf::RenderWindow& theRenderWindow)
   {
      mLayers[theID].draw(theRenderWindow);
   }
   /**
    * @brief getLayerVertices
    * @param theID
    * @return
    */
   Layer& getLayer(LayerID theID)
   {
      return mLayers[theID];
   }
   /**
    * @brief addVertex
    * @param theID
    * @param theVertex
    */
   void addVertex(LayerID theID, const sf::Vertex& theVertex)
   {
      mLayers[theID].mVertices.append(theVertex);
   }
   /**
    * @brief clear
    */
   void clear()
   {
      std::map<LayerID, Layer>::iterator anIter;

      for (anIter = mLayers.begin(); anIter != mLayers.end(); anIter++)
      {
         if(anIter->second.mUpdatable == true)
         {
            anIter->second.mVertices.clear();
         }
      }
   }
private:
   std::map<LayerID, Layer> mLayers;

};
#endif /* end of include guard: RENDERUNIT_YJUY1HTM */
