/// @file Propeller.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-02-26

#include <Box2D/Box2D.h>
#include <MPE/MPE.hpp>
#include <GQE/Entity/interfaces/IEntity.hpp>
#include <TTX/Types.hpp>

#ifndef  PROPELLER_INC
#define  PROPELLER_INC

class Propeller
{
   public:

      Propeller();                   
      ~Propeller();                   

      /// @brief impulse 
      /// @param theDirection
      void impulse(MoveData theDirection);
      /// @brief setLinearPower 
      /// @param theLinearPower
      void setLinearPower(float theLinearPower);
      /// @brief setTurnPower 
      /// @param theTurnPower
      void setTurnPower(float theTurnPower);
      /// @brief setFocus 
      /// @param theFocus
      void setFocus(mpe::FocusPtr theFocus);
      /// @brief setBody 
      /// @param theBody
      void setBody(b2Body* theBody);
      /// @brief setInnerPosition 
      /// @param theInnerPosition
      void setInnerPosition(b2Vec2 theInnerPosition);
      /// @brief setEmitterID 
      /// @param theEmitterID
      void setEmitterID(mpe::EmitterID theEmitterID);
      /// @brief getEmitterID 
      /// @return 
      mpe::EmitterID getEmitterID();
      /// @brief switchOn 
      void switchOn();
      /// @brief switchOff 
      void switchOff();


   protected:
      bool           mOn;
      b2Body*        mBody;
      mpe::FocusPtr  mFocus;
      float          mLinearPower;
      float          mTurnPower;
      b2Vec2         mInnerPosition;
      mpe::EmitterID mEmitterID;
}; 
#endif   // ----- #ifndef PROPELLER_INC  -----
