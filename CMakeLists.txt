cmake_minimum_required (VERSION 2.6)

project (EasyChain)

set (EasyChain_VERSION_MAJOR 0)
set (EasyChain_VERSION_MINOR 1)
set (CMAKE_CXX_STANDAR 11)
set (CMAKE_BUILD_TYPE Debug)

include_directories("${CMAKE_SOURCE_DIR}/include")

add_executable(EasyChain main.cpp include/block.h include/block.cpp)
