cmake_minimum_required(VERSION 4.0)
project(prod)

set(CMAKE_CXX_STANDARD 26)

add_executable(prod main.cpp doubly_linked_list.cpp doubly_linked_list.h solution.cpp solution.h correct_number.cpp correct_number.h)
