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

      virtual void impulse(b2Body* theBody,MoveData theDirection) = 0;
};
#endif
