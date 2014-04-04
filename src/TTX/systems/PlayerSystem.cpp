// =====================================================================================
//
//       Filename:  PlayerSystem.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  30/10/12 00:26:44
//       Revision:  none
//       Compiler:  g++
//
//         Author:  YOUR NAME (),
//        Company:
//
// =====================================================================================

#include <TTX/systems/PlayerSystem.hpp>

PlayerSystem::PlayerSystem(IActionState& theState, sf::View& theView, float theFactor):
   ISystem("PlayerSystem", theState),
   mView(theView),
   mAngle(theView.getRotation()),
   mRot(mAngle* TORAD),
   mFactor(theFactor)
{
}
PlayerSystem::~PlayerSystem()
{}
void PlayerSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<int>("iID", 0);
   theEntity->mProperties.add<int>("iJoystick", 0);
   theEntity->mProperties.add<int>("iPoints", 0);
   theEntity->mProperties.add<std::string>("sName", "");
   theEntity->mProperties.add<GQE::Instance*>("gInstance", 0);
}

void PlayerSystem::handleEvents(sf::Event theEvent)
{
}

void PlayerSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   std::vector<sf::Vector2f> anPositions;
   sf::Vector2f anCenterPosition;

   anIter = mEntities.begin();

   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();

      while(anQueue != anIter->second.end())
      {
         GQE::IEntity* anEntity = *anQueue;

         processJoystick(anEntity);
         sf::Vector2f anPosition = anEntity->mProperties.get<sf::Vector2f>("vPosition");
         anPositions.push_back(anPosition);

         anQueue++;
      }

      anIter++;
   }

for (auto anPosition: anPositions)
   {
      anCenterPosition.x += anPosition.x;
      anCenterPosition.y += anPosition.y;
   }

   if(int nPositions = anPositions.size())
   {
      anCenterPosition.x /= nPositions;
      anCenterPosition.y /= nPositions;
      anCenterPosition.x *= mFactor;
      anCenterPosition.y *= mFactor;
      mView.setCenter(anCenterPosition);
      GQE::IApp::getApp()->mWindow.setView(mView);
   }
}

void PlayerSystem::draw(void)
{}
void PlayerSystem::updateVariable(float theElapsedTime)
{}
void PlayerSystem::handleInit(GQE::IEntity* theEntity)
{}
void PlayerSystem::handleCleanup(GQE::IEntity* theEntity)
{}
void PlayerSystem::processJoystick(GQE::IEntity* theEntity)
{

   int anJoy = theEntity->mProperties.get<int>("iJoystick");
   bool anViewChanged = false;

   ////////////// VIEW CONTROLS
   if(sf::Joystick::isButtonPressed(anJoy, 4))
   {
      mAngle -= 1;
      mView.setRotation(mAngle);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(anJoy, 5))
   {
      mAngle += 1;
      mView.setRotation(mAngle);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(anJoy, 6))
   {
      mView.zoom(0.98);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(anJoy, 7))
   {
      mView.zoom(1.02);
      anViewChanged = true;
   }

   if (anViewChanged)
   {
      GQE::IApp::getApp()->mWindow.setView(mView);
      mRot.Set(mAngle * TORAD);
   }

   ////////////// MOVE CONTROLS
   ///////////  JOY  CONTROLS

   MoveData anMoveData;

   b2Vec2 anJoyStick(sf::Joystick::getAxisPosition(anJoy, sf::Joystick::X) / 100,
                     sf::Joystick::getAxisPosition(anJoy, sf::Joystick::Y) / 100);
   anJoyStick = b2Mul(mRot, anJoyStick);
   float anLength = anJoyStick.Length();

   if( 1 < anLength )
   {
      anJoyStick *= 1.f / anLength;
   }

   anMoveData.x = anJoyStick.x;
   anMoveData.y = anJoyStick.y;

   if(sf::Joystick::isButtonPressed(anJoy, 3))
   {
      anMoveData.turn = false;
   }

   if(sf::Joystick::isButtonPressed(anJoy, 7))
   {
      anMoveData.move = false;
   }

   if (anViewChanged)
   {
      GQE::IApp::getApp()->mWindow.setView(mView);
      mRot.Set(mAngle * TORAD);
   }

   theEntity->mProperties.set<MoveData>("vMoveData", anMoveData);

   ////////////// FIRE CONTROLS
   if(sf::Joystick::isButtonPressed(anJoy, 2))
   {
      sf::Vector2f anPosition = theEntity->mProperties.get<sf::Vector2f>("vPosition");
      float anAngle = theEntity->mProperties.get<float>("fAngle") * TORAD;
      Position2D anPosition2D(anPosition.x, anPosition.y, anAngle);
      Weapon* anWeapon = theEntity->mProperties.getPointer<Weapon>("wWeapon");
      anWeapon->fire(anPosition2D, mState);
   }
}
