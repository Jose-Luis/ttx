set(OBJECTS_FILES 
   ${INCROOT}/classes/listeners/Input.hpp
   ${SRCROOT}/classes/listeners/Input.cpp
   ${INCROOT}/classes/listeners/InputListener.hpp
   ${SRCROOT}/classes/listeners/InputListener.cpp
   ${INCROOT}/classes/listeners/propellers/ShipPropellerListener.hpp
   ${SRCROOT}/classes/listeners/propellers/ShipPropellerListener.cpp
   ${INCROOT}/classes/listeners/weapons/SimpleWeaponListener.hpp
   ${SRCROOT}/classes/listeners/weapons/SimpleWeaponListener.cpp
   ${INCROOT}/classes/listeners/weapons/WeaponManagerListener.hpp
   ${SRCROOT}/classes/listeners/weapons/WeaponManagerListener.cpp
   )

add_library(listeners ${OBJECTS_FILES})

target_link_libraries(
   listeners
      ${SFML_LIBRARIES}
      ${MPE_LIBRARIES}
      ${GT_LIBRARIES}
      ${GQE_LIBRARIES}
      ${BOX2D_LIBRARY})
