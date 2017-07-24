cmake_minimum_required(VERSION 2.8)

project(STLIterator2)

file(GLOB SRC
    "*.h"
    "*.cpp"
)
add_executable(STLIterator2 ${SRC})