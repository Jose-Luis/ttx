set(PROTOTYPE_FILES
   ${INCROOT}/prototypes/PhysicProto.hpp
   ${INCROOT}/prototypes/Box.hpp
   ${INCROOT}/prototypes/BasicShip.hpp
   ${INCROOT}/prototypes/Player.hpp
   ${INCROOT}/prototypes/SimpleBullet.hpp
   ${SRCROOT}/prototypes/PhysicProto.cpp
   ${SRCROOT}/prototypes/Box.cpp
   ${SRCROOT}/prototypes/BasicShip.cpp
   ${SRCROOT}/prototypes/Player.cpp
   ${SRCROOT}/prototypes/SimpleBullet.cpp
   ${SRCROOT}/prototypes/Machinegun.cpp)

add_library(protos  ${PROTOTYPE_FILES})

target_link_libraries(
   protos
)
