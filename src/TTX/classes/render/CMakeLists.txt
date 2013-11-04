set(RENDER_FILES 
   ${INCROOT}/classes/render/Animation.hpp
   ${INCROOT}/classes/render/Layer.hpp
   ${INCROOT}/classes/render/RenderManager.hpp
   ${SRCROOT}/classes/render/Animation.cpp
   ${SRCROOT}/classes/render/Layer.cpp
   ${SRCROOT}/classes/render/RenderManager.cpp)

add_library( render ${RENDER_FILES})

target_link_libraries(
   render 
      ${SFML_LIBRARIES}
)
