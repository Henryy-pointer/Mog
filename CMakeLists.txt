cmake_minimum_required(VERSION 3.20)
project(renderer)

set(SOURCES
  src/main.c
  src/platform/X11/window.c
  src/Scene.c
  src/app/image.c
)

add_executable(renderer ${SOURCES})

find_package(X11 REQUIRED)

target_include_directories(renderer PRIVATE ${X11_INCLUDE_DIR}
src/
)
target_link_libraries(renderer ${X11_LIBRARIES})
