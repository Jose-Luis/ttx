/// @file Angle.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-18

#ifndef  ANGLE_INC
#define  ANGLE_INC

#include <cmath>
#include <GT/Config.hpp>

namespace gt
{
   /// @brief Angle 
   class Angle
   {
      public:
         /// @brief  PI constant
         const static Real PI;
         /// @brief Angle 
         /// @param theValue
         Angle(Real theValue);
         /// @brief getValue 
         /// @return 
         inline Real getValue ( ) const {return mValue;};
         /// @brief getSin 
         /// @return 
         inline Real getSin ( ) const {return mSin;};
         /// @brief getCos 
         /// @return 
         inline Real getCos ( ) const {return mCos;};
         /// @brief set 
         /// @param theValue
         inline void set(Real theValue)
         {
            mValue = theValue;
            mSin = std::sin(theValue);
            mCos = std::cos(theValue);
         };
         /// @brief toRadians 
         /// @param theDegrees
         /// @return 
         static inline Real toRadians(float theDegrees)
         {
            return (theDegrees*PI/180);
         };
         /// @brief toDegrees 
         /// @param theRadians
         /// @return 
         static inline Real toDegrees(float theRadians)
         {
            return (theRadians/PI*180);
         };
         /// @brief operator= 
         /// @param theValue
         /// @return 
         Angle& operator=(const Real theValue);
      private:

         Real mValue;
         Real mSin;
         Real mCos;
   };
}
#endif   
