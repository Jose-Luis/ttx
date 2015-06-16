project(TTX)

set(TTX_MAJOR 0)
set(TTX_MINOR 0)
set(TTX_PATCH 0)
set(TTX_VERSION ${TTX_MAJOR}.${TTX_MINOR}.${TTX_PATCH})
set(TTX_DESCRIPTION "ThingsThatXplote")
set(TTX_EXENAME "TTX")
set(TTX_PACKAGENAME "TTX")
set(TTX_HOMEPAGE "http://www.TTxshooter.org")
 
cmake_minimum_required (VERSION 2.8)

#set(CMAKE_CXX_COMPILER "g++")
set(EXT_LIBS ${PROJECT_SOURCE_DIR}/ext_libs)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/Modules)

include_directories(${PROJECT_SOURCE_DIR}/include)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
   set(BITS 64) 
else()
   set(BITS 32) 
endif()

if (${UNIX})
   set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/linux${BITS})
else()
   set(EXT_LIBS_DIR ${EXT_LIBS}/libraries/win${BITS})
endif()

#========= LIBRARIES ==========================
set(GQE_STATIC_LIBRARIES TRUE)
find_package(GQE REQUIRED) 
include_directories(${GQE_INCLUDE_DIR})
#==
find_package(Box2D REQUIRED) 
include_directories(${BOX2D_INCLUDE_DIR})
#==
find_package(TinyXML2 REQUIRED)
include_directories(${TINYXML2_INCLUDE_DIR})
#==
find_package(GT REQUIRED)
include_directories(${GT_INCLUDE_DIR})
#==
find_package(MPE REQUIRED)
include_directories(${MPE_INCLUDE_DIR})

#SFML
#====
find_package(SFML REQUIRED graphics window audio network system)
include_directories(${SFML_INCLUDE_DIR})

if(MSVC)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W3")
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -Wall -pedantic")
endif()

ADD_DEFINITIONS(-DSFML_DYNAMIC)
ADD_DEFINITIONS(-DGQE_STATIC)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/TTX)
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/TTX)

set(RESOURCES_PATH ${PROJECT_BINARY_DIR}/bin/resources)
execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/resources ${RESOURCES_PATH})
add_subdirectory(src)

# CPack version numbers for release tarball name.
set(CPACK_PACKAGE_VERSION_MAJOR ${TTX_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${TTX_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${TTX_PATCH})

#And then there's ways to customize this as well
set(CPACK_DMG_VOLUME_NAME "ttx")
set(CPACK_BINARY_DRAGNDROP ON)
include(CPack)

################################################################
# Summary
################################################################

message( "" )
message( "Summary:" )
message( "  CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}" )
message( "  WIN32 = ${WIN32}" )
message( "  UNIX = ${UNIX}" )
message( "  APPLE = ${APPLE}" )
message( "  CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}" )
message( "  CMAKE_INSTALL_PREFIX = ${CMAKE_INSTALL_PREFIX}" )
message( "  CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}" )
message( "  CMAKE_GENERATOR = ${CMAKE_GENERATOR}" )
message( "  GQE_LIBRARIES = ${GQE_LIBRARIES}" )
message( "  SFML_LIBRARIES = ${SFML_LIBRARIES}" )
message( "  BOX2D_LIBRARY = ${BOX2D_LIBRARY}" )
message( "  GT_LIBRARY = ${GT_LIBRARY}" )
message( "  TINYXML2_LIBRARY = ${TINYXML2_LIBRARY}" )
message( "  MPE_LIBRARY = ${MPE_LIBRARY}" )
message( "" )
