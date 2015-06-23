/**
 * @file Affectors.hpp
 * @brief Particles affectors classes
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-25
 */
#ifndef AFFECTORS_INC
#define AFFECTORS_INC

#include <random>
#include<MPE/MPE.hpp>

class DisolveAffector: public mpe::Affector
{
public:

   DisolveAffector(mpe::Real theLifetime, mpe::Real theColorFactor);
   void affect(mpe::Particle& theParticle , mpe::Real theElapsedTime);
   virtual void update(mpe::Real theElapsedTime);
   static std::shared_ptr<DisolveAffector> create(mpe::Real theColorFactor);

private:
   mpe::Real mColorFactor;
   std::default_random_engine mGenerator;
   std::exponential_distribution<float> mDistribution;
};
#endif
