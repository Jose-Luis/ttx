/// @file VehicleProto.cpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#ifndef  VEHICLEPROTO_INC
#define  VEHICLEPROTO_INC

#include <GQE/Entity/classes/Prototype.hpp>
#include <TTX/classes/propellers/Propeller.hpp>

class VehicleProto: virtual public GQE::Prototype 
{
   public:

      VehicleProto(GQE::typePrototypeID theID);
      void setPropellerModel(PropellerType theModel);
};

#endif   // ----- #ifndef VehiclePROTO_INC  -----
