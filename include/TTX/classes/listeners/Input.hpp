#ifndef INPUT_INC
#define INPUT_INC

#include <TTX/Types.hpp>

class InputListener;

class Input
{
   public:

      struct Data
      {
         Vec2D move;
         Vec2D fire;
         bool Afire,Bfire;
         bool changeNext,changePrevious;
         bool pivot,turn;
         bool pause,menu;
         float turbo;
      };

      void addListener(InputListener* theInputListener);
      void dropListener(InputListener* theInputListener);
      void setData(Data theData);
      void publish();


   private:

      std::set<InputListener*> mListeners;
      Data mData;
};

#endif
