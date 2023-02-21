cmake_minimum_required(VERSION 3.21.0)

project(miniRT)
set (SRCS
    src/main.c
    src/render/render.c
    src/render/render_params.c
    src/render/camera.c
    src/render/ray.c
    src/render/utils.c
    src/render/hittable/hittable.c
    src/render/hittable/sphere.c
    src/render/hittable/hittable_list.c
)
set (EXEC_NAME miniRT)

#compiler settings:
set (CMAKE_C_FLAGS "-Wall -Werror -Wextra")
set (CMAKE_C_FLAGS_DEBUG "-g -fsanitize=address") #cmake -DCMAKE_BUILD_TYPE=DEBUG to add debug flags
set (CMAKE_EXPORT_COMPILE_COMMANDS ON) #vscode include path checking

#make executable with output name specified under EXEC_NAME and sources specified under SRCS
add_executable(${EXEC_NAME} ${SRCS})
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

enable_testing()
