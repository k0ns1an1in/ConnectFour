cmake_minimum_required(VERSION 3.24)
project(ConnectFour)

set(CMAKE_CXX_STANDARD 23)

add_executable(ConnectFour main.cpp GUI.h GUI.cpp Verwaltung.h Verwaltung.cpp Spielfeld.h Spielfeld.cpp)
