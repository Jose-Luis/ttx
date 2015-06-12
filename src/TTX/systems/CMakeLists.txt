set(SYSTEMS_FILES
   ${INCROOT}/systems/ISystem.hpp
   ${INCROOT}/systems/RenderSystem.hpp
   ${INCROOT}/systems/PlayerSystem.hpp
   ${INCROOT}/systems/PropellerSystem.hpp
   ${INCROOT}/systems/AnimationSystem.hpp
   ${INCROOT}/systems/HealthSystem.hpp
   ${INCROOT}/systems/PhysicSystem.hpp
   ${SRCROOT}/systems/ISystem.cpp
   ${SRCROOT}/systems/RenderSystem.cpp
   ${SRCROOT}/systems/PlayerSystem.cpp
   ${SRCROOT}/systems/PropellerSystem.cpp
   ${SRCROOT}/systems/HealthSystem.cpp
   ${SRCROOT}/systems/PhysicSystem.cpp
   ${SRCROOT}/systems/ActorSystem.cpp
   ${SRCROOT}/systems/WeaponSystem.cpp
   ${SRCROOT}/systems/AnimationSystem.cpp)

add_library(systems ${SYSTEMS_FILES}) 

target_link_libraries(
   systems
      ${BOX2D_LIBRARY}
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
)
