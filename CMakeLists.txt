cmake_minimum_required(VERSION 3.15)
project(cornerstone2 C CXX)

add_executable(cornerstone2 main.cpp)

# Disable tests for protobuf
set(protobuf_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/third-party/protobuf/cmake)

target_include_directories(cornerstone2 PRIVATE ${CMAKE_SOURCE_DIR}/third-party/protobuf/src/google/protobuf)

target_link_libraries(cornerstone2 -lprotobuf)