#include <TTX/classes/physics/CollisionListener.hpp>

void CollisionListener::PreSolve(b2Contact* theContact, const b2Manifold* theOldManifold)
{
}

void CollisionListener::PostSolve(b2Contact* theContact, const b2ContactImpulse* theImpulse)
{
   auto anCollideEntityA = static_cast<GQE::IEntity*>(theContact->GetFixtureA()->GetBody()->GetUserData());
   auto anCollideEntityB = static_cast<GQE::IEntity*>(theContact->GetFixtureB()->GetBody()->GetUserData());

   float aImpactStrength = theImpulse->normalImpulses[0];

   applyDamage(anCollideEntityA, aImpactStrength);
   applyDamage(anCollideEntityB, aImpactStrength);
}

void CollisionListener::BeginContact(b2Contact* theContact)
{}

void CollisionListener::EndContact(b2Contact* theContact)
{}

void CollisionListener::applyDamage(GQE::IEntity* theEntity, float theImpactStrength)
{
   if (theEntity)
   {
      float aResistance = theEntity->mProperties.get<float>(RESISTANCE);
      if(aResistance)
      {
         float aDamage = theImpactStrength / aResistance;
         float aHealth = theEntity->mProperties.get<float>(HEALTH);
         theEntity->mProperties.set<float>(HEALTH, aHealth - aDamage);
      }
   }
}
