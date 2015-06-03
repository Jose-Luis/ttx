#include<TTX/classes/particles/Affectors.hpp>

DisolveAffector::DisolveAffector(mpe::Real theLifetime, mpe::Real theColorFactor):
   Affector(theLifetime),
   mColorFactor(theColorFactor)
{
}
void DisolveAffector::affect(mpe::Particle& theParticle, mpe::Real theElapsedTime)
{
   theParticle.modifyAlpha(-mColorFactor);

   if (theParticle.isTransparent())
   {
      theParticle.kill();
   }
}

void DisolveAffector::update(mpe::Real theElapsedTime)
{
   age(theElapsedTime);
}

std::shared_ptr<DisolveAffector> DisolveAffector::create(mpe::Real theColorFactor)
{
   return std::make_shared<DisolveAffector>(mpe::REAL_INFINITY, theColorFactor);
}
