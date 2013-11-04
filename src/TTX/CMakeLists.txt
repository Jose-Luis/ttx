add_subdirectory(gameStates)
add_subdirectory(app)
add_subdirectory(prototypes)
add_subdirectory(systems)
add_subdirectory(classes)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
add_executable(TTX main.cpp)
target_link_libraries(
   TTX 
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
      TTXapp
)
