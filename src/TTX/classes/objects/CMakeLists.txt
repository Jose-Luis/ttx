set(OBJECTS_FILES 
                    ${INCROOT}/classes/objects/Propeller.hpp
                    ${SRCROOT}/classes/objects/Propeller.cpp)

add_library(objects ${OBJECTS_FILES})

target_link_libraries(
   objects
      ${SFML_LIBRARIES}
      ${MPE_LIBRARIES}
      ${GT_LIBRARIES}
      ${GQE_LIBRARIES}
      ${BOX2D_LIBRARY}
)
