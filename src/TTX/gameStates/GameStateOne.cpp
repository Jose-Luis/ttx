/**
 * @brief Provides the GameStateOne.
 * @file GameStateOne.cpp
 * @author Jose Luis Lavado
 * @date 2013-04-22 Created
 */
#include <TTX/gameStates/GameStateOne.hpp>
#include <TTX/classes/physics/CollisionListener.hpp>
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  constructor
// Description:
//------------------------------------------------------------------------------
GameStateOne::GameStateOne(GQE::IApp& theApp):
   IActionState("State1", theApp)
{
#ifndef NDEBUG
   mStatManager.registerApp(&mApp);
#endif
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  deconstructor
// Description:
//------------------------------------------------------------------------------
GameStateOne::~GameStateOne(void)
{
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  doInit
// Description:
//------------------------------------------------------------------------------
void GameStateOne::doInit(void)
{
   // First call our base class implementation
   IState::doInit();
   //Assets
#ifndef NDEBUG
      mStatManager.doInit();
      mStatManager.setShow(true);
#endif
   sf::Texture* anSpriteTexture =
      mApp.mAssetManager.getHandler<sf::Texture>().
      getReference("resources/Sprites.png",
                   GQE::AssetLoadNow,
                   GQE::AssetLoadFromFile,
                   GQE::AssetDropAtZero);
   sf::Texture* anTileTexture =
      mApp.mAssetManager.getHandler<sf::Texture>().
      getReference("resources/Tiles1.png",
                   GQE::AssetLoadNow,
                   GQE::AssetLoadFromFile,
                   GQE::AssetDropAtZero);

   mApp.mAssetManager.loadAllAssets();
   //Prototypes
   auto boxProto = new Box();
   auto basicShipProto = new BasicShip();
   auto simpleBulletProto = new SimpleBullet();
   auto playerProto = new Player();
   auto machinegunProto = new Machinegun();
   
   mRenderSystem = new RenderSystem(*this, mRenderManager, LENGTHFACTOR);
   mPlayerSystem = new PlayerSystem(*this, mView, LENGTHFACTOR);
   mPropellerSystem = new PropellerSystem(*this, mParticles);
   mPhysicSystem = new PhysicSystem(*this, mWorld);
   mAnimationSystem = new AnimationSystem(*this);
   mHealthSystem = new HealthSystem(*this);
   mActorSystem = new ActorSystem(*this);

   playerProto->addSystem(mPlayerSystem);
   
   machinegunProto->addSystem(mRenderSystem); 
   machinegunProto->addSystem(mHealthSystem); 
   machinegunProto->addSystem(mPhysicSystem); 

   simpleBulletProto->addSystem(mRenderSystem); 
   simpleBulletProto->addSystem(mHealthSystem); 
   simpleBulletProto->addSystem(mPhysicSystem); 

   basicShipProto->addSystem(mRenderSystem); 
   basicShipProto->addSystem(mActorSystem); 
   basicShipProto->addSystem(mHealthSystem); 
   basicShipProto->addSystem(mPhysicSystem); 
   basicShipProto->addSystem(mPropellerSystem); 

   boxProto->addSystem(mRenderSystem); 
   boxProto->addSystem(mAnimationSystem); 
   boxProto->addSystem(mHealthSystem); 
   boxProto->addSystem(mPhysicSystem); 

   mPrototypes.addPrototype(boxProto);
   mPrototypes.addPrototype(basicShipProto);
   mPrototypes.addPrototype(simpleBulletProto);
   mPrototypes.addPrototype(playerProto);
   mPrototypes.addPrototype(machinegunProto);

   //RenderUnits                      
   mRenderManager.addLayer("Back", anTileTexture);
   mRenderManager.addLayer("Fore", anTileTexture);
   mRenderManager.addLayer("Obj1", anSpriteTexture);
   mRenderManager.addLayer("Par1", anSpriteTexture);

   mRenderManager.getLayer("Obj1").mUpdatable = true;
   mRenderManager.getLayer("Par1").mUpdatable = true;
   mRenderManager.getLayer("Back").mUpdatable = false;
   mRenderManager.getLayer("Fore").mUpdatable = false;
   //Update Rate
   mApp.setUpdateRate(UPDATE_RATE);
   mApp.mWindow.setView(mView);
   mView.setRotation(0);
   //Others
   mParticles.setSize(1024);
   mParticles.setXFactor(16);
   mParticles.setYFactor(16);
   mParticles.initFromFile("resources/Particles.xml");
   //MapLoader
   MapLoader anMapLoader("resources/map1.tmx");
   anMapLoader.loadTiles(mRenderManager);
   anMapLoader.loadShapes(mWorld);
   mCollisionListener = new CollisionListener();
   mWorld.SetContactListener(mCollisionListener);
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  reInit
// Description:
//------------------------------------------------------------------------------
void GameStateOne::reInit(void)
{
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  handleEvents
// Description:
//------------------------------------------------------------------------------
void GameStateOne::handleEvents(sf::Event theEvent)
{
   // Exit program if Escape key is pressed

   if((theEvent.type == sf::Event::KeyReleased) &&
         (theEvent.key.code == sf::Keyboard::Escape))
   {
      // Signal the application to exit
      mApp.quit(GQE::StatusAppOK);
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
           (theEvent.key.code == sf::Keyboard::Space))
   {
      //Position2D anPos(rand()%40,0,rand()%3);
      //addInstance("pBox", Position2D(rand() % 4, 16, rand() % 3), Position2D(3, 3, 0));
      addInstance("Box", Position2D(4, 16, rand() % 3), Position2D(0, 0, 0));
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
           (theEvent.key.code == sf::Keyboard::B))
   {
      //Position2D anPos(rand()%40,0,rand()%6);
      addInstance("pRombo", Position2D(rand() % 40, 0, rand() % 6));
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
           (theEvent.key.code == sf::Keyboard::A))
   {
      if(mPlayer)
      {
         GQE::Prototype* prototype = mPrototypes.getPrototype("Machinegun");
         prototype->mProperties.add<GQE::IEntity*>("FatherNode", mPlayer->mProperties.get<GQE::IEntity*>("Actor"));
         prototype->mProperties.set<GQE::typePropertyID>("AnchorPoint", "WeaponAnchorLeft");
         prototype->makeInstance();
         prototype->mProperties.set<GQE::typePropertyID>("AnchorPoint", "WeaponAnchorRight");
         prototype->makeInstance();
      }

   }
   else
   {
      for(int i = 0; i < 8; i++)
      {
         if(sf::Joystick::isConnected(i) && sf::Joystick::isButtonPressed(i, 0))
            if(!mPlayer)
            {
               this->mPlayer = addPlayer(i, "BasicShip", Position2D(4, 16, 90 * TORAD));
            }
      }
   }
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  UpdateSelected
// Description:
//------------------------------------------------------------------------------
void GameStateOne::updateSelected(sf::Event theEvent)
{
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  updateFixed
// Description:
//------------------------------------------------------------------------------
void GameStateOne::updateFixed(void)
{
   mRenderManager.clear();
   mPhysicSystem->updateFixed();
   mPlayerSystem->updateFixed();
   mPropellerSystem->updateFixed();
   mHealthSystem->updateFixed();
   mAnimationSystem->updateFixed();
   mRenderSystem->updateFixed();
   mParticles.update(SPU);
   mParticles.updateRender(mRenderManager);
#ifndef NDEBUG
   mStatManager.updateFixed();
#endif
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  updateVariable
// Description:
//------------------------------------------------------------------------------
void GameStateOne::updateVariable(float theElapsedTime)
{
}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
//      Method:  draw
// Description:
//------------------------------------------------------------------------------
void GameStateOne::draw(void)
{
   mApp.mWindow.clear();
   mRenderManager.drawLayer("Back", mApp.mWindow);
   mRenderManager.drawLayer("Par1", mApp.mWindow);
   mRenderManager.drawLayer("Obj1", mApp.mWindow);
   mRenderManager.drawLayer("Fore", mApp.mWindow);
   mRenderManager.drawLayer("HUD", mApp.mWindow);
#ifndef NDEBUG
   mStatManager.draw();
#endif
}




//------------------------------------------------------------------------------
// Class:  GameStateOne
// Method:  handleCleanup
// Description:
//------------------------------------------------------------------------------
void GameStateOne::handleCleanup(void)
{
}
