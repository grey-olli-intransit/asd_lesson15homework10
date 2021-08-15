cmake_minimum_required(VERSION 2.8)
add_compile_options(-Wall -g)
project(l15hw10)
add_executable(l15hw10 src/l15hw10.c)
target_include_directories(l15hw10 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(l15hw10 PRIVATE m)

