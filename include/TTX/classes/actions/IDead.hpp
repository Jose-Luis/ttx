#ifndef IDEAD_RKHT6JPP

#define IDEAD_RKHT6JPP


class IActionState;
class Position2D;

class IDead 
{
public:
    virtual void execute(Position2D, IActionState&) = 0;
};


#endif /* end of include guard: IDEAD_RKHT6JPP */
