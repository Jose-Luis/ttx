set(OBJECTS_FILES 
                    ${INCROOT}/classes/objects/Propeller.hpp
                    ${SRCROOT}/classes/objects/Propeller.cpp
                    ${INCROOT}/classes/objects/WeaponMachinegun.hpp
                    ${SRCROOT}/classes/objects/WeaponMachinegun.cpp
                    ${INCROOT}/classes/objects/WeaponManager.hpp
                    ${SRCROOT}/classes/objects/WeaponManager.cpp)

add_library(objects ${OBJECTS_FILES})

target_link_libraries(
   objects
      ${SFML_LIBRARIES}
      ${MPE_LIBRARIES}
      ${GT_LIBRARIES}
      ${GQE_LIBRARIES}
      ${BOX2D_LIBRARY}
)
