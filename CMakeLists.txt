cmake_minimum_required(VERSION 3.30)
project(leet_35 C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED 11)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg -fsanitize=address -ggdb")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg -fsanitize=address -ggdb")

add_executable(${PROJECT_NAME} src/main.c)
add_subdirectory(src/include)
