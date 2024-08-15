cmake_minimum_required(VERSION 3.16)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED COMPONENTS system filesystem thread)
link_directories(/opt/homebrew/Cellar/cpprestsdk/2.10.19/lib)  # Add this line

add_executable(ChessEngine main.cpp
        defs.h
        init.cpp
        bitboards.cpp
        hashkeys.cpp
        board.cpp
        data.cpp)

target_link_libraries(ChessEngine PRIVATE Boost::system Boost::filesystem Boost::thread cpprest)
