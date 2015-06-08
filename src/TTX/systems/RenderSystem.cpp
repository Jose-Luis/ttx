/// @file RenderSystem.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-02

#include <TTX/systems/RenderSystem.hpp>

RenderSystem::RenderSystem(IActionState& theState,
                           RenderManager& theRenderManager,
                           float theFactor):
   ISystem("RenderSystem", theState),
   mRenderManager(theRenderManager),
   mFactor(theFactor)
{
   //mStates.texture = mApp.mAssetManager.getHandler<sf::Texture>().getReference("resources/Sprites.png");
   //mVertices.setPrimitiveType(sf::Quads);
   //mShader.loadFromFile("resources/wave.vert", "resources/blur.frag");
   //mStates.shader = &mShader;
}

RenderSystem::~RenderSystem()
{}

void RenderSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<Position2D>  ("Position", Position2D(0, 0, 0));
   theEntity->mProperties.add<sf::Vector2f>  ("vScale", sf::Vector2f(1, 1));
   theEntity->mProperties.add<sf::IntRect>  ("rTexRect", sf::IntRect(0, 0, 0, 0));
   theEntity->mProperties.add<bool>          ("bVisible", true);
   theEntity->mProperties.add<LayerID>       ("rLayerID", "Obj1");
}

void RenderSystem::handleInit(GQE::IEntity* theEntity)
{}

void RenderSystem::handleEvents(sf::Event theEvent)
{}

void RenderSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();

   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

      while(anQueue != anIter->second.end())
      {
         GQE::IEntity* anEntity = *anQueue;

         if(anEntity->mProperties.get<bool>("bVisible"))
         {
            Position2D anPosition = anEntity->mProperties.get<Position2D>("Position") * mFactor;
            sf::Vector2f anScale    = anEntity->mProperties.get<sf::Vector2f>("vScale");
            sf::IntRect anTexRect  = anEntity->mProperties.get<sf::IntRect>("rTexRect");
            LayerID  anLayerID  = anEntity->mProperties.get<LayerID>("rLayerID");

            sf::Transform anTransform;

            anTransform.translate(sf::Vector2f(anPosition.x, anPosition.y)).rotate(anPosition.angle).scale(anScale);
            //anTransform.translate(anPosition);

            sf::Vector2f anPositions[4];
            anPositions[0] = anTransform.transformPoint(sf::Vector2f(-(anTexRect.width / 2), -(anTexRect.height / 2)));
            anPositions[1] = anTransform.transformPoint(sf::Vector2f( (anTexRect.width / 2), -(anTexRect.height / 2)));
            anPositions[2] = anTransform.transformPoint(sf::Vector2f( (anTexRect.width / 2), (anTexRect.height / 2)));
            anPositions[3] = anTransform.transformPoint(sf::Vector2f(-(anTexRect.width / 2), (anTexRect.height / 2)));

            sf::Vector2f anTexCoords[4];
            anTexCoords[0] = sf::Vector2f(anTexRect.left,                   anTexRect.top);
            anTexCoords[1] = sf::Vector2f(anTexRect.left + anTexRect.width, anTexRect.top);
            anTexCoords[2] = sf::Vector2f(anTexRect.left + anTexRect.width, anTexRect.top + anTexRect.height);
            anTexCoords[3] = sf::Vector2f(anTexRect.left,                   anTexRect.top + anTexRect.height);

            for (int i = 0; i < 4; i++)
            {
               mRenderManager.addVertex(anLayerID, sf::Vertex(anPositions[i], sf::Color(255, 255, 255, 255), anTexCoords[i]));
            }
         }

         anQueue++;
      }

      anIter++;
   }
}

void RenderSystem::updateVariable(float theElapsedTime)
{}

void RenderSystem::draw()
{
}

void RenderSystem::handleCleanup(GQE::IEntity* theEntity)
{}
sf::IntRect RenderSystem::mDummyRect = sf::IntRect(0, 0, 0, 0);
