cmake_minimum_required(VERSION 3.5)
project(cpp_plazza)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Threads)

include_directories(include)

set(
        SOURCE_FILES

        include/IConnector.hpp
        include/IObservable.hpp
        include/IObserver.hpp
        include/IOrder.hpp
        include/ISafeQueue.hpp

        src/orders/AOrder.cpp
        src/orders/AOrder.hpp
        src/orders/EmailAddress.cpp
        src/orders/EmailAddress.hpp
        src/orders/IpAddress.cpp
        src/orders/IpAddress.hpp
        src/orders/PhoneNumber.cpp
        src/orders/PhoneNumber.hpp

        src/process/OrderDispatcher.cpp
        src/process/OrderDispatcher.hpp
        src/process/Process.cpp
        src/process/Process.hpp

        src/utils/Client.hpp
        src/utils/Decrypt.cpp
        src/utils/Decrypt.hpp
        src/utils/Exception.cpp
        src/utils/Exception.hpp
        src/utils/Factory.hpp
        src/utils/Fifo.cpp
        src/utils/Fifo.hpp
        src/utils/Fork.cpp
        src/utils/Fork.hpp
        src/utils/Parser.cpp
        src/utils/Parser.hpp
        src/utils/Regex.cpp
        src/utils/SafeQueue.hpp
        src/utils/Server.hpp
        src/utils/ThreadPool.h

        src/Main.cpp
        src/Main.hpp
        src/OrderReader.cpp
        src/OrderReader.hpp
)

add_executable(cpp_plazza ${SOURCE_FILES})
target_link_libraries(cpp_plazza ${CMAKE_THREAD_LIBS_INIT})
