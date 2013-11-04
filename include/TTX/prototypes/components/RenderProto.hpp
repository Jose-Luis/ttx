/// @file RenderProto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  RENDERPROTO_INC
#define  RENDERPROTO_INC

#include <SFML/Graphics.hpp>
#include <GQE/Entity/classes/Prototype.hpp>

//Forward declarations
class b2Body;

/// @brief : 
//
class RenderProto: virtual public GQE::Prototype
{

   public:

      RenderProto(GQE::typePrototypeID theID);

   private:
};

#endif   // ----- #ifndef RENDERPROTO_INC  -----
