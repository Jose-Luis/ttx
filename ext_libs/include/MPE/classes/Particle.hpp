/// @file Particle.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  PARTICLE_INC
#define  PARTICLE_INC

#include <MPE/Config.hpp>
#include <MPE/classes/Mortal.hpp>
#include <MPE/classes/Vec2.hpp>

namespace mpe
{
/// @class Particle
/// @brief Particle
class Particle: public Mortal
{
public:
   /// @brief Particle
   Particle();
   /// @brief ~Particle
   ~Particle();

   void update(Real theElapsedTime);

   Real getSize() const;
   void setSize(Real theSize);

   Vec2 getPosition() const;
   void setPosition(Vec2 thePosition);


   Real getAngle() const;
   void setAngle(Real theAngle);

   Vec2 getLinearVelocity() const;
   void setLinearVelocity(Vec2 theLinearVelocity);

   Real getAngularVelocity() const;
   void setAngularVelocity(Real theAngularVelocity);

   TextRect getTextRect() const;
   void setTextRect(TextRect theTextRect);

   Color getColor() const;
   void  setColor(Color theColor);
   void modifyAlpha(int theAlphaInc);
   bool isTransparent();


   GroupID getGroups() const;
   void  setGroups(GroupID theGroup);
   bool belongToGroup(const GroupID theGroups) const;

private:

   Real      mSize;
   Vec2      mPosition;
   Real      mAngle;
   Vec2      mLinearVelocity;
   Real      mAngularVelocity;
   TextRect  mTextRect;
   Color     mColor;
   GroupID   mGroups;
};
}
#endif
// Copyright (C)
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

