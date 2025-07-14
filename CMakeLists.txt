cmake_minimum_required(VERSION 3.16)
project(ShootingGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(main src/main.cpp
        src/Bullet.cpp
        include/Bullet.h)

find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics)

target_link_libraries(main sfml-system sfml-window sfml-graphics)