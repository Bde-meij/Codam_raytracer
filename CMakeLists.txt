cmake_minimum_required(VERSION 3.21.0)

project(miniRT)

set (SRCS_MAIN
	src/main.c
)

set (SRCS
    src/parsing/string_utilities.c
    src/parsing/check_filmset.c
    src/parsing/check_file_args.c
    src/parsing/check_objects.c
    src/parsing/error_handling.c
    src/render/render.c
    src/render/render_params.c
    src/render/camera.c
    src/render/ray.c
    src/render/utils.c
    src/render/light.c
    src/render/point_light.c
    src/render/ambient.c
    src/render/hittables/hittable.c
    src/render/hittables/sphere.c
    src/render/hittables/cylinder.c
    src/render/hittables/plane.c
    src/render/hittables/circle.c
    src/render/hittables/hittable_array.c
    src/render/color.c
    src/render/hit_record.c
    src/render/material.c
    src/hooks.c
)
set (EXEC_NAME miniRT)

#compiler settings:
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_C_FLAGS_DEBUG "-g -fsanitize=address") #cmake -DCMAKE_BUILD_TYPE=DEBUG to add debug flags
set (CMAKE_C_FLAGS_RELEASE "-O3 -Ofast") #cmake -DCMAKE_BUILD_TYPE=RELEASE to add release flags
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) #vscode include path checking

# add -gprof flag to compile and link if GPROF is set to ON
if (GPROF)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
    set (CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
endif()

#make executable with output name specified under EXEC_NAME and sources specified under SRCS
add_executable(${EXEC_NAME} ${SRCS} ${SRCS_MAIN})
target_include_directories(${EXEC_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(lib/libft)
add_subdirectory(lib/get_next_line)
add_subdirectory(lib/vec3)
add_subdirectory(lib/MLX42)

target_link_libraries(${EXEC_NAME} PRIVATE ft)
target_link_libraries(${EXEC_NAME} PRIVATE get_next_line)
target_link_libraries(${EXEC_NAME} PRIVATE vec3)
target_link_libraries(${EXEC_NAME} PRIVATE mlx42)

#-------------------- TESTING -------------------------------

if ((PROJECT_NAME STREQUAL CMAKE_PROJECT_NAME AND BUILD_TESTS) OR MINIRT_BUILD_TESTS)
	add_subdirectory(test)
	enable_testing()
endif()
