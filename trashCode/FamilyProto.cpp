/// @file HealthProto.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/components/FamilyProto.hpp>

FamilyProto::FamilyProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID)
{
   mProperties.add<EntityID>("Name", "");
   mProperties.add<GQE::IEntity*>("Parent", 0);
   mProperties.add<ChildrenContainer>("Children", ChildrenContainer());
   mProperties.add<bool>("Independent", false);

   mSystemIDs.push_back("FamilySystem");
}

