#include <TTX/prototypes/components/VehicleProto.hpp>

VehicleProto::VehicleProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mProperties.add<PropellerType>("pPropellerType", NOPROPELLER); 
   mSystemIDs.push_back("PropellerSystem");
}

void VehicleProto::setPropellerModel(PropellerType theModel)
{
   mProperties.set("pPropellerType", theModel);
}
