
enable_testing()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(SRC_DIR ${CMAKE_CURRENT_LIST_DIR}/../src)

AUX_SOURCE_DIRECTORY(${SRC_DIR} DIR_SRCS)

# add_library(creator SHARED ${SRC_DIR}/creator.hpp)

include_directories(
    ${SRC_DIR}
)

add_executable(creator_test creator_test.cpp)

target_link_libraries(
    creator_test
    gtest 
    gtest_main
    pthread
)

add_test(NAME creator_test COMMAND creator_test)