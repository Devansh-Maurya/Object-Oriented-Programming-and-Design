cmake_minimum_required(VERSION 3.12)
project(Account)

set(CMAKE_CXX_STANDARD 14)

add_executable(Account main.cpp Account.cpp SavingsAccount.cpp CheckingAccount.cpp)