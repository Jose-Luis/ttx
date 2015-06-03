#include <GQE/Entity/interfaces/IEntity.hpp>
#include <Box2D/Box2D.h>

class CollisionListener : public b2ContactListener
{
public:
   void PreSolve(b2Contact* theContact, const b2Manifold* theOldManifold);
   void PostSolve(b2Contact* theContact, const b2ContactImpulse* theImpulse);
   void BeginContact(b2Contact* theContact);
   void EndContact(b2Contact* theContact);

private:
   void applyDamage(GQE::IEntity* theEntity, float theImpactStrength);
   /* data */
};
