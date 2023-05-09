cmake_minimum_required(VERSION 3.13.4)
project(allegro C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-L/usr/local/lib -lalleg -lm")

add_executable(allegro main.c)

target_link_libraries(allegro)