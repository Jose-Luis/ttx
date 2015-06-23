#ifndef IACTIONSTATE_M3AYKRER
#define IACTIONSTATE_M3AYKRER

#include <Box2D/Box2D.h>
#include <GQE/Core/utils/CRC32.hpp>
#include <GQE/Core/interfaces/IState.hpp>
#include <GQE/Entity/classes/PrototypeManager.hpp>
#include <GQE/Entity/classes/Prototype.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <TTX/Definition.hpp>
#include <TTX/Types.hpp>
#include <TTX/systems/ISystem.hpp>
#include <TTX/classes/render/RenderManager.hpp>
#include <TTX/classes/particles/Particles.hpp>

class IActionState : public GQE::IState
{
public:
   IActionState(GQE::typeStateID theStateID, GQE::IApp& theApp);

   virtual ~IActionState(void);

   GQE::Instance* addInstance(GQE::typePrototypeID thePrototype,
                              Position2D           thePosition,
                              Position2D           theInitialImpulse = Position2D(0, 0, 0));
   GQE::IEntity* addPlayer(int                  theJoy,
                           GQE::typePrototypeID thePrototype,
                           Position2D           thePosition);

   void deactivateEntity(GQE::IEntity* theEntity);

   void activeEntity(GQE::IEntity* theEntity);
   void attachEntities(GQE::IEntity* theFather,GQE::IEntity* theChild,GQE::typePropertyID theChildName);
   Particles& getParticles();


protected:   //Members

   GQE::PrototypeManager mPrototypes;
   PlayerContainer       mPlayers;
   RenderManager         mRenderManager;
   Particles             mParticles;
   b2World               mWorld;
};

#endif 

