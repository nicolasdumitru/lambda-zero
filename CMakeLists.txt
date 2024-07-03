cmake_minimum_required(VERSION 3.29)

project(
  lambdazero
  VERSION 1.0
  LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

set(SOURCES
    src/command.hpp
    src/command.cpp
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
