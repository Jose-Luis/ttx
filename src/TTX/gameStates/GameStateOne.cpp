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
   IActionState("State1",theApp)
{
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
   mView.setRotation(0);
   //Prototypes
   mPrototypes.addPrototype(new Rombo());
   mPrototypes.addPrototype(new Box());
   mPrototypes.addPrototype(new Ground());
   mPrototypes.addPrototype(new BasicShip());
   mPrototypes.addPrototype(new SimpleBullet());
   mPrototypes.addPrototype(new Player());
   mPrototypes.addPrototype(new Machinegun());
   //Systems
   addSystem(new AttachSystem(*this));
   addSystem(new RenderSystem(*this,mRenderManager,LENGTHFACTOR));
   addSystem(new PlayerSystem(*this,mView,LENGTHFACTOR));
   addSystem(new PropellerSystem(*this,mParticles));
   addSystem(new B2System(*this,mWorld));
   addSystem(new AnimationSystem(*this));
   addSystem(new HealthSystem(*this));
   //RenderUnits
   mRenderManager.addLayer("Back",anTileTexture);
   mRenderManager.addLayer("Fore",anTileTexture);
   mRenderManager.addLayer("Obj1",anSpriteTexture);
   mRenderManager.addLayer("Par1",anSpriteTexture);
   mRenderManager.getLayer("Obj1").mUpdatable = true;
   mRenderManager.getLayer("Par1").mUpdatable = true;
   mRenderManager.getLayer("Back").mUpdatable = false;
   mRenderManager.getLayer("Fore").mUpdatable = false;
   //Update Rate
   mApp.setUpdateRate(UPDATE_RATE);
   //Others
   mApp.mWindow.setView(mView);
   mApp.mWindow.setVerticalSyncEnabled(true);
   mParticles.setSize(1024);
   mParticles.setXFactor(16);
   mParticles.setYFactor(16);
   mParticles.initFromFile("resources/Particles.xml");
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
      addInstance("pBox",Position2D(rand()%4,16,rand()%3),Position2D(3,3,0));
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
           (theEvent.key.code == sf::Keyboard::B))
   {
      //Position2D anPos(rand()%40,0,rand()%6);
      addInstance("pRombo",Position2D(rand()%40,0,rand()%6));
   }
   else if((theEvent.type == sf::Event::KeyReleased) &&
           (theEvent.key.code == sf::Keyboard::A))
   {
      if(mPlayer)
      {
          GQE::Prototype* anPrototype = mPrototypes.getPrototype("pMachinegun");
          GQE::Instance* anInstance = anPrototype->makeInstance();
          //Setting the posiion to the instance.
          anInstance->mProperties.set<GQE::IEntity*>("Parent", mPlayer);
          //Adding the instance to the systems.
          for(auto anSystem :  anPrototype->mSystemIDs)
          {
              mSystems[anSystem]->addEntity(anInstance);
          }
      }
      
   }
    else
    {
       for(int i=0;i<8;i++)
       {
          if(sf::Joystick::isConnected(i) && sf::Joystick::isButtonPressed(i,0))
             if(!mPlayer)
            this->mPlayer = addPlayer(i,"pBasicShip",Position2D(4,16,90*TORAD));
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
   mSystems["B2System"]->updateFixed();
   mSystems["AttachSystem"]->updateFixed();
   mSystems["PlayerSystem"]->updateFixed();
   mSystems["PropellerSystem"]->updateFixed();
   mSystems["HealthSystem"]->updateFixed();
   mSystems["AnimationSystem"]->updateFixed();
   mSystems["RenderSystem"]->updateFixed();
   mParticles.update(SPU);
   mParticles.updateRender(mRenderManager);
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
   mRenderManager.drawLayer("Back",mApp.mWindow);
   mRenderManager.drawLayer("Par1",mApp.mWindow);
   mRenderManager.drawLayer("Obj1",mApp.mWindow);
   mRenderManager.drawLayer("Fore",mApp.mWindow);

}
//------------------------------------------------------------------------------
//       Class:  GameStateOne
   /*
#ifndef  NDEBUG
   mAcum += 1/mFpsClock.restart().asSeconds();
   mCont += 1;
   if (mCont == 30)
   {
      float anFps = mAcum /30;
      mCont = 0;
      mAcum = 0;
      std::ostringstream ss;
      ss << "FPS: " << anFps;
      std::string s(ss.str());
      mFpsText.setString(s);
   }
   mFpsText.setPosition(mView.getCenter());
   mApp.mWindow.draw(mFpsText);
   #endif *///      Method:  handleCleanup
// Description:   
//------------------------------------------------------------------------------
void GameStateOne::handleCleanup(void)
{
}
