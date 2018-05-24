cmake_minimum_required(VERSION 3.9)
project(algorithms)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_executable(hello_world src/hello_world.cpp)
add_executable(longest_common_subsequence src/longest_common_subsequence.cpp include/longest_common_subsequence.h)
add_executable(longest_increasing_subsequence src/longest_increasing_subsequence.cpp include/longest_increasing_subsequence.h)
add_executable(expedition src/expedition.cpp include/expedition.h)
add_executable(parentheses_balance src/parentheses_balance.cpp include/parentheses_balance.h)
add_executable(binary_color_graph src/bianry_color_graph.cpp include/binaty_color_graph.h)
add_executable(bellman_ford src/bellman_ford.cpp include/bellman_ford.h)
add_executable(dijkstra src/dijkstra.cpp include/dijkstra.h)