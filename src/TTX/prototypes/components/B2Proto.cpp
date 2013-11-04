#include <TTX/prototypes/components/B2Proto.hpp>

B2Proto::B2Proto(GQE::typePrototypeID theID):
         GQE::Prototype(theID)
{
   mProperties.add<b2BodyDef*>("b2BodyDef",&mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>("b2FixturesDef",&mFixturesDef);
   mSystemIDs.push_back("B2System");
}
