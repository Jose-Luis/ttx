#include <TTX/systems/ParticleSystem.hpp>

ParticleSystem::ParticleSystem(GQE::IState& theState,Particles& theParticles):
   ISystem("ParticleSystem",theState),
   mParticles(theParticles)
{
   mParticles.setXFactor(16);
   mParticles.setYFactor(16);
   mParticles.setTexture(mApp.mAssetManager.getHandler<sf::Texture>().getReference("resources/Sprites.png"));
   /*mpe::Emitter anEmitter("ShipParticle");*/
   //anEmitter.setTexRect(sf::Rect<int>(0,64,16,16));
   //anEmitter.setShape(mpe::Emitter::CIRCLE);
   //anEmitter.setRangeFocusWidth(0.5,0.5);
   //anEmitter.setRangeFocusHeight(0.5,0.5);
   //anEmitter.setRangeParticlePOW(0.0,0.0);
   //anEmitter.setRangeParticleTOL(1024,2048);
   //anEmitter.setDispersion(mpe::Emitter::STATIC);
   //anEmitter.setRangeFocusTOL(mpe::REAL_INFINITY,mpe::REAL_INFINITY);
   //anEmitter.setRangeFocusNP(mpe::MAX_INTEGER,mpe::MAX_INTEGER);
   //anEmitter.setRangeFocusPPS(0,0);
   //anEmitter.setRangeParticleScale(0.8,2.4);
   /*anEmitter.setRangeParticleAV(0,0);*/
   mParticles.addEmitter(emitter1);
}

ParticleSystem::~ParticleSystem()
{}

void ParticleSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<mpe::EmitterID>("pEmitterID","DUMMY");
}

void ParticleSystem::handleInit(GQE::IEntity* theEntity)
{
   mpe::EmitterID anEmitterID = 
      theEntity->mProperties.get<mpe::EmitterID>("pEmitterID");

   sf::Vector2f anPosition =
      theEntity->mProperties.get<sf::Vector2f>("vPosition");

   float anAngle = theEntity->mProperties.get<float>("fAngle");

   mpe::FocusPtr anFocus = mParticles.createFocus(anEmitterID,
                                                  anPosition.x,
                                                  anPosition.y, 
                                                  anAngle);
   mParticles.addFocus(anFocus);
      theEntity->mProperties.add<mpe::FocusPtr>("pFocus",anFocus);
}

void ParticleSystem::handleEvents(sf::Event theEvent)
{
}

void ParticleSystem::updateFixed()
{
   std::map<const GQE::Uint32, std::deque<GQE::IEntity*> >::iterator anIter;
   anIter = mEntities.begin();
   while(anIter != mEntities.end())
   {
      std::deque<GQE::IEntity*>::iterator anQueue = anIter->second.begin();
      while(anQueue != anIter->second.end())
      {
         // get the IEntity address first
         GQE::IEntity* anEntity = *anQueue;

         sf::Vector2f anPosition =
            anEntity->mProperties.get<sf::Vector2f>("vPosition");

         float anAngle = anEntity->mProperties.get<float>("fAngle");
         mpe::FocusPtr anFocus = 
            anEntity->mProperties.get<mpe::FocusPtr>("pFocus");

         anFocus->setPosition(anPosition.x,anPosition.y);
         anFocus->setAngle(anAngle);
         // Increment the IEntity iterator second
         anQueue++;
      }  
      anIter++;
   mParticles.update(UPDATE_RATE);
   }
}

void ParticleSystem::updateVariable(float theElapsedTime)
{
}

void ParticleSystem::draw()
{
   mParticles.draw(mApp.mWindow);
}

void ParticleSystem::handleCleanup(GQE::IEntity* theEntity)
{
  delete (theEntity->mProperties.get<Particle*>("pParticle"));
}

/**
 * Copyright (c) 2010-2012 Jacob Dix
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
