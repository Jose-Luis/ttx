#ifndef ENTITY_INPUTLISTENER_INC
#define ENTITY_INPUTLISTENER_INC

#include <TTX/classes/listeners/InputListener.hpp>
#include <TTX/gameStates/IActionState.hpp>

class EntityInputListener: public InputListener
{
   public:
      virtual void update(Input::Data theInput) = 0;
      virtual EntityInputListener* clone() = 0;
      virtual void init() = 0;

      void setEntity(Entity* theEntity){mEntity = theEntity;}
      void setState(IActionState* theState){mState = theState;}

   protected:

      Entity* mEntity;
      IActionState* mState;
};
#endif
