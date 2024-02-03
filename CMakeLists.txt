cmake_minimum_required(VERSION 3.27)
project(SimpleTask_manager)

set(CMAKE_CXX_STANDARD 17)

add_executable(SimpleTask_manager main.cpp
        Task.cpp
        Task.h)
