cmake_minimum_required(VERSION 3.20)
project(Mog)

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
  src/renderer/model.c
  src/renderer/framebuffer-functions.c
)

add_executable(Mog ${SOURCES})

find_package(X11 REQUIRED)

target_include_directories(Mog PRIVATE ${X11_INCLUDE_DIR}
src/
src/renderer
src/platform/X11
)
target_link_libraries(Mog ${X11_LIBRARIES} m)
