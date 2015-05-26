/// @file Interfaces.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-01-10


#ifndef  MORTAL_INC
#define  MORTAL_INC

#include <MPE/Config.hpp>

namespace mpe
{
class Mortal
{

   public:

      /// @brief isAlive 
      /// @return 
      inline bool isAlive()
      {
         return mAlive;
      }
      /// @brief kill 
      inline void kill()
      {
         mAlive=false;
      }
      /// @brief getAge 
      /// @return 
      inline Real getAge() const
      {
         return mAge;
      }

   protected:

      /// @brief Mortal 
      /// @param theLifetime
      Mortal(Real theLifetime);
      /// @brief age 
      /// @param theElapsedTime
      inline void age(Real theElapsedTime)
      {
         mAge += theElapsedTime;
         if (mAge > mLifetime)
            die();
      }

   private:

      bool mAlive;
      Real mLifetime;
      Real mAge;
      /// @brief die 
      inline void die()
      {
         mAlive=false;
      }
};

}
#endif   
