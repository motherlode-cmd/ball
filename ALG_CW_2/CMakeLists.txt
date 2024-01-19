cmake_minimum_required(VERSION 3.24)
project(ALG_CW_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(main.cpp TableHash/HashTable.h TableHash/ChainList.h TableHash/Elem.h TableHash/GeneratorTests.h TableHash/ChainList.h)
