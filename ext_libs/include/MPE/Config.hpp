/// @file Config.hpp
/// @brief
/// @author Jose Luis Lavado
/// @version 0.1
/// @date 2013-10-05

#ifndef  CONFIG_MPE_INC
#define  CONFIG_MPE_INC

#include <string>
#include <limits>
#include <cmath>
#include <memory>

namespace mpe
{
class System;
class Focus;
class Affector;
class Emitter;
class Particle;
class Mortal;
class Position;

typedef int Integer;
typedef float Real;
typedef std::string EmitterID;
typedef unsigned char GroupID;
typedef std::shared_ptr<Focus> FocusPtr;
typedef std::shared_ptr<Affector> AffectorPtr;

const bool FIXED = true;
const bool NON_FIXED = false;

const Integer MAX_INTEGER = std::numeric_limits<Integer>::max();
const Real REAL_INFINITY = std::numeric_limits<Real>::infinity();

const GroupID NO_GROUP = 0x00;
const GroupID GROUP_A = 0x01;
const GroupID GROUP_B = 0x02;
const GroupID GROUP_C = 0x04;
const GroupID GROUP_D = 0x08;
const GroupID GROUP_E = 0x10;
const GroupID GROUP_F = 0x20;
const GroupID GROUP_G = 0x40;
const GroupID GROUP_H = 0x80;

struct Color
{
   Integer r, g, b, a;
};

struct TextRect
{
   Integer x, y, width, height;
};
}
#endif   // ----- #ifndef CONFIG_INC  -----

