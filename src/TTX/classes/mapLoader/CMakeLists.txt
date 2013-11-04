set(MAPLOADER_FILES 
   ${INCROOT}/classes/mapLoader/MapLoader.hpp
   ${SRCROOT}/classes/mapLoader/MapLoader.cpp)

add_library(mapLoader ${MAPLOADER_FILES})

target_link_libraries ( mapLoader  ${TINYXML2_LIBRARIES})
