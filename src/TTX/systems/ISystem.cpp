/**
 * @file ISystem.cpp
 * @brief Implematacion
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-21
 */


#include <TTX/systems/ISystem.hpp>

//------------------------------------------------------------------------------
//       Class:  ISystem
//      Method:
// Description:  A stupid method
//------------------------------------------------------------------------------
ISystem::ISystem (GQE::typeSystemID theSystemID,
                  IActionState&      theState):
   GQE::ISystem(theSystemID, *GQE::IApp::getApp()),
   mState(theState)
{}
ISystem::~ISystem() {}
