cmake_minimum_required(VERSION 3.20)
project(renderer)

set(SOURCES
  src/main.c
  src/platform/X11/window.c
  src/Scene.c
  src/app/image.c
  src/app/cube.c
  src/renderer/matrix-functions.c
  src/renderer/camera.c
  src/renderer/model-transform.c
  src/renderer/projection.c
  src/renderer/rasterizer.c
)

add_executable(renderer ${SOURCES})

find_package(X11 REQUIRED)

target_include_directories(renderer PRIVATE ${X11_INCLUDE_DIR}
src/
src/renderer
src/platform/X11
)
target_link_libraries(renderer ${X11_LIBRARIES} m)
