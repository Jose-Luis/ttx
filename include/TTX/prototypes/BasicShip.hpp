
#ifndef  PTRIANGLE_INC
#define  PTRIANGLE_INC

#include <TTX/prototypes/components/B2Proto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/classes/objects/Propeller.hpp>
#include <TTX/classes/objects/Weapon.hpp>
#include <TTX/classes/actions/IDead.hpp>
#include <TTX/gameStates/IActionState.hpp>

class BasicShip: public B2Proto, public RenderProto, public HealthProto
{
public:

    BasicShip();

    class ShipDead:public IDead
    {
    public:
        virtual void execute(Position2D,IActionState&);
    };

private:

    b2PolygonShape  mShape1,mShape2,mShape3;
    ShipDead mDead;
};

#endif   // ----- #ifndef PBOX_INC  -----

