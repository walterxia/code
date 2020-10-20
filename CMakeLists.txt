cmake_minimum_required(VERSION 3.0.0)
project(algocode VERSION 0.1.0)

#显示指定使用的C++编译器 
#set(CMAKE_CXX_COMPILER "g++")
#set (CMAKE_CXX_FLAGS  "-g -fexec-charset=GBK")

#include(CTest)
#enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/inc)
aux_source_directory(./src/ SrcFiles)

#set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/Bin)
add_executable(algocode ${SrcFiles} demo.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
