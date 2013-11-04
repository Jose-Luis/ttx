set(GAMESTATES_FILES 
   ${SRCROOT}/gameStates/IActionState.cpp
   ${SRCROOT}/gameStates/GameStateOne.cpp
   ${INCROOT}/gameStates/IActionState.hpp
   ${INCROOT}/gameStates/GameStateOne.hpp)

add_library(gameStates ${GAMESTATES_FILES})

target_link_libraries(
   gameStates
      systems
      protos
      objects
      mapLoader
      particles
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
)
