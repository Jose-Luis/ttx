#include <Box2D/Box2D.h>

class CollisionListener :public b2ContactListener
{
public:
   void BeginContact(b2Contact* theContact);
   void EndContact(b2Contact* theContact);

private:
   /* data */
};
