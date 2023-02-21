cmake_minimum_required(VERSION 3.21.0)

project(libvec3)
set (SRCS
	src/add.c
	src/multiply.c
	src/subtract.c
	src/scalar.c
	src/utils.c
	src/new.c
	src/dot.c
	src/divide.c
	src/lenght_squared.c
	src/lenght.c
	src/normalize.c
	src/cross.c
)

add_library(vec3 STATIC ${SRCS})
target_link_libraries(vec3 PRIVATE m)
target_include_directories(vec3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


# -------------- TESTING --------------------

include(cmake/gtest.cmake)

enable_testing()

set(CMAKE_CXX_STANDARD 14)

add_executable(
	unit_tests
	test/constructors.cpp
	test/basic_calculations.cpp
	test/advanced_calculations.cpp
)

target_link_libraries(
	unit_tests
	vec3
	GTest::gtest_main
)

gtest_discover_tests(unit_tests)
