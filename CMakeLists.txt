cmake_minimum_required(VERSION 3.0.0)
project(creator VERSION 0.1.0)

SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -std=c++1z -Werror -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

option(ENABLE_TEST "gtest build" OFF)

include(CTest)
enable_testing()

include_directories(
    ${CMAKE_CURRENT_LIST_DIR}/src
    /usr/include
    /usr/local/include
)

link_directories(
    /usr/lib
    /usr/local/lib
)

if(ENABLE_TEST)
    add_subdirectory(gtest)
endif(ENABLE_TEST)

add_executable(${PROJECT_NAME} src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
