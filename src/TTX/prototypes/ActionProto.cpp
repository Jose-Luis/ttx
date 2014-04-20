#include<TTX/prototypes/ActionProto.hpp>

//-------------------------------------------------------------
//  Class:       ActionProto 
//  Method:       MethodName
//  Description:  Description
// ------------------------------------------------------------
ActionProto::ActionProto (GQE::typePrototypeID theID, IActionState& theState ) : 
   Prototype (theID),
   mActionState(theState)
{
   mProperties.add<b2BodyDef*>("b2BodyDef",&mBodyDef);
   mProperties.add<std::vector<b2FixtureDef>*>("b2FixturesDef",&mFixturesDef);
   addSystem(theState.getSystem("B2System"));
   
   mProperties.add<sf::Vector2f>  ("vPosition",sf::Vector2f(0,0));
   mProperties.add<float>         ("fAngle",0);
   mProperties.add<b2Body*>       ("b2Body",0);
   mProperties.add<sf::IntRect>  ("rTexRect",sf::IntRect(0,0,0,0));
   mProperties.add<bool>          ("bVisible", true);
   addSystem(theState.getSystem("RenderSystem"));
   
   mProperties.add<float>("Resistance",0);
   mProperties.add<float>("Health",0);
   mProperties.add<IDead*>("Dead",nullptr);
   addSystem(theState.getSystem("HealthSystem"));
   
   
}
