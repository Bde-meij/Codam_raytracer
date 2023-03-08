set(TEST_EXECUTABLE_NAME unit_tests)

# Download GoogleTest
# --------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
   URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Compile test executable
# --------------------------------------------------
add_executable(
	${TEST_EXECUTABLE_NAME}
	constructors.cpp
	basic_calculations.cpp
	advanced_calculations.cpp
)

# Set C++ standard for test executable, googletest requires C++14
# --------------------------------------------------
set_property(TARGET ${TEST_EXECUTABLE_NAME} PROPERTY CXX_STANDARD 14)

# Link test executable with GoogleTest and vec3 library
# --------------------------------------------------
target_link_libraries(
	${TEST_EXECUTABLE_NAME}
	vec3
	GTest::gtest_main
)

# Add tests to CTest
# --------------------------------------------------
gtest_discover_tests(${TEST_EXECUTABLE_NAME})

enable_testing()
