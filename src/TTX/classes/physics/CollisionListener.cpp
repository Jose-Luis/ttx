#include <GQE/Entity/interfaces/IEntity.hpp>
#include <TTX/classes/physics/CollisionListener.hpp>

void CollisionListener::BeginContact(b2Contact* theContact)
{
   GQE::IEntity* anCollideEntityA = 
      static_cast<GQE::IEntity*>(theContact->GetFixtureA()->GetBody()->GetUserData());
   if(anCollideEntityA)
      anCollideEntityA->destroy();
   GQE::IEntity* anCollideEntityB = 
      static_cast<GQE::IEntity*>(theContact->GetFixtureB()->GetBody()->GetUserData());
   if(anCollideEntityB)
      anCollideEntityB->destroy();
}

void CollisionListener::EndContact(b2Contact* theContact)
{}
