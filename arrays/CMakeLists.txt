cmake_minimum_required(VERSION 3.10.2)
project(arrays)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -Wall -Wextra -pedantic -Werror")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address -g -Wall -Wextra -pedantic -Werror")

add_executable(arrays main.cpp Array.h)