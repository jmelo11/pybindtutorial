
cmake_minimum_required(VERSION 3.10)

# set the project name
project(
  FinLib
  VERSION 1.0
  LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# header and source files
file(GLOB SOURCES "*.cpp")
file(GLOB HEADERS "*.hpp")

# add the executable
add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

