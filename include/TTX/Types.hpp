
#ifndef  TYPES_INC
#define  TYPES_INC
#include <map>
#include <string>
#include <GQE/Entity/interfaces/IEntity.hpp>

class ISystem;

const float PI = 3.14159265359f;
const float HALF_PI = 3.14159265359f / 2;
const float TWO_PI = 3.14159265359f * 2;
const float UPDATE_RATE = 60;
const float SPU = 1.0f / UPDATE_RATE;
const float TORAD = PI / 180;
const float TODEG = 180 / PI;
const float LENGTHFACTOR = 16;

typedef std::string ID;
typedef std::string SystemID;
typedef std::string EntityID;
typedef std::string WeaponID;
typedef std::string AmunitionID;
typedef unsigned int InstanceID;

typedef std::map<SystemID, ISystem*> SystemContainer;
typedef std::map<EntityID, GQE::IEntity*> ChildrenContainer;
typedef std::map<int, InstanceID> PlayerContainer;

struct Position2D
{
   Position2D():
      x(0), y(0), angle(0)
   {}

   Position2D(float theX, float theY, float theAngle):
      x(theX), y(theY), angle(theAngle)
   {}

   Position2D operator-(const Position2D& theOther) const
   {
      return (Position2D(x - theOther.x, y - theOther.y, angle - theOther.angle));
   }

   Position2D operator*(const float& theOther) const
   {
      return (Position2D(x * theOther, y * theOther, angle));
   }

   Position2D operator-=(const Position2D& theOther) const
   {
      return (Position2D(x - theOther.x, y - theOther.y, angle - theOther.angle));
   }

   Position2D operator+=(const Position2D& theOther) const
   {
      return (Position2D(x + theOther.x, y + theOther.y, angle + theOther.angle));
   }

   Position2D operator+(const Position2D& theOther) const
   {
      return (Position2D(x + theOther.x, y + theOther.y, angle + theOther.angle));
   }

   float x, y, angle;
};

typedef Position2D Transform;

struct MoveData
{
   float x, y;
   bool  move, turn;
};

struct FireData
{};

enum Layers
{
   BACK_1, BACK_2,
   OBJT_1, OBJT_2,
   PART_1, PART_2,
   FORE_1, FORE_2
};

enum ObjectCategories
{
   FRIENDLY_SHIP = 0x0001,
   FRIENDLY_BULLET = 0x0002,
   SCENE = 0x0004,
   ENEMY_SHIP = 0x0008,
   ENEMY_BULLET = 0x0010,
   ALL = 0xFFFF
};
#endif   // ----- #ifndef TYPES_INC  -----

