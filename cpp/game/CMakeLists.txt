cmake_minimum_required(VERSION 2.8)

project(game)

#set (CMAKE_CXX_FLAGS "-std=c++11")

set (CMAKE_BUILD_TYPE "Debug")

add_library(gamelib Hero.cpp Knife.cpp Monster.cpp Sword.cpp)

add_executable(game game.cpp)

target_link_libraries(game gamelib)
