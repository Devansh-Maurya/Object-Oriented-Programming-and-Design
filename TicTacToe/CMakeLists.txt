cmake_minimum_required(VERSION 3.12)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 14)

add_executable(TicTacToe main.cpp TicTacToeBoard.cpp TicTacToeBoard.h TicTacToeGame.cpp TicTacToeGame.h)