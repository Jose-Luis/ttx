/// @file Randomizer.hpp
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2012-12-19

#ifndef  RANDOMIZER_INC
#define  RANDOMIZER_INC

#include <ctime>
#include <cstdlib>
#include <GT/Config.hpp>

namespace gt
{
   class Randomizer
   {
      public:

         /// @brief init 
         static void init()
         {
            std::srand(std::time(NULL));
         }
         /// @brief get 
         /// @param theMin
         /// @param theMax
         /// @return 
         static Real get(Real theMin, Real theMax)
         {
            return (theMax-theMin) * std::rand() / RAND_MAX + theMin;
         }
         /// @brief Randomizer 
         Randomizer();
         /// @brief Randomizer 
         /// @param theA
         /// @param theB
         Randomizer(Real theA,Real theB);
         /// @brief get 
         /// @return 
         Real get() const
         {
            return (mMax-mMin) * std::rand() / RAND_MAX + mMin;
         }
         /// @brief operator() 
         /// @param theMin
         /// @param theMax
         void operator()(Real theA,Real theB);
      private:

         Real mMin;
         Real mMax;
   };
   ////////////////////////////////////////////////////////////////////////////////
}
#endif   // ----- #ifndef RANDOMIZER_INC  -----
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
// 

