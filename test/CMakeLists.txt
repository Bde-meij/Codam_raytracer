set(TEST_EXECUTABLE_NAME minirt_unit_tests)

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

# Download GoogleTest
# --------------------------------------------------
include(GoogleTest)
include(FetchContent)

FetchContent_Declare(
	googletest
	DOWNLOAD_EXTRACT_TIMESTAMP
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG v1.13.0
)
FetchContent_MakeAvailable(googletest)

list(TRANSFORM SRCS PREPEND ../)

# Tests
# --------------------------------------------------
add_executable(
	${TEST_EXECUTABLE_NAME}
	${SRCS}
	camera_test.cpp
)

target_compile_options(${TEST_EXECUTABLE_NAME} PRIVATE -g -fsanitize=address)
target_link_options(${TEST_EXECUTABLE_NAME} PRIVATE -g -fsanitize=address)

target_include_directories(${TEST_EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

target_link_libraries(
	${TEST_EXECUTABLE_NAME}
	vec3
	ft
	mlx42
	get_next_line
	GTest::gtest_main
)

# Add tests to CTest
# Set working directory to the the testing folder so that the test can find their test files
# --------------------------------------------------
gtest_discover_tests(${TEST_EXECUTABLE_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} TEST_PREFIX "miniRT/")
enable_testing()