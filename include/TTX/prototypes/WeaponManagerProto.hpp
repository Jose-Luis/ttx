#ifndef  WEAPON_MANAGER_PROTO_INC
#define  WEAPON_MANAGER_PROTO_INC

#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>

class WeaponManagerProto:
{

public:

   WeaponManagerProto():
   {
      mProperties.add<Entity*>(ACTOR, 0);
      mProperties.add<WeaponManagerListener>(INPUT_LISTENER, WeaponManagerListener());
   }
};

#endif   // ----- #ifndef PBOX_INC  ----- 
