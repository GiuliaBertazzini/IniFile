cmake_minimum_required(VERSION 3.9)
project(LaboratorioProgrammazione)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES IniFileManager.cpp IniFileManager.h)
add_executable(LaboratorioProgrammazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(LaboratorioProgrammazione core)