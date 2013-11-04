/// @file Affector.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-08

#ifndef  AFFECTOR_INC
#define  AFFECTOR_INC

#include <MPE/classes/Mortal.hpp>

namespace mpe
{
class Particle;

class Affector: public Mortal
{
public:
   /// @brief affect
   /// @param theParticle
   virtual void affect(Particle& theParticle, Real theElapsedTime) = 0;
   /// @brief update
   /// @param theElapsedtime
   virtual void update(Real theElapsedtime)
   {
      age(theElapsedtime);
   };

protected:
   /// @brief IAffector
   /// @param theRadius
   Affector(Real      theLifetime);
};
}
#endif
