/// @file Vec2D.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  VEC2D_INC
#define  VEC2D_INC

#include <cmath>
#include <GT/Angle.hpp>

namespace gt
{
////////////////////////////////////////////////////////////////////////////////
///  @class  Vec2D
///  @brief  Two dimentions vector
////////////////////////////////////////////////////////////////////////////////
class Vec2D
{
public:

   Real x;
   Real y;
   //////////////////////////////////////////////////////////////////////////
   //                       LIFECYCLE
   //////////////////////////////////////////////////////////////////////////
   /// @brief Vec2D
   explicit Vec2D();
   /// @brief Vec2D
   /// @param theX
   /// @param theY
   explicit Vec2D(Real theX, Real theY);
   //////////////////////////////////////////////////////////////////////////
   //                       METHODS
   //////////////////////////////////////////////////////////////////////////
   /// @brief module
   /// @return
   Real module ();
   /// @brief module
   /// @return
   Real squaremodule ();
   /// @brief scale
   /// @param theXFactor
   /// @param theYFactor
   /// @return
   Vec2D& scale(Real theXFactor, Real theYFactor);
   /// @brief normalize
   /// @return
   Vec2D& normalize(void);
   /// @brief rotate
   /// @param angle
   /// @return
   Vec2D& rotate(Real theAngle);
   /// @brief rotate
   /// @param theAngle
   /// @return
   Vec2D& rotate(Angle theAngle);
   //////////////////////////////////////////////////////////////////////////
   //                       OPERATORS
   //////////////////////////////////////////////////////////////////////////
   /// @brief +=
   /// @param theVector
   /// @return
   Vec2D& operator +=(const Vec2D& theVector);
   /// @brief -=
   /// @param theVector
   /// @return
   Vec2D& operator -=(const Vec2D& theVector);
   /// @brief =
   /// @param theFloat
   /// @return
   Vec2D& operator *=(Real theFloat);
   /// @brief /=
   /// @param theFloat
   /// @return
   Vec2D& operator /=(Real theFloat);
   /// @brief -
   /// @return
   inline Vec2D operator -(void) const
   {
      return (Vec2D(-x, -y));
   }
   /// @brief +
   /// @param theVector
   /// @return
   inline Vec2D operator +(const Vec2D& theVector) const
   {
      return (Vec2D(x + theVector.x, y + theVector.y));
   }
   /// @brief -
   /// @param theVector
   /// @return
   inline Vec2D operator -(const Vec2D& theVector) const
   {
      return (Vec2D(x - theVector.x, y - theVector.y));
   }
   /// @brief
   /// @param theFloat
   /// @return
   inline Vec2D operator *(Real theFloat) const
   {
      return (Vec2D(x * theFloat, y * theFloat));
   }
   /// @brief /
   /// @param theFloat
   /// @return
   inline Vec2D operator /(Real theFloat) const
   {
      return (Vec2D(x / theFloat, y / theFloat));
   }
   /// @brief
   /// @param theVector
   /// @return
   inline Real operator *(const Vec2D& theVector) const
   {
      return (x * theVector.x + y * theVector.y);
   }
   /// @brief ==
   /// @param theVector
   /// @return
   bool operator ==(const Vec2D& theVector) const;
   /// @brief !=
   /// @param theVector
   /// @return
   bool operator !=(const Vec2D& theVector) const;
};
////////////////////////////////////////////////////////////////////////////////
//  END OF CLASS Vec2D
////////////////////////////////////////////////////////////////////////////////
}
#endif



