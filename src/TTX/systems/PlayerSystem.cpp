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
   mRot(mAngle * TORAD),
   mFactor(theFactor)
{
}
PlayerSystem::~PlayerSystem()
{}
void PlayerSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<int>("ID", 0);
   theEntity->mProperties.add<int>("Joystick", 0);
   theEntity->mProperties.add<int>("Points", 0);
   theEntity->mProperties.add<std::string>("Name", "");
   theEntity->mProperties.add<GQE::IEntity*>("Actor", 0);
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
         GQE::IEntity* anActor = anEntity->mProperties.get<GQE::IEntity*>("Actor");
         if(anActor)
         {
             Position2D anPosition2D = anActor->mProperties.get<Position2D>("Position");
             sf::Vector2f anPosition(anPosition2D.x, anPosition2D.y);
             anPositions.push_back(anPosition);
         }


         anQueue++;
      }

      anIter++;
   }

   for (auto anPosition : anPositions)
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
{
}
void PlayerSystem::processJoystick(GQE::IEntity* theEntity)
{

   int anJoy = theEntity->mProperties.get<int>("Joystick");
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

   if( 0.2 < anLength )
   {
      anMoveData.x = anJoyStick.x;
      anMoveData.y = anJoyStick.y;
   }
   else
   {
      anMoveData.x = 0;
      anMoveData.y = 0;
   }

   if(sf::Joystick::isButtonPressed(anJoy, 3))
   {
      anMoveData.turn = false;
   }
   else
   {
       anMoveData.turn = true;
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

   GQE::IEntity* anActor = theEntity->mProperties.get<GQE::IEntity*>("Actor");
   anActor->mProperties.set<MoveData>("vMoveData", anMoveData);

   ////////////// FIRE CONTROLS

   b2Vec2 anVector(sf::Joystick::getAxisPosition(anJoy, sf::Joystick::U), -sf::Joystick::getAxisPosition(anJoy, sf::Joystick::V));

   if(400 < anVector.LengthSquared())
   {
      sf::Vector2f anPosition = theEntity->mProperties.get<sf::Vector2f>("vPosition");
      float anAngle = std::atan2( anVector.x, anVector.y );
      Position2D anPosition2D(anPosition.x, anPosition.y, anAngle );
      Weapon* anWeapon = theEntity->mProperties.getPointer<Weapon>("wWeapon");
      anWeapon->fire(anPosition2D, mState);
   }
}
