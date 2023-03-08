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


# Tests, only if the build type is test and the project is the main project
# -----------------------------------------------------------------------
if (CMAKE_BUILD_TYPE STREQUAL "Test")
	add_subdirectory(test)
	enable_testing()
endif()
