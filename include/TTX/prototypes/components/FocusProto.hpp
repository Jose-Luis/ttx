/// @file FocusProto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-04-01


#ifndef  FOCUSPROTO_INC
#define  FOCUSPROTO_INC

#include <GQE/Entity/classes/Prototype.hpp>
#include <TTX/gameStates/IActionState.hpp>

class FocusProto: virtual public GQE::Prototype
{
   public:

      FocusProto(GQE::typePrototypeID theID,
                 mpe::EmitterID theEmitter,
                 IActionState& theState);

   protected:

      mpe::EmitterID mEmitter;
};

#endif   // ----- #ifndef FocusPROTO_INC  -----
