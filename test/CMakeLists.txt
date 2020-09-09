cmake_minimum_required(VERSION 3.9)
project(test)

set(CMAKE_CXX_STANDARD  11)
add_subdirectory(/home/giulia/CLionProjects/IniFile/test/lib/googletest)
set(gtest_SOURCE_DIR, /home/giulia/CLionProjects/IniFile/test/lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(SOURCE_FILES test.cpp)
add_executable(test runAllTest.cpp ${SOURCE_FILES})
target_link_libraries(test gtest gtest_main core)
