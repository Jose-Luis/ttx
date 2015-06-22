#include <TTX/classes/listeners/Input.hpp>
#include <TTX/classes/listeners/InputListener.hpp>

void Input::addListener(InputListener* theInputListener)
{
    mListeners.push_front(theInputListener);
   theInputListener->setInput(this);
}

void Input::dropListener(InputListener* theInputListener)
{
   mListeners.remove(theInputListener);
}

void Input::publish()
{
   for(auto listener : mListeners)
   {
      listener->update(mData);
   }
}

void Input::setData(Data theData)
{
   mData = theData;
}

