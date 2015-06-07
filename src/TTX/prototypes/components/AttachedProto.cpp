/// @file HealthProto.cpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01

#include <TTX/prototypes/components/AttachedProto.hpp>

AttachedProto::AttachedProto(GQE::typePrototypeID theID):
   GQE::Prototype(theID),
   B2Proto(theID)
{
   mProperties.add<Transform>("LocalTransform", Transform(0, 0, 0));
   mProperties.add<Transform>("Transform", Transform(0, 0, 0));
   mProperties.add<b2JointDef*>("JointDef", 0);
   mProperties.add<b2Joint*>("Joint", 0);
   mProperties.add<bool>("DirtyTransformBit", false);

   mSystemIDs.push_back("AttachSystem");
}

