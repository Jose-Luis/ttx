/**
 * @file ISystem.hpp
 * @brief A derived class from ISystem that kepp a reference to its World
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-19
 */
#ifndef ISYSTEM_E119QL54
#define ISYSTEM_E119QL54
//Headers
//#include <GQE/Core/interfaces/IState.hpp>
#include <GQE/Entity/interfaces/ISystem.hpp>
//#include <TTX/gameStates/IActionState.hpp>
class IActionState;
/**
 * @brief : A wrapper class for GQE::ISystem that keep a reference to its World
 */
class ISystem: public GQE::ISystem
{
public:
   /**
    * @brief ISystem constructor
    */
   ISystem (GQE::typeSystemID theSystemID,
            IActionState&      theState);
   /**
    * @brief ~ISystem destructor
    */
   virtual ~ISystem ();

    IActionState& mState;
};
#endif /* end of include guard: ISYSTEM_E119QL54 */
