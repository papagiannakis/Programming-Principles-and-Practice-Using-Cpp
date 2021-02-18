cmake_minimum_required(VERSION 3.0.0)
project(sect4 VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)


include(CTest)
enable_testing()

add_executable(sect4_4_try1 sect4_4_try1.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
