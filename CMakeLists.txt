cmake_minimum_required(VERSION 3.13)
project(crystal_monsters)
set(CMAKE_CXX_STANDARD 14)
add_executable(crystal_monsters src/main.cpp src/graphics.cpp src/game.cpp src/input.cpp src/sprite.cpp src/character.cpp)

include_directories(src/headers)

find_package(SDL2 REQUIRED)
target_link_libraries(crystal_monsters /Library/Frameworks/SDL2.framework)
target_link_libraries(crystal_monsters /Library/Frameworks/SDL2_image.framework)