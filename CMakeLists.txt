cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(
        SOURCE_FILES
        src/orders/PhoneNumber.cpp
        src/orders/PhoneNumber.h
        src/orders/EmailAddress.cpp
        src/orders/EmailAddress.h
        src/orders/IpAddress.cpp
        src/orders/IpAddress.h
        src/process/Process.cpp
        src/process/Process.h
        src/utils/SafeQueue.hpp
        src/IOrder.h
        src/Main.cpp
        src/Main.h
        src/OrderReader.cpp
        src/OrderReader.h
)

add_executable(cpp_plazza ${SOURCE_FILES})
