#include <TTX/systems/HealthSystem.hpp>

HealthSystem::HealthSystem(IActionState& theState):
   ISystem("HealthSystem", theState)
{}

HealthSystem::~HealthSystem()
{}

void HealthSystem::addProperties(GQE::IEntity* theEntity)
{
   theEntity->mProperties.add<float>("Resistance", 0);
   theEntity->mProperties.add<float>("Health", 0);
}

void HealthSystem::handleInit(GQE::IEntity* theEntity)
{}

void HealthSystem::handleEvents(sf::Event theEvent)
{
}

void HealthSystem::updateFixed()
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

         auto anHealth = anEntity->mProperties.get<float>("Health");

         if(anHealth < 0)
         {
            auto anDeadActions = anEntity->mProperties.get
            anEntity->destroy();
         }

         anQueue++;
      }

      anIter++;
   }
}

void HealthSystem::updateVariable(float theElapsedTime)
{
}

void HealthSystem::draw()
{
}

void HealthSystem::handleCleanup(GQE::IEntity* theEntity)
{
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
