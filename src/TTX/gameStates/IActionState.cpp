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
{
    for (auto anSystem : mSystems)
    {
        delete anSystem.second;
    }
}

GQE::Instance* IActionState::addInstance(GQE::typePrototypeID thePrototype,
        Position2D           thePosition,
        Position2D           theInitialImpulse)

{
    //Getting the prototype and creating the instance.
    GQE::Prototype* anPrototype = mPrototypes.getPrototype(thePrototype);
    GQE::Instance* anInstance = anPrototype->makeInstance();
    //Setting the posiion to the instance.
    anInstance->mProperties.set<Position2D>("Position", thePosition);
    anInstance->mProperties.add<Position2D>("InitialImpulse", theInitialImpulse);

    //Adding the instance to the systems.
    for(auto anSystem :  anPrototype->mSystemIDs)
    {
        mSystems[anSystem]->addEntity(anInstance);
    }

    return anInstance;
}

GQE::IEntity* IActionState::addPlayer(int                  theJoy,
        GQE::typePrototypeID thePrototype,
        Position2D           thePosition)
{
    GQE::IEntity* aPlayer = 0;
    GQE::IEntity* anActor = 0;

    if(mPlayers.find(theJoy) == mPlayers.end())
    {
        aPlayer = mPrototypes.getPrototype("Player")->makeInstance();
        anActor = addInstance(thePrototype,thePosition);
        aPlayer->mProperties.set<GQE::IEntity*>("Actor",anActor);
        aPlayer->mProperties.set<int>("Joystick", theJoy);
        anActor->mProperties.add<GQE::IEntity*>("Player",aPlayer);
        GQE::typeEntityID anPlayerID = mSystems["PlayerSystem"]->addEntity(aPlayer);
        mSystems["ActorSystem"]->addEntity(anActor);
        mPlayers.insert(std::pair<int, GQE::typeEntityID>(theJoy, anPlayerID));
    }

    return aPlayer;
}

void IActionState::addSystem(ISystem* theSystem)
{
    if(theSystem != NULL)
    {
        mSystems[theSystem->getID()] = theSystem;
    }
    else
    {
        ELOG() << "SystemManager::addSystem() Null pointer provided!" << std::endl;
    }
}

