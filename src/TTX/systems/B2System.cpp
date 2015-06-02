// =====================================================================================
// 
//       Filename:  B2System.cpp
// 
//    Description:  
// 
//        Version:  1.0
//        Created:  15/10/12 12:30:05
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  YOUR NAME (), 
//        Company:  
// 
// =====================================================================================

#include <TTX/systems/B2System.hpp>

/*B2System::B2System(GQE::IState& theState):*/
   //ISystem("B2System",theState),
   //mWorld(b2Vec2(0.0f,1.0f))
//{ 
   ////mTimeStep = theApp.getUpdateRate();
   
   //mTimeStep = 1/30.f;
   //mVelocityIterations = 6;
   //mPositionIterations = 2;
/*}*/

B2System::B2System(IActionState& theState,b2World& theWorld):
   ISystem("B2System",theState),
   mWorld(theWorld)
{
   //mTimeStep = this->mApp.getUpdateRate();
   mTimeStep = SPU;
   mVelocityIterations = 6;
   mPositionIterations = 2;
}

B2System::~B2System()
{}

void B2System::addProperties(GQE::IEntity *theEntity)
{
   theEntity->mProperties.add<sf::Vector2f>("vPosition",sf::Vector2f(0,0));
   theEntity->mProperties.add<float>("fAngle",0);
   theEntity->mProperties.add<b2Body*>("b2Body",0);
   theEntity->mProperties.add<sf::Transform>("b2Body",0);
}


void B2System::updateFixed()
{
   mWorld.Step(mTimeStep,mVelocityIterations,mPositionIterations);

   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();
   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();
      while(anQueue != anIter->second.end())
      {
         // get the IEntity address first
         GQE::IEntity* anEntity = *anQueue;

         b2Body* anBody    = anEntity->mProperties.get<b2Body*>("b2Body");
         b2Vec2 anPosition = anBody->GetPosition();
         float anAngle     = anBody->GetAngle();
         
         
         anEntity->mProperties.set<sf::Vector2f>("vPosition",sf::Vector2f(anPosition.x,anPosition.y));
         anEntity->mProperties.set<float>("fAngle",anAngle * TODEG);

         // Increment the IEntity iterator second
         anQueue++;
      }  
      anIter++;
   }
   
}

void B2System::updateVariable(float theElapsedTime)
{}

void B2System::handleInit(GQE::IEntity* theEntity)
{
   b2BodyDef* anBodyDef = theEntity->mProperties.get<b2BodyDef*>("b2BodyDef");
   std::vector<b2FixtureDef>* anFixturesDef = 
      theEntity->mProperties.get<std::vector<b2FixtureDef>*>("b2FixturesDef");

   sf::Vector2f anPosition = theEntity->mProperties.get<sf::Vector2f>("vPosition");
   float anAngle = theEntity->mProperties.get<float>("fAngle");
   Position2D anImpulse = theEntity->mProperties.get<Position2D>("pInitialImpulse");
 
   anBodyDef->position.Set(anPosition.x,anPosition.y);
   anBodyDef->angle = anAngle;

   b2Body* anBody = mWorld.CreateBody(anBodyDef);
   anBody->SetUserData(theEntity);
   if(anImpulse.x + anImpulse.y + anImpulse.angle != 0)
   {
      anBody->ApplyLinearImpulse(b2Vec2(anImpulse.x,anImpulse.y),anBody->GetPosition());
   }
   
   std::vector<b2FixtureDef>::iterator anIter;

   for(anIter = anFixturesDef->begin();anIter!= anFixturesDef->end();anIter++)
   {
      anBody->CreateFixture(&(*anIter));
   }
   theEntity->mProperties.set<b2Body*>("b2Body",anBody);
}

void B2System::handleCleanup(GQE::IEntity* theEntity)
{
   mWorld.DestroyBody(theEntity->mProperties.get<b2Body*>("b2Body"));
   std::cout << mWorld.GetBodyCount() << " -- ";
}

void B2System::handleEvents(sf::Event theEvent)
{}
void B2System::draw(void)
{}
