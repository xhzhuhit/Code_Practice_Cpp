cmake_minimum_required(VERSION 2.8)
project(test_reuse_cpp)

add_library(badbad SHARED src/utils/do_something.cpp)

add_executable(test_reuse_cpp src/main.cpp src/do_something.cpp)
target_link_libraries(test_reuse_cpp 
        badbad 
        dl)
