#ifndef PARTICLECONTAINER_N3JXVU09
#define PARTICLECONTAINER_N3JXVU09

#include <cstring>
#include <MPE/classes/Particle.hpp>

namespace mpe 
{
   class ParticleContainer 
   {
   public:

      using  iterator = Particle* ;
      using  const_iterator = const Particle* ;

      ParticleContainer (size_t theSize, bool theFixed = true);
      ~ParticleContainer ();
   
      Particle* addParticle();
      void removeParticle(Particle* theParticle);

      size_t size(){return mSize;};
      bool setSize(size_t theNumberOfParticles);

      iterator begin() {return mParticles;}
      const_iterator begin() const {return mParticles;}

      iterator end() {return mParticles + mSize;}
      const_iterator end() const {return mParticles + mSize;}

      
   private:
      Particle*  mParticles;
      size_t mSize;
      size_t mMaxSize;
      bool mFixedSize;

      bool grow();


   };
} /* mpe */

#endif /* end of include guard: PARTICLECONTAINER_N3JXVU09 */
