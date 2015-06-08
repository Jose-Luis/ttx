
#include <TTX/Types.hpp>
#include <TTX/prototypes/Player.hpp>

Player::Player():
   GQE::Prototype("Player")
{
   mProperties.add<int>("ID", -1);
   mProperties.add<int>("Joystick", -1);
   mProperties.add<int>("Points", 0);
   mProperties.add<std::string>("Name", "");
   mProperties.add<GQE::IEntity*>("Actor", 0);
}
