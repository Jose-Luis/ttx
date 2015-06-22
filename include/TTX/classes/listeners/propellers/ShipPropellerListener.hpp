#ifndef SHIP_PROPELLER_LISTENER_INC
#define SHIP_PROPELLER_LISTENER_INC

#include <Box2D/Box2D.h>
#include <TTX/classes/listeners/EntityInputListener.hpp>

class ShipPropellerListener: public EntityInputListener
{
   virtual void update(Input::Data theInputData);
   virtual ShipPropellerListener* clone(); 
};

#endif
