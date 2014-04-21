/// @file HealthProto.cpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/components/HealthProto.hpp>

HealthProto::HealthProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mProperties.add<float>("Resistance",0);
   mProperties.add<float>("Health",0);
   mProperties.add<IDead*>("IDead",nullptr);

   mSystemIDs.push_back("HealthSystem");
}

