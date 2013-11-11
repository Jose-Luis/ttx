set(PROTOCOMPONENTS_FILES
   ${INCROOT}/prototypes/components/B2Proto.hpp
   ${INCROOT}/prototypes/components/RenderProto.hpp
   ${SRCROOT}/prototypes/components/B2Proto.cpp
   ${SRCROOT}/prototypes/components/RenderProto.cpp
   ${INCROOT}/prototypes/components/HealthProto.hpp
   ${SRCROOT}/prototypes/components/HealthProto.cpp)

add_library(proto_components ${PROTOCOMPONENTS_FILES})

target_link_libraries(
   proto_components
      ${SFML_LIBRARIES}
      ${GQE_LIBRARIES}
      ${BOX2D_LIBRARY}
)
