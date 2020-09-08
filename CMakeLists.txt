cmake_minimum_required(VERSION 3.9)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES iniFileManager.cpp iniFileManager.h)
add_executable(LaboratorioProgrammazione main.cpp IniFileManager.cpp IniFileManager.h test/test.cpp test/runAllTest.cpp)