/// @file Position.hpp
/// @author Jose Luis Lavado
/// @version 0.2
/// @date 2013-01-10

#ifndef  POSITION_INC
#define  POSITION_INC

#include <MPE/Config.hpp>
#include <GT/GT.hpp>

namespace mpe
{
class Position
{

   public:

      /// @brief getPosition 
      /// @return 
      gt::Vec2D getPosition() const
      {
         return mPosition;
      }
      /// @brief setPosition 
      /// @param thePosition
      void setPosition(gt::Vec2D thePosition)
      {
         mPosition=thePosition;
      }
      /// @brief setPosition 
      /// @param theX
      /// @param theY
      void setPosition(Real theX,Real theY)
      {
         mPosition.x = theX;
         mPosition.y = theY;
      }
      /// @brief move 
      /// @param theXOffset
      /// @param theYOffset
      void move(Real theXOffset,Real theYOffset)
     {
         mPosition.x += theXOffset;
         mPosition.y += theYOffset;
      }
      /// @brief move 
      /// @param theOffset
      void move(gt::Vec2D theOffset)
      {
         mPosition += theOffset;
      }
     
   protected:

      Position(gt::Vec2D thePosition);
      gt::Vec2D mPosition;
};
}
#endif   // ----- #ifndef POSITION_INC  -----
