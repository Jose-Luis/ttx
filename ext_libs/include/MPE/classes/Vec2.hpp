/// @file Position.hpp
/// @author Jose Luis Lavado
/// @version 0.2
/// @date 2013-01-10

#ifndef VEC2_GSAIH2DS
#define VEC2_GSAIH2DS

#include <MPE/Config.hpp>

namespace mpe
{
class Vec2
{

public:

   Vec2(): x(0), y(0) {}

   Vec2(Real theX, Real theY):
      x(theX),
      y(theY)
   {}

   void init(Real theX, Real theY)
   {
      x = theX;
      y = theY;
   }

   Real getX()
   {
      return x;
   }
   Real getY()
   {
      return y;
   }


   Real length()
   {
      return std::sqrt(x * x + y * y);
   }

   Real squareLength()
   {
      return x * x + y * y;
   }

   void normalize()
   {
      Real anLength = length();

      if(anLength)
      {
         x /= anLength;
         y /= anLength;
      }
   }

   Vec2& scale(const Real& theScalarX, const Real& theScalarY)
   {
      x *= theScalarX;
      y *= theScalarY;
      return (*this);
   }

   Vec2& rotate ( Real theAngle )
   {
      Real aCosine = std::cos(theAngle);
      Real aSine = std::sin(theAngle);

      Real nx = x * aCosine - y * aSine;
      Real ny = x * aSine + y * aCosine;

      x = nx;
      y = ny;

      return (*this);
   }

   Vec2 operator*(const Real& theScalar) const
   {
      return Vec2(x * theScalar, y * theScalar);
   }

   Vec2& operator*=(const Real& theScalar)
   {
      x *= theScalar;
      y *= theScalar;
      return (*this);
   }

   Vec2 operator-(const Vec2& theVector) const
   {
      return Vec2(x - theVector.x, y - theVector.y);
   }

   Vec2& operator -=(const Vec2& theVector)
   {
      x -= theVector.x;
      y -= theVector.y;

      return (*this);
   }

   Vec2 operator+(const Vec2& theVector) const
   {
      return Vec2(x + theVector.x, y + theVector.y);
   }

   Vec2& operator +=(const Vec2& theVector)
   {
      x += theVector.x;
      y += theVector.y;

      return (*this);
   }

private:

   Real x, y;
};
}
#endif /* end of include guard: VEC2_GSAIH2DS */
