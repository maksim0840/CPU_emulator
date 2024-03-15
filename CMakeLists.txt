cmake_minimum_required(VERSION 3.24)
project(CPU_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main main.cpp)

add_subdirectory(libs/Stack)
add_subdirectory(libs/CPU)
add_subdirectory(libs/Parser)
add_subdirectory(test)

target_link_libraries(CPU Stack)
target_link_libraries(main Parser CPU)
target_link_libraries(test_file Parser CPU)

target_include_directories(main PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Parser/include"
                          "${PROJECT_SOURCE_DIR}/libs/CPU/include"
)
target_include_directories(test_file PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/libs/Parser/include"
                          "${PROJECT_SOURCE_DIR}/libs/CPU/include"
)
