
# Locate ML library 
# This module defines 
# ML_LIBRARY, the name of the library to link against 
# ML_FOUND, if false, do not try to link to ML
# ML_INCLUDE_DIR, where to find ML headers 
# 
# Created by Sven-Hendrik Haase. Based on the FindZLIB.cmake module.

IF(ML_INCLUDE_DIR)
  # Already in cache, be silent
  SET(ML_FIND_QUIETLY TRUE)
ENDIF(ML_INCLUDE_DIR)

FIND_PATH(ML_INCLUDE_DIR MapLoader/map.hpp
  PATH_SUFFIXES include
  PATHS
  ${EXT_LIBS})

FIND_LIBRARY(ML_RELEASE_LIBRARY NAMES  maploader PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})
FIND_LIBRARY(ML_DEBUG_LIBRARY NAMES maploader_debug PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})

IF(ML_RELEASE_LIBRARY)
    IF(ML_DEBUG_LIBRARY)
        SET(ML_LIBRARY optimized "${ML_RELEASE_LIBRARY}" debug "${ML_DEBUG_LIBRARY}")
    ELSE()
        SET(ML_LIBRARY "${ML_RELEASE_LIBRARY}")        # Could add "general" keyword, but it is optional
    ENDIF()
ENDIF()

MARK_AS_ADVANCED(ML_LIBRARY ML_RELEASE_LIBRARY ML_DEBUG_LIBRARY ML_INCLUDE_DIR)

# Per-recommendation
SET(ML_INCLUDE_DIRS "${ML_INCLUDE_DIR}")
SET(ML_LIBRARIES    "${ML_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set ML_FOUND to TRUE if 
# all listed variables are TRUE

#INCLUDE(FindPackageHandleStandardArgs) 
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(ML DEFAULT_MSG ML_LIBRARY ML_INCLUDE_DIR) 
