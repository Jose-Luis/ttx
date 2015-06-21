#include <TTX/classes/listeners/InputListener.hpp>
#include <TTX/classes/listeners/Input.hpp>

Input* InputListener::getInput()
{
   return mInput;
}

InputListener::~InputListener()
{
   drop();
}

void InputListener::setInput(Input* theInput)
{
   mInput = theInput;
}

void InputListener::drop()
{
   if(mInput)
      mInput->dropListener(this);
}

