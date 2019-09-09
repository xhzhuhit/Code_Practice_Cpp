cmake_minimum_required(VERSION 2.8)
project(testMultiThread)

add_definitions(-std=c++11)
add_executable(testMultiThread
        src/main.cpp)
target_link_libraries(testMultiThread
        pthread
        )
add_executable(testNotify
        src/notify.cpp)
target_link_libraries(testNotify
        pthread
        )
