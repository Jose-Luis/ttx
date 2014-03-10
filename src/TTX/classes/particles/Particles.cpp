#include<TTX/classes/particles/Particles.hpp>
#include<iostream>

void Particles::updateRender(RenderManager& theRenderManager)
{
   for(auto it = getParticlesBegin(); it != getParticlesEnd(); it++)
   {
      mpe::Vec2 anPosition = it->getPosition();
      mpe::TextRect anTexRect = it->getTextRect();
      mpe::Color anColor = it->getColor();
      
      sf::Transform anTransform;
      LayerID anLayerID = getParticleLayer(*it);

      anTransform.translate(anPosition.getX() * getXFactor(), anPosition.getY() * getYFactor());
      anTransform.rotate(it->getAngle());
      anTransform.scale(it->getSize(),it->getSize());

      sf::Vector2f anPositions[4];
      anPositions[0] = anTransform.transformPoint(sf::Vector2f(-(anTexRect.width / 2),-(anTexRect.height /2)));
      anPositions[1] = anTransform.transformPoint(sf::Vector2f( (anTexRect.width / 2),-(anTexRect.height /2)));
      anPositions[2] = anTransform.transformPoint(sf::Vector2f( (anTexRect.width / 2), (anTexRect.height /2)));
      anPositions[3] = anTransform.transformPoint(sf::Vector2f(-(anTexRect.width / 2), (anTexRect.height /2)));

      sf::Vector2f anTexCoords[4];
      anTexCoords[0] = sf::Vector2f(anTexRect.x,                    anTexRect.y);
      anTexCoords[1] = sf::Vector2f(anTexRect.x + anTexRect.width-1,anTexRect.y);
      anTexCoords[2] = sf::Vector2f(anTexRect.x + anTexRect.width-1,anTexRect.y + anTexRect.height-1);
      anTexCoords[3] = sf::Vector2f(anTexRect.x,                    anTexRect.y + anTexRect.height-1);

      for (int i = 0; i < 4;i++)
      {
         theRenderManager.addVertex(anLayerID,sf::Vertex(anPositions[i], sf::Color(anColor.r,anColor.g,anColor.b,anColor.a) ,anTexCoords[i]));
      }
   }
}

LayerID Particles::getParticleLayer(const mpe::Particle& theParticle)
{
   if(theParticle.belongToGroup(mpe::GROUP_A | mpe::GROUP_B | mpe::GROUP_C | mpe::GROUP_D))
      return "Par1";
   else
      return "Par2";
}
