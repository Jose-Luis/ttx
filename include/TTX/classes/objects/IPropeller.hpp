#ifndef  IPROPELLER_INC
#define  IPROPELLER_INC

#include <TTX/Types.hpp>

class b2Body;

class IPropeller
{
public:

   IPropeller() {};
   virtual ~IPropeller() {};
   virtual IPropeller* clone() = 0;

   /// @brief impulse
   /// @param theDirection
  virtual void impulse(b2Body* theBody,MoveData theDirection) = 0;
   /// @brief setLinearPower
   /// @param theLinearPower
};
#endif   // ----- #ifndef PROPELLER_INC  -----
