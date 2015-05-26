/// @file StateProto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  STATEPROTO_INC
#define  STATEPROTO_INC

#include <SFML/Graphics.hpp>
#include <TTX/classes/render/Animation.hpp>
#include <GQE/Entity/classes/Prototype.hpp>


class StateProto: virtual public GQE::Prototype
{

   public:

      StateProto(GQE::typePrototypeID theID);

   private:

      std::map<std::string,Animation> mAnimations;
};

#endif   // ----- #ifndef RENDERPROTO_INC  -----
