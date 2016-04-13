cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
        src/Main.cpp
        src/Main.h
        src/process/Process.cpp
        src/process/Process.h
        src/IOrder.h
        src/OrderReader.cpp
        src/OrderReader.h
        src/orders/PhoneNumber.cpp
        src/orders/PhoneNumber.h
        src/orders/EmailAddress.cpp
        src/orders/EmailAddress.h
        src/orders/IpAddress.cpp
        src/orders/IpAddress.h
        src/process/ThreadPool.cpp
        src/process/ThreadPool.h
        bootstrap/SafeQueue.cpp bootstrap/includes/SafeQueue.hpp bootstrap/IConVar.cpp bootstrap/includes/IConVar.hpp bootstrap/SafeQueue.cpp bootstrap/includes/CondVar.hpp bootstrap/includes/ThreadPool.cpp bootstrap/includes/ThreadPool.hpp)

add_executable(cpp_plazza ${SOURCE_FILES})
