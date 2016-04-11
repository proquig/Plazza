cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    bootstrap/ex1.cpp
    bootstrap/IMutex.hpp
    bootstrap/ISafeQueue.hpp
    bootstrap/Mutex.hpp
    bootstrap/ScopedLock.hpp
    bootstrap/Thread.hpp bootstrap/Mutex.cpp bootstrap/ScopedLock.cpp)

add_executable(cpp_plazza ${SOURCE_FILES})