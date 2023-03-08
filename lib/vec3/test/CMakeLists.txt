set(TEST_EXECUTABLE_NAME vec3_unit_tests)

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

# Tests
# --------------------------------------------------
add_executable(
	${TEST_EXECUTABLE_NAME}
	constructors.cpp
	basic_calculations.cpp
	advanced_calculations.cpp
)

target_compile_options(${TEST_EXECUTABLE_NAME} PRIVATE -g -fsanitize=address)
target_link_options(${TEST_EXECUTABLE_NAME} PRIVATE -g -fsanitize=address)

target_link_libraries(
	${TEST_EXECUTABLE_NAME}
	vec3
	GTest::gtest_main
)


# Add tests to CTest
# Set working directory to the the testing folder so that the test can find their test files
# --------------------------------------------------
gtest_discover_tests(${TEST_EXECUTABLE_NAME} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} TEST_PREFIX "vec/")
enable_testing()