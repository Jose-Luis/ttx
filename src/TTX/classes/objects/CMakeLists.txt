set(OBJECTS_FILES 
                    ${INCROOT}/classes/objects/Propeller.hpp
                    ${INCROOT}/classes/objects/Weapon.hpp
                    ${SRCROOT}/classes/objects/Propeller.cpp
                    ${SRCROOT}/classes/objects/Weapon.cpp)

add_library(objects ${OBJECTS_FILES})

target_link_libraries(
   objects
      ${SFML_LIBRARIES}
      ${MPE_LIBRARIES}
      ${GT_LIBRARIES}
      ${GQE_LIBRARIES}
      ${BOX2D_LIBRARY}
)
