/**
 * Provides the SpaceDots GameState example in the GQE library.
 *
 * @file src/IActionState.cpp
 * @author Ryan Lindeman
 * @date 20120323 - Initial Release
 * @date 20120421 - Make sure SFML 2 doesn't use its default font since it will crash on exit
 * @date 20120512 - Use new RAII Asset style
 */
#ifndef IACTIONSTATE_M3AYKRER
#define IACTIONSTATE_M3AYKRER

#include <Box2D/Box2D.h>
#include <GQE/Core/interfaces/IState.hpp>
#include <GQE/Entity/classes/PrototypeManager.hpp>
#include <GQE/Entity/classes/Prototype.hpp>
#include <GQE/Entity/classes/Instance.hpp>
#include <TTX/Types.hpp>
#include <TTX/systems/ISystem.hpp>
#include <TTX/classes/render/RenderManager.hpp>
#include <TTX/classes/particles/Particles.hpp>

class IActionState : public GQE::IState
{
public:
    /**
     * @brief IActionState constructor
     * @param[in] theApp is a pointer to the App class.
     */
    IActionState(GQE::typeSystemID theSystemID,GQE::IApp& theApp);

    /**
     * @brief IActionState deconstructor
     */
    virtual ~IActionState(void);
    /**
     * @brief addInstance
     * @param thePrototype
     * @param thePosition
     * @return
     */
    GQE::Instance* addInstance(GQE::typePrototypeID thePrototype,
                               Position2D           thePosition,
                               Position2D           theInitialImpulse = Position2D(0,0,0));
    /**
     * @brief addPlayer
     * @param theJoy
     * @param thePrototype
     * @param thePosition
     */
    void addPlayer(int                  theJoy,
                   GQE::typePrototypeID thePrototype,
                   Position2D           thePosition);
    /**
     * @brief addChild 
     * @param theFather
     * @param theChild
     * @param theName
     */
    void addChild(GQE::Instance* theFather,
                  GQE::Instance* theChild,
                  GQE::PropertyID theChildName);
    /**
     * @brief addSystem
     * @param theSystem
     */
    void addSystem(ISystem* theSystem);
    /// @brief addSystem 
    /// @param theSystem
    ISystem* getSystem(SystemID theSystem);
    /// @brief addPrototype 
    /// @param theProto
    void addPrototype(GQE::Prototype* theProto);
 
    void addParticleFocus(Position2D,mpe::EmitterID);

protected:   //Members

    GQE::PrototypeManager mPrototypes;
    SystemContainer       mSystems;
    PlayerContainer       mPlayers;
    RenderManager         mRenderManager;
    Particles             mParticles;
    b2World               mWorld;
};

#endif /* end of include guard: IACTIONSTATE_M3AYKRER */

/**
 * @class IActionState
 */
