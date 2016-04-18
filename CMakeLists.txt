cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads)

set(
        SOURCE_FILES

        src/orders/EmailAddress.cpp
        src/orders/EmailAddress.hpp
        src/orders/IOrder.hpp
        src/orders/IpAddress.cpp
        src/orders/IpAddress.hpp
        src/orders/PhoneNumber.cpp
        src/orders/PhoneNumber.hpp

        src/process/Process.cpp
        src/process/Process.hpp

        src/utils/Exception.cpp
        src/utils/Exception.hpp
        src/utils/Fifo.cpp
        src/utils/Fifo.hpp
        src/utils/Fork.cpp
        src/utils/Fork.hpp
        src/utils/IConnector.hpp
        src/utils/ISafeQueue.hpp
        src/utils/Parser.cpp
        src/utils/Parser.hpp
        src/utils/SafeQueue.hpp
        src/utils/ThreadPool.cpp
        src/utils/ThreadPool.hpp

        src/Main.cpp
        src/Main.h
        src/OrderReader.cpp
        src/OrderReader.h
        src/utils/Factory/Factory.hpp
        src/utils/Factory/Factory.cpp
        src/utils/Factory/IFactoriable.hpp)

add_executable(cpp_plazza ${SOURCE_FILES})
target_link_libraries(cpp_plazza ${CMAKE_THREAD_LIBS_INIT})
