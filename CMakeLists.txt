cmake_minimum_required(VERSION 3.20)
project(renderer)

set(SOURCES
  window.c
)

add_executable(renderer ${SOURCES})

find_package(X11 REQUIRED)

target_include_directories(renderer PRIVATE ${X11_INCLUDEW_DIR})
target_link_libraries(renderer ${X11_LIBRARIES})
