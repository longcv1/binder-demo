cmake_minimum_required(VERSION 3.0)

project(binder-demo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#find_library(ProtobufShared protobuf)

add_subdirectory(binder-control)
add_subdirectory(libs)
add_subdirectory(test_service)
add_subdirectory(servicemanager)
