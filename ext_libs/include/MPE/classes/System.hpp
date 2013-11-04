/// @file System.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  SYSTEM_INC
#define  SYSTEM_INC

#include <list>
#include <map>
#include <MPE/Config.hpp>
#include <MPE/classes/Particle.hpp>
#include <MPE/classes/ParticleContainer.hpp>
#include <MPE/classes/Affector.hpp>
#include <MPE/classes/Emitter.hpp>
#include <MPE/classes/Focus.hpp>
#include <tinyxml2.h>

namespace mpe
{
class System
{
public:
   
   System();
   System(size_t theNParticles,bool theFixed=true);
   bool setSize(size_t theNumberOfParticles);
   void addEmitter(Emitter& theEmitter);
   void addFocus(FocusPtr theFocus);
   void addAffector(AffectorPtr theAffector);
   Particle* addParticle();
   FocusPtr createFocus(EmitterID theEmitter);
   void update(Real theElapsedTime);
   Emitter& getEmitter(EmitterID theEmitterID);
   Integer getParticlesSize();
   ParticleContainer::const_iterator getParticlesBegin() const;
   ParticleContainer::const_iterator getParticlesEnd() const;
   Real getXFactor() const;
   void setXFactor(Real theXFactor);
   Real getYFactor() const;
   void setYFactor(Real theYFactor);
   bool initFromFile(std::string theFilename);

private:

   void updateParticles(Real theElapsedTime);
   void updateFocusses (Real theElapsedTime);

private:

   Real mXFactor;
   Real mYFactor;
   std::list<FocusPtr>           mFocusses;
   std::list<AffectorPtr>        mAffectors;
   ParticleContainer             mParticles;
   std::map<EmitterID, Emitter>  mEmitters;
};
}
#endif
