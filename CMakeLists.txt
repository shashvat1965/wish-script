cmake_minimum_required(VERSION 3.26)
project(wish_script)

set(CMAKE_CXX_STANDARD 17)

add_executable(wish_script main.cpp
        lexer.cpp
        tokens.cpp
        parser.cpp
        interpreter.cpp)
