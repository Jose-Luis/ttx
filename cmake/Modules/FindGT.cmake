
# Locate GT library 
# This module defines 
# GT_LIBRARY, the name of the library to link against 
# GT_FOUND, if false, do not try to link to GT
# GT_INCLUDE_DIR, where to find GT headers 
# 
# Created by Sven-Hendrik Haase. Based on the FindZLIB.cmake module.

IF(GT_INCLUDE_DIR)
  # Already in cache, be silent
  SET(GT_FIND_QUIETLY TRUE)
ENDIF(GT_INCLUDE_DIR)

FIND_PATH(GT_INCLUDE_DIR GT/GT.hpp
  PATH_SUFFIXES include
  PATHS
  ${EXT_LIBS})

FIND_LIBRARY(GT_RELEASE_LIBRARY NAMES  geotools PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})
FIND_LIBRARY(GT_DEBUG_LIBRARY NAMES  geotools_debug PATH_SUFFIXES lib PATHS ${EXT_LIBS_DIR})

IF(GT_RELEASE_LIBRARY)
    IF(GT_DEBUG_LIBRARY)
        SET(GT_LIBRARY optimized "${GT_RELEASE_LIBRARY}" debug "${GT_DEBUG_LIBRARY}")
    ELSE()
        SET(GT_LIBRARY "${GT_RELEASE_LIBRARY}")        # Could add "general" keyword, but it is optional
    ENDIF()
ENDIF()

MARK_AS_ADVANCED(GT_LIBRARY GT_RELEASE_LIBRARY GT_DEBUG_LIBRARY GT_INCLUDE_DIR)

# Per-recommendation
SET(GT_INCLUDE_DIRS "${GT_INCLUDE_DIR}")
SET(GT_LIBRARIES    "${GT_LIBRARY}")

# handle the QUIETLY and REQUIRED arguments and set GT_FOUND to TRUE if 
# all listed variables are TRUE

#INCLUDE(FindPackageHandleStandardArgs) 
#FIND_PACKAGE_HANDLE_STANDARD_ARGS(GT DEFAULT_MSG GT_LIBRARY GT_INCLUDE_DIR) 
