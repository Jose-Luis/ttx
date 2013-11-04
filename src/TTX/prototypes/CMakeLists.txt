add_subdirectory(components)

set(PROTOTYPE_FILES
   ${INCROOT}/prototypes/Rombo.hpp
   ${INCROOT}/prototypes/Box.hpp
   ${INCROOT}/prototypes/BasicShip.hpp
   ${INCROOT}/prototypes/Ground.hpp
   ${INCROOT}/prototypes/Player.hpp
   ${INCROOT}/prototypes/SimpleBullet.hpp
   ${SRCROOT}/prototypes/Rombo.cpp
   ${SRCROOT}/prototypes/Box.cpp
   ${SRCROOT}/prototypes/BasicShip.cpp
   ${SRCROOT}/prototypes/Ground.cpp
   ${SRCROOT}/prototypes/Player.cpp
   ${SRCROOT}/prototypes/SimpleBullet.cpp)

add_library(protos  ${PROTOTYPE_FILES})

target_link_libraries(
   protos
      proto_components
      #${SFML_LIBRARIES}
      #${GQE_LIBRARIES}
      #${BOX2D_LIBRARY}
)
