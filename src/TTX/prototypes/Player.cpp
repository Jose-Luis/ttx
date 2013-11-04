
#include <TTX/Types.hpp>
#include <TTX/prototypes/Player.hpp>

Player::Player():
   GQE::Prototype("pPlayer")
{
   mProperties.add<int>("iID",-1);
   mProperties.add<int>("iJoystick",-1);
   mProperties.add<int>("iPoints",0);
   mProperties.add<std::string>("sName","");
   mProperties.add<GQE::Instance*>("gInstance",0);
}
