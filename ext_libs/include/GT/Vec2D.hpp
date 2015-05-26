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
      Vec2D();                               // constructor
      explicit Vec2D(Real theX, Real theY);  // constructor
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
      Vec2D& scale(Real theXFactor,Real theYFactor);
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
      Vec2D& operator +=(const Vec2D& theVector);
      Vec2D& operator -=(const Vec2D& theVector);
      Vec2D& operator *=(Real theFloat);
      Vec2D& operator /=(Real theFloat);
      Vec2D operator -(void) const;
      Vec2D operator +(const Vec2D& theVector) const;
      Vec2D operator -(const Vec2D& theVector) const;
      Vec2D operator *(Real theFloat) const;
      Vec2D operator /(Real theFloat) const;
      Real operator *(const Vec2D& theVector) const;
      bool operator ==(const Vec2D& theVector) const;
      bool operator !=(const Vec2D& theVector) const;
}; 
////////////////////////////////////////////////////////////////////////////////
//  END OF CLASS Vec2D 
////////////////////////////////////////////////////////////////////////////////
}
#endif  



