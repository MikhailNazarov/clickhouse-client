cmake_minimum_required(VERSION 3.21)
project(clickhouse_client)

set(CMAKE_CXX_STANDARD 20)
find_package(boost REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

add_subdirectory(src)
add_subdirectory(tests)

add_subdirectory(examples)