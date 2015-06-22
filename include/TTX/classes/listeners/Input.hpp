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

         Data():
            move(0,0),
            fire(0,0),
            Afire(false),
            Bfire(false),
            changeNext(false),
            changePrevious(false),
            pivot(false),
            turn(false),
            pause(false),
            menu(false),
            turbo(false)
         {}

      };

      void addListener(InputListener* theInputListener);
      void dropListener(InputListener* theInputListener);
      void setData(Data theData);
      void publish();


   private:

      std::forward_list<InputListener*> mListeners;
      Data mData;
};

#endif
