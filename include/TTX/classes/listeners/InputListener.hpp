#ifndef INPUTLISTENER_INC
#define INPUTLISTENER_INC

#include <TTX/Types.hpp>

class Input;

class InputListener
{
   public:

      virtual ~InputListener();
      virtual void update(Input::Data) = 0;
      Input* getInput();
      void setInput(Input* theInput);
      void drop();

   private:

      Input* mInput;
};

#endif
