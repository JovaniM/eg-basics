cmake_minimum_required(VERSION 3.14)
project(EG-BASICS)
set(CMAKE_CXX_STANDARD 17)

# here we include external libraries
include(FetchContent)
FetchContent_Declare(
  sdl2
  REQUIRED
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG        e11183ea6caa3ae4895f4bc54cad2bbb0e365417
)

FetchContent_MakeAvailable(sdl2)

FetchContent_Declare(
  sdl2_image
  GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
  GIT_TAG        release-2.8.2
)
FetchContent_MakeAvailable(sdl2_image)

add_executable(
  EG-BASICS
  src/main.cpp
  src/core/Game.cpp
  src/core/Window.cpp
  src/graphics/Sprite.cpp
)
  
target_include_directories(EG-BASICS PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_link_libraries(
    EG-BASICS
    PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2_image::SDL2_image
)      

add_custom_target(copy_assets ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    ${CMAKE_BINARY_DIR}/assets)
add_dependencies(EG-BASICS copy_assets)

if (MSVC)
  target_compile_options(EG-BASICS PRIVATE /W4 /permissive-)
else()
  target_compile_options(EG-BASICS PRIVATE -Wall -Wextra -Wpedantic)
endif()