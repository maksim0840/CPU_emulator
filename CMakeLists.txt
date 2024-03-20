cmake_minimum_required(VERSION 3.24)
project(CPU_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Test coverage flags
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")

# Include "gtest" library
include(FetchContent)
FetchContent_Declare(
 googletest
 URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(main main.cpp)

add_subdirectory(libs/Stack)
add_subdirectory(libs/CPU)
add_subdirectory(libs/Parser)

target_link_libraries(CPU Stack)
target_link_libraries(main Parser CPU)
target_link_libraries(test_Parser Parser GTest::gtest_main)
target_link_libraries(test_Stack Stack GTest::gtest_main)
target_link_libraries(test_CPU CPU GTest::gtest_main)

target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Parser/include"
                          "${PROJECT_SOURCE_DIR}/libs/CPU/include"
)
target_include_directories(test_Parser PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Parser/include"
)
target_include_directories(test_Stack PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Stack/include"
)
target_include_directories(test_CPU PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Stack/include"
                          "${PROJECT_SOURCE_DIR}/libs/CPU/include"
)
