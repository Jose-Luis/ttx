/// @file Propeller.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-02-26

#include <Box2D/Box2D.h>
#include <MPE/MPE.hpp>
#include <GQE/Entity/interfaces/IEntity.hpp>
#include <TTX/Types.hpp>
#include <TTX/classes/objects/IPropeller.hpp>
#include <TTX/classes/particles/Particles.hpp>

#ifndef  PROPELLER_INC
#define  PROPELLER_INC

class Propeller : public IPropeller
{
public:

   Propeller(Particles& theSystem);
   virtual ~Propeller();

   virtual Propeller* clone();

   /// @brief impulse
   /// @param theDirection
   virtual void impulse(b2Body* theBody,MoveData theDirection);
   /// @brief setLinearPower
   /// @param theLinearPower
   void setLinearPower(float theLinearPower);
   /// @brief setTurnPower
   /// @param theTurnPower
   void setTurnPower(float theTurnPower);
   /// @brief setEmitterID
   /// @param theEmitterID
   void setEmitterID(mpe::EmitterID theEmitterID);
   /// @brief getEmitterID
   /// @return
   void setFocus(mpe::FocusPtr theFocus);
   mpe::EmitterID getEmitterID();
   /// @brief switchOn
   void switchOn();
   /// @brief switchOff
   void switchOff();


protected:
   bool           mOn;
   mpe::FocusPtr  mFocus;
   float          mLinearPower;
   float          mTurnPower;
   mpe::EmitterID mEmitterID;
   Particles&   mParticles;
};
#endif   // ----- #ifndef PROPELLER_INC  -----
