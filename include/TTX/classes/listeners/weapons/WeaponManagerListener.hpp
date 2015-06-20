#ifndef WEAPONMANAGER_INC
#define WEAPONMANAGER_INC

#include <set>
#include <TTX/Types.hpp>
#include <TTX/Definition.hpp>
#include <TTX/classes/listeners/EntityInputListener.hpp>

class WeaponManagerListener: public EntityInputListener
{
public:

   WeaponManagerListener();

   virtual void update(Input::Data theData);

   void changeWeapon();

   void changeWeapon(WeaponID);

   void addWeapon(GQE::IEntity* theWeapon);

   void removeWeapon(WeaponID theWeapon);

   void removeWeapon(GQE::IEntity* theWeapon);

private:

   std::map<WeaponID,std::set<GQE::IEntity*>> mWeaponMap;
   WeaponID mActiveWeapon;
   Input* mInput;
};

#endif
