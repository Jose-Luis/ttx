/**
 * @file Animation.hpp
 * @brief Animation class
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-29
 */
#ifndef ANIMATION_YL97FCUT
#define ANIMATION_YL97FCUT

#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:
   Animation() {};
   Animation( std::vector<sf::IntRect>* theRects):
      mFPS(8),
      mTime(0),
      mFrame(0),
      mSize(theRects->size())
   {
      mRects = theRects;
   }

   ~Animation() {};
   void update(float theTime)
   {
      mFrame = mFPS * mTime;

      if(mFrame > (mSize - 1))
      {
         if(mLoop)
         {
            mFrame = mFrame % mSize;
         }
         else
         {
            mFrame = mSize - 1;
         }
      }

      mTime += theTime;
   }

   void reset()
   {
      mTime = 0;
   }

   sf::IntRect getFrame()
   {
      return (*mRects)[mFrame];
   }


public:
   bool mLoop;
   float mFPS;

private:
   std::vector<sf::IntRect>* mRects;
   float mTime;
   int mFrame;
   int mSize;
};

//Animation::Animation()
//{
//}

//Animation::Animation(std::vector<sf::IntRect>* theRects):
//mFPS(8),
//mRects(theRects),
//mSize(theRects->size())
//{
//}

//void Animation::update(float theTime)
//{
//mFrame = mFPS * mTime;

//if(mFrame > (mSize - 1))
//{
//if(mLoop)
//mFrame = mFrame % mSize;
//else
//mFrame = mSize - 1;
//}
//mTime += theTime;
//}

//sf::IntRect Animation::getFrame()
//{
//return (*mRects)[mFrame];
//}

//void Animation::reset()
//{
//mTime = 0;
//}

#endif /* end of include guard: ANIMATION_YL97FCUT */
