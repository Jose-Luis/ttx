/// @file ActionProto.hpp
/// @brief Only for ad an IAcionState refenrecen to the prototype
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2014-04-17

class ActionProto
{
public:

    ActionProto (IActionState& theActionState): mState(theActionState);
    virtual ~ActionProto ();

private:
    IActionState& mState;
};

