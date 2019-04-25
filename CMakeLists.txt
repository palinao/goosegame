cmake_minimum_required(VERSION 3.6)

project(GooseGame VERSION 1.0 LANGUAGES C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

add_library(GameUtility SHARED GameUtility.c)

add_executable(GameServer GameServer.c)

add_executable(GameClient GameClient.c)

target_link_libraries(GameServer LINK_PUBLIC GameUtility)
