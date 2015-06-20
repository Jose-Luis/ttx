#include <TTX/classes/listeners/Input.hpp>

void Input::addListener(InputListener* theInputListener)
{
   if( mListeners.insert(theInputListener).second )
      theInputListener->setInput(this);
}

void Input::dropListener(InputListener* theInputListener)
{
   mListeners.erase(theInputListener);
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

