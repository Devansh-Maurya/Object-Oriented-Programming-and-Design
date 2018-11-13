cmake_minimum_required(VERSION 3.12)
project(Polynomial)

set(CMAKE_CXX_STANDARD 14)

add_executable(Polynomial main.cpp Polynomial.cpp Term.cpp)