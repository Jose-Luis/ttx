#ifndef SIMPLEWEAPONLISTENER_INC
#define SIMPLEWEAPONLISTENER_INC

#include <TTX/Definition.hpp>
#include <TTX/classes/listeners/Input.hpp>
#include <TTX/classes/listeners/EntityInputListener.hpp>

class SimpleWeaponListener: public EntityInputListener
{
   public:
      SimpleWeaponListener();
      virtual SimpleWeaponListener* clone();
      virtual void update(Input::Data theInput);
      virtual void init(){}
      void setAmmunitionType(AmunitionID theAmmu);
      void setCadency(float theCadency);
      void setPower(float thePower);

   private:
      AmunitionID   mAmunitionType;
      float         mCadency;
      float         mPower;
      float         mLastTime;
      int           mAmunition;
};
#endif
