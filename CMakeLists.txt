cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads)

set(
        SOURCE_FILES
        src/orders/PhoneNumber.cpp
        src/orders/PhoneNumber.h
        src/orders/EmailAddress.cpp
        src/orders/EmailAddress.h
        src/orders/IpAddress.cpp
        src/orders/IpAddress.h
        src/utils/Exception.cpp
        src/utils/Exception.hpp
        src/utils/Fork.cpp
        src/utils/Fork.hpp
        src/utils/ISafeQueue.hpp
        src/utils/SafeQueue.hpp
        src/IOrder.h
        src/Main.cpp
        src/Main.h
        src/OrderReader.cpp
        src/OrderReader.h
)

add_executable(cpp_plazza ${SOURCE_FILES})
target_link_libraries(cpp_plazza ${CMAKE_THREAD_LIBS_INIT})
