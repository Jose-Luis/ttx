/// @file RenderProto.cpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/components/RenderProto.hpp>

RenderProto::RenderProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mProperties.add<sf::Vector2f>  ("vPosition",sf::Vector2f(0,0));
   mProperties.add<float>         ("fAngle",0);
   mProperties.add<b2Body*>       ("b2Body",0);
   mProperties.add<sf::IntRect>  ("rTexRect",sf::IntRect(0,0,0,0));
   mProperties.add<bool>          ("bVisible", true);

   mSystemIDs.push_back("RenderSystem");
}
