/// @file DestroyableProto.hpp
/// @brief 
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2014-03-31

#include <TTX/gameStates/IActionState.hpp>
#include <GQE/Entity/classes/Prototype.hpp>

class DestroyableProto: virtual public GQE::Prototype 
{
public:
   DestroyableProto ();
   virtual ~DestroyableProto ();

private:
   virtual void destroy(IActionState&)=0;
};
