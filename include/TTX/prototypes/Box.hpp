#ifndef  PBOX2_INC
#define  PBOX2_INC

#include <TTX/Types.hpp>
#include <TTX/prototypes/components/B2Proto.hpp>
#include <TTX/prototypes/components/RenderProto.hpp>
#include <TTX/prototypes/components/HealthProto.hpp>
#include <TTX/classes/render/Animation.hpp>
#include <TTX/classes/actions/IDead.hpp>

class Box: public B2Proto, public RenderProto, public HealthProto
{

public:

    Box();

    class BoxDead:public IDead
    {
       virtual void execute(Position2D,IActionState&);
    };


private:


    b2PolygonShape  mShape1;
    std::vector<sf::IntRect> mAnimation1;




};

#endif   // ----- #ifndef PBOX_INC  ----- 

