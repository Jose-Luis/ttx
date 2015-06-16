#include <TTX/gameStates/GameStateOne.hpp>

GameStateOne::GameStateOne(GQE::IApp& theApp):
   IActionState(STATE_1, theApp)
{
#ifndef NDEBUG
   mStatManager.registerApp(&mApp);
#endif
}

GameStateOne::~GameStateOne(void)
{}

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
   auto basicShipProto = new BasicShip(this);
   auto simpleBulletProto = new SimpleBullet();
   auto playerProto = new Player();
   auto machinegunProto = new Machinegun();
   auto shipPropellerProto = new ShipPropeller(mParticles);

   mRenderSystem = new RenderSystem(*this, mRenderManager, LENGTHFACTOR);
   mPlayerSystem = new PlayerSystem(*this, mView, LENGTHFACTOR);
   mPropellerSystem = new PropellerSystem(*this, mParticles);
   mPhysicSystem = new PhysicSystem(*this, mWorld);
   mAnimationSystem = new AnimationSystem(*this);
   mHealthSystem = new HealthSystem(*this);
   mActorSystem = new ActorSystem(*this);
   mWeaponSystem = new WeaponSystem(*this);

   playerProto->addSystem(mPlayerSystem);

   machinegunProto->addSystem(mRenderSystem);
   machinegunProto->addSystem(mHealthSystem);
   machinegunProto->addSystem(mPhysicSystem);
   machinegunProto->addSystem(mWeaponSystem);

   simpleBulletProto->addSystem(mRenderSystem);
   simpleBulletProto->addSystem(mHealthSystem);
   simpleBulletProto->addSystem(mPhysicSystem);

   shipPropellerProto->addSystem(mRenderSystem);
   shipPropellerProto->addSystem(mHealthSystem);
   shipPropellerProto->addSystem(mPhysicSystem);
   shipPropellerProto->addSystem(mPropellerSystem);

   basicShipProto->addSystem(mRenderSystem);
   basicShipProto->addSystem(mActorSystem);
   basicShipProto->addSystem(mHealthSystem);
   basicShipProto->addSystem(mPhysicSystem);

   boxProto->addSystem(mRenderSystem);
   boxProto->addSystem(mAnimationSystem);
   boxProto->addSystem(mHealthSystem);
   boxProto->addSystem(mPhysicSystem);

   mPrototypes.addPrototype(boxProto);
   mPrototypes.addPrototype(basicShipProto);
   mPrototypes.addPrototype(simpleBulletProto);
   mPrototypes.addPrototype(playerProto);
   mPrototypes.addPrototype(machinegunProto);
   mPrototypes.addPrototype(shipPropellerProto);

   //RenderUnits
   mRenderManager.addLayer(BACKGROUND, anTileTexture);
   mRenderManager.addLayer(FOREGROUND, anTileTexture);
   mRenderManager.addLayer(OBJECTS, anSpriteTexture);
   mRenderManager.addLayer(PARTICLES, anSpriteTexture);

   mRenderManager.getLayer(OBJECTS).mUpdatable = true;
   mRenderManager.getLayer(PARTICLES).mUpdatable = true;
   mRenderManager.getLayer(BACKGROUND).mUpdatable = false;
   mRenderManager.getLayer(FOREGROUND).mUpdatable = false;
   //Update Rate
   mApp.setUpdateRate(UPDATE_RATE);
   mApp.mWindow.setView(mView);
   mView.setRotation(0);
   mView.setSize(mApp.mVideoMode.width,mApp.mVideoMode.height);

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

void GameStateOne::reInit(void)
{}

void GameStateOne::handleEvents(sf::Event theEvent)
{
   // Exit program if Escape key is pressed

   if((theEvent.type == sf::Event::KeyReleased) &&
         (theEvent.key.code == sf::Keyboard::Escape))
   {
      mApp.quit(GQE::StatusAppOK);
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
         (theEvent.key.code == sf::Keyboard::B))
   {
      if(mPlayer)
      {
         deactivateEntity( mPlayer->mProperties.get<GQE::IEntity*>(ACTOR));
      }
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
         (theEvent.key.code == sf::Keyboard::A))
   {
   }
   else
   {
      for(int i = 0; i < 8; i++)
      {
         if(sf::Joystick::isConnected(i) && sf::Joystick::isButtonPressed(i, 0))
            if(!mPlayer)
            {
               mPlayer = addPlayer(i, BASIC_SHIP_PROTO, Position2D(40, 160, 90 * TORAD));
               GQE::IEntity* actor = mPlayer->mProperties.get<GQE::IEntity*>(ACTOR);
               GQE::Prototype* propeller = mPrototypes.getPrototype(SHIP_PROPELLER_PROTO);
               propeller->mProperties.add<GQE::IEntity*>(FATHER_NODE, actor);
               actor->mProperties.add<GQE::IEntity*>(PROPELLER, propeller->makeInstance());
               GQE::Prototype* prototype = mPrototypes.getPrototype(MACHINEGUN_PROTO);
               prototype->mProperties.add<GQE::IEntity*>(FATHER_NODE, actor);
               prototype->mProperties.set<GQE::typePropertyID>(ID32_("AnchorPoint"), ID32_("WeaponAnchorLeft"));
               GQE::IEntity* machinegunleft = prototype->makeInstance();
               actor->mProperties.getPointer<WeaponManager>(WEAPON_MANAGER)->addWeapon(machinegunleft);
               prototype->mProperties.set<GQE::typePropertyID>(ID32_("AnchorPoint"), ID32_("WeaponAnchorRight"));
               actor->mProperties.getPointer<WeaponManager>(WEAPON_MANAGER)->addWeapon(prototype->makeInstance());
            }
      }
   }
}

void GameStateOne::updateSelected(sf::Event theEvent)
{}

void GameStateOne::updateFixed(void)
{
   mRenderManager.clear();
   mPhysicSystem->updateFixed();
   mPlayerSystem->updateFixed();
   mActorSystem->updateFixed();
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

void GameStateOne::updateVariable(float theElapsedTime)
{}

void GameStateOne::draw(void)
{
   mApp.mWindow.clear();
   mRenderManager.drawLayer(BACKGROUND, mApp.mWindow);
   mRenderManager.drawLayer(PARTICLES, mApp.mWindow);
   mRenderManager.drawLayer(OBJECTS, mApp.mWindow);
   mRenderManager.drawLayer(FOREGROUND, mApp.mWindow);
#ifndef NDEBUG
   mStatManager.draw();
#endif
}

void GameStateOne::handleCleanup(void)
{}
