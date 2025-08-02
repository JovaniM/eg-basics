cmake_minimum_required(VERSION 3.10)
project(EG-BASICS)
set(CMAKE_CXX_STANDARD 17)

add_executable(EG-BASICS
    src/main.cpp
    src/character/Character.cpp
    src/character/Enemy.cpp
    src/character/Player.cpp
)