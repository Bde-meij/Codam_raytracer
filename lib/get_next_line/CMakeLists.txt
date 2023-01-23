cmake_minimum_required(VERSION 3.21.0)

project(get_next_line)


set (SRCS
get_next_line.c
get_next_line_utils.c
)

add_library(get_next_line STATIC ${SRCS})

target_include_directories(get_next_line PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)