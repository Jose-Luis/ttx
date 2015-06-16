
#include <TTX/Types.hpp>
#include <TTX/prototypes/Player.hpp>

Player::Player():
   GQE::Prototype(PLAYER_PROTO)
{
   mProperties.add<int>(ID, -1);
   mProperties.add<int>(JOYSTICK, -1);
   mProperties.add<int>(POINTS, 0);
   mProperties.add<std::string>(PLAYER_NAME, "");
   mProperties.add<GQE::IEntity*>(ACTOR, 0);
}
