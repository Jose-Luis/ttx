set(TTXAPP_FILES 
   ${INCROOT}/app/TTXapp.hpp
   ${SRCROOT}/app/TTXapp.cpp)
add_library( TTXapp ${TTXAPP_FILES})
target_link_libraries(
   TTXapp 
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
      gameStates
)
