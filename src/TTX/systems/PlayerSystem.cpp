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
{}

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

         GQE::IEntity* actor = anEntity->mProperties.get<GQE::IEntity*>("Actor");

         if(actor)
         {
            int joy = anEntity->mProperties.get<int>("Joystick");

            processJoystick(joy,actor);
            Position2D anPosition2D = actor->mProperties.get<Position2D>("Position");
            sf::Vector2f anPosition(anPosition2D.x, anPosition2D.y);
            anPositions.push_back(anPosition);
         }
         else
         {
            sf::Font aFont;
            aFont.loadFromFile("resources/arial.ttf");
            sf::Text aText;
            aText.setFont(aFont);
            aText.setCharacterSize(32);
            aText.setColor(sf::Color::Green);

            aText.setString("GAME OVER!");
            //aText.setPosition(mView.getCenter());
            mApp.mWindow.draw(aText);
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
void PlayerSystem::processJoystick(int theJoy, GQE::IEntity* theActor)
{

   bool anViewChanged = false;

   ////////////// VIEW CONTROLS
   if(sf::Joystick::isButtonPressed(theJoy, 4))
   {
      mAngle -= 1;
      mView.setRotation(mAngle);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(theJoy, 5))
   {
      mAngle += 1;
      mView.setRotation(mAngle);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(theJoy, 6))
   {
      mView.zoom(0.98);
      anViewChanged = true;
   }

   if(sf::Joystick::isButtonPressed(theJoy, 7))
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

   b2Vec2 theJoyStick(sf::Joystick::getAxisPosition(theJoy, sf::Joystick::X) / 100,
                     sf::Joystick::getAxisPosition(theJoy, sf::Joystick::Y) / 100);
   theJoyStick = b2Mul(mRot, theJoyStick);
   float anLength = theJoyStick.Length();

   if( 1 < anLength )
   {
      theJoyStick *= 1.f / anLength;
   }

   if( 0.2 < anLength )
   {
      anMoveData.x = theJoyStick.x;
      anMoveData.y = theJoyStick.y;
   }
   else
   {
      anMoveData.x = 0;
      anMoveData.y = 0;
   }

   if(sf::Joystick::isButtonPressed(theJoy, 3))
   {
      anMoveData.turn = false;
   }
   else
   {
      anMoveData.turn = true;
   }

   if(sf::Joystick::isButtonPressed(theJoy, 7))
   {
      anMoveData.move = false;
   }

   if (anViewChanged)
   {
      GQE::IApp::getApp()->mWindow.setView(mView);
      mRot.Set(mAngle * TORAD);
   }

   theActor->mProperties.set<MoveData>("MoveData", anMoveData);

}
