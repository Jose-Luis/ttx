/**
 * Provides the TTXApp class which implements the TTX example game
 * for the GQE library.
 *
 * @file src/TTXApp.cpp
 * @author Ryan Lindeman
 * @date 20120323 - Initial Release
 * @date 20120512 - Add new Init methods required by IApp base class
 */

#include <TTX/app/TTXapp.hpp>
#include <TTX/gameStates/GameStateOne.hpp>
#include <GQE/Core/states/SplashState.hpp>

TTXApp::TTXApp(const std::string theTitle) :
   GQE::IApp(theTitle)
{
}

TTXApp::~TTXApp()
{
}

void TTXApp::initAssetHandlers(void)
{
   // No custom asset handlers needed or provided
}

void TTXApp::initScreenFactory(void)
{
   // Add Menu State as the next active state
   mStateManager.addActiveState(new(std::nothrow) GameStateOne(*this));

//  mStateManager.addActiveState(new(std::nothrow) GQE::SplashState(*this, "Splash"));
}

void TTXApp::handleCleanup(void)
{
   // No custom cleanup needed
}
