/// @file HealthProto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  HEALTHPROTO_INC
#define  HEALTHPROTO_INC

#include <SFML/Graphics.hpp>
#include <GQE/Entity/classes/Prototype.hpp>
#include <TTX/classes/actions/IDead.hpp>


class HealthProto: virtual public GQE::Prototype
{

   public:

      HealthProto(GQE::typePrototypeID theID);

   private:
};

#endif   // ----- #ifndef RENDERPROTO_INC  -----
