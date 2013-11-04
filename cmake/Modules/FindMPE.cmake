
# Locate MPE library 
# This module defines 
# MPE_LIBRARY, the name of the library to link against 
# MPE_FOUND, if false, do not try to link to MPE
# MPE_INCLUDE_DIR, where to find MPE headers 
# 
# Created by Sven-Hendrik Haase. Based on the FindZLIB.cmake module.

IF(MPE_INCLUDE_DIR)
  # Already in cache, be silent
  SET(MPE_FIND_QUIETLY TRUE)
ENDIF(MPE_INCLUDE_DIR)

FIND_PATH(MPE_INCLUDE_DIR MPE/MPE.hpp
  PATH_SUFFIXES include
  PATHS
  ${EXT_LIBS})

FIND_LIBRARY(MPE_RELEASE_LIBRARY NAMES particles PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})
FIND_LIBRARY(MPE_DEBUG_LIBRARY NAMES particles_debug PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})

IF(MPE_RELEASE_LIBRARY)
    IF(MPE_DEBUG_LIBRARY)
        SET(MPE_LIBRARY optimized "${MPE_RELEASE_LIBRARY}" debug "${MPE_DEBUG_LIBRARY}")
    ELSE()
        SET(MPE_LIBRARY "${MPE_RELEASE_LIBRARY}")        # Could add "general" keyword, but it is optional
    ENDIF()
ENDIF()

MARK_AS_ADVANCED(MPE_LIBRARY MPE_RELEASE_LIBRARY MPE_DEBUG_LIBRARY MPE_INCLUDE_DIR)

# Per-recommendation
SET(MPE_INCLUDE_DIRS "${MPE_INCLUDE_DIR}")
SET(MPE_LIBRARIES    "${MPE_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set MPE_FOUND to TRUE if 
# all listed variables are TRUE

#INCLUDE(FindPackageHandleStandardArgs) 
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(MPE DEFAULT_MSG MPE_LIBRARY MPE_INCLUDE_DIR) 
