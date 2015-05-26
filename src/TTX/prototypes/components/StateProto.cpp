#include <TTX/prototypes/components/StateProto.hpp>

StateProto::StateProto(GQE::typePrototypeID thePrototypeID):
   GQE::Prototype(thePrototypeID)
{
   mProperties.add<std::map<std::string,Animation> ("Animations",&mAnimations);
   this->mSystemIDs.push_back("StateSystem");
}
