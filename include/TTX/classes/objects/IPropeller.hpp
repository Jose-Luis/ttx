#ifndef  IPROPELLER_INC
#define  IPROPELLER_INC

#include <TTX/Types.hpp>

class IPropeller
{
public:

   IPropeller() {};
   virtual ~IPropeller() {};

   /// @brief impulse
   /// @param theDirection
  virtual void impulse(MoveData theDirection) = 0;
   /// @brief setLinearPower
   /// @param theLinearPower
};
#endif   // ----- #ifndef PROPELLER_INC  -----
