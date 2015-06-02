set(SYSTEMS_FILES
   ${INCROOT}/systems/ISystem.hpp
   ${INCROOT}/systems/B2System.hpp 
   ${INCROOT}/systems/RenderSystem.hpp
   ${INCROOT}/systems/PlayerSystem.hpp
   ${INCROOT}/systems/PropellerSystem.hpp
   ${INCROOT}/systems/AnimationSystem.hpp
   ${INCROOT}/systems/HealthSystem.hpp
   ${SRCROOT}/systems/ISystem.cpp
   ${SRCROOT}/systems/B2System.cpp 
   ${SRCROOT}/systems/RenderSystem.cpp
   ${SRCROOT}/systems/PlayerSystem.cpp
   ${SRCROOT}/systems/PropellerSystem.cpp
   ${SRCROOT}/systems/HealthSystem.cpp
   ${SRCROOT}/systems/AttachSystem.cpp
   ${SRCROOT}/systems/AnimationSystem.cpp)

add_library(systems ${SYSTEMS_FILES}) 

target_link_libraries(
   systems
      ${BOX2D_LIBRARY}
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
)
