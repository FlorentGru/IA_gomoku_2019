cmake_minimum_required(VERSION 3.9)
project(AIA_gomoku_2019)
set(CMAKE_CXX_STANDARD 14)

include_directories(sources/ sources/brain)
add_executable(pbrain-gomoku-ai sources/main.cpp sources/Protocol.cpp sources/Launcher.cpp sources/brain/Brain.cpp sources/brain/Board.cpp)