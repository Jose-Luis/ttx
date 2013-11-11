add_library(collision CollisionListener.cpp)
target_link_libraries(collision ${BOX2D_LIBRARY} ${GQE_LIBRARIES})
