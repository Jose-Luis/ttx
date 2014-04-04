#include <TTX/prototypes/components/B2Proto.hpp>

B2Proto::B2Proto(GQE::typePrototypeID theID,IActionState& theState):
         GQE::Prototype(theID)
{
   mProperties.add<b2BodyDef*>("b2BodyDef",&mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>("b2FixturesDef",&mFixturesDef);
   this->addSystem(theState.getSystem("B2System"));
}
