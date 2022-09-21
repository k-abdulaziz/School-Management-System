cmake_minimum_required(VERSION 3.23)
project(School_Management_System_SLL C)

set(CMAKE_C_STANDARD 90)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(School_Management_System_SLL linked_list.c linked_list.h menu.c menu.h main.c)
