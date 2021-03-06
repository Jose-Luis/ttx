/**
 * @file Particles.hpp
 * @brief An derived class of mpe::System to be adapted to the render system used here
 * @author Jose Luis Lavado
 * @version 0.1
 * @date 2013-04-25
 */
#ifndef PARTICLESYSTEM_T69OX7N
#define PARTICLESYSTEM_T69OX7N

#include <MPE/MPE.hpp>
#include <GQE/Core/utils/CRC32.hpp>
#include <TTX/Definition.hpp>
#include <TTX/classes/render/RenderManager.hpp>

class Particles: public mpe::System
{
public:

   void updateRender(RenderManager& theRenderManager);
   Id getParticleLayer(const mpe::Particle& theParticle);

};

#endif /* end of include guard: PARTICLESYSTEM_T69OX7N */

