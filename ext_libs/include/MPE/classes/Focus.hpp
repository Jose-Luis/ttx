/// @file Focus.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-21

#ifndef  FOCUS_INC
#define  FOCUS_INC

#include <memory>
#include <MPE/Config.hpp>
#include <MPE/classes/Particle.hpp>

namespace mpe
{
class Focus: public Mortal
{
public:
   static FocusPtr create(const Emitter&  theEmitter);

   void update(Real theElapsedTime);
   Vec2 getPosition() const;
   void setPosition(Vec2 thePosition);
   Real getWidth() const;
   void setWidth(Real theWidth);
   Real getHeight() const;
   void setHeight(Real theHeight);
   Real getAngle() const;
   void setAngle(Real theAngle);
   void setPPS(Real thePPS);
   Real getPPS();
   void resetNP(Real theNP);
   void addGroups(GroupID theGroups);
   void removeGroups(GroupID theGroups);
   void removeFromAllGroups();

private:

   Focus(const Emitter&  theEmitter);
   void emit(Integer theNParticles);
   void initParticle();
   Integer drain(Real theElapsedTime);
   Particle createParticle();

   Real      mWidth; 
   Real      mHeight;
   Vec2      mPosition;
   Real      mAngle;
   Integer   mTP;  
   Integer   mEP; 
   Real      mPPS;
   Real      mTimeAcum;
   GroupID   mGroups;
   const Emitter&  mEmitter;
};
}
#endif
