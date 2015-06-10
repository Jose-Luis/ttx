/**
 * Provides the SpaceDots GameState example in the GQE library.
 *
 * @file src/IActionState.cpp
 * @author Ryan Lindeman
 * @date 20120323 - Initial Release
 * @date 20120421 - Make sure SFML 2 doesn't use its default font since it will crash on exit
 * @date 20120512 - Use new RAII Asset style
 */
#include <TTX/gameStates/IActionState.hpp>

IActionState::IActionState(GQE::typeStateID theStateID, GQE::IApp& theApp):
    GQE::IState(theStateID, theApp),
    mWorld(b2Vec2(0.0f, 0.0f))
{
    mWorld.SetAllowSleeping(true);
}

IActionState::~IActionState()
{}

GQE::Instance* IActionState::addInstance(GQE::typePrototypeID thePrototype,
                                         Position2D           thePosition,
                                         Position2D           theInitialImpulse)
{
    GQE::Prototype* prototype = mPrototypes.getPrototype(thePrototype);
    prototype->mProperties.add<Position2D>("Position", thePosition);
    prototype->mProperties.add<Position2D>("InitialImpulse", theInitialImpulse);

    return prototype->makeInstance();
}

GQE::IEntity* IActionState::addPlayer(int                  theJoy,
        GQE::typePrototypeID thePrototype,
        Position2D           thePosition)
{
    GQE::IEntity* player = 0;
    GQE::IEntity* actor = 0;

    if(mPlayers.find(theJoy) == mPlayers.end())
    {
        player = mPrototypes.getPrototype("Player")->makeInstance();
        GQE::Prototype* actorProto = mPrototypes.getPrototype(thePrototype);
        actorProto->mProperties.add<Position2D>("Position", thePosition);
        actor = actorProto->makeInstance();

        player->mProperties.set<GQE::IEntity*>("Actor",actor);
        player->mProperties.set<int>("Joystick", theJoy);
        actor->mProperties.set<GQE::IEntity*>("Player",player);
    }

    return player;
}
