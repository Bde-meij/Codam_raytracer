#include <gtest/gtest.h>

extern "C" {
	#include "render/camera.h"
	#include <stdbool.h>
}

TEST(camera, basic_ray)
{
	t_camera *camera = camera_new(vec3_new(0, 0, 0), vec3_new(0, 0, 1), 90);

	ASSERT_NE(camera, nullptr);

	camera_prepare(camera, 1);

	t_ray test_ray = camera_generate_ray(camera, 0.5, 0.5);

	EXPECT_TRUE(vec3_eq_c(test_ray.direction, vec3_new(0, 0, 1)));

	camera_destroy(camera);
}

TEST(camera, basic_ray2)
{
	t_camera *camera = camera_new(vec3_new(0, 0, 0), vec3_new(0, 0, 1), 90);

	ASSERT_NE(camera, nullptr);

	camera_prepare(camera, 1);

	t_ray test_ray = camera_generate_ray(camera, 0.8, 0.8);
	std::cout << "result: "; vec3_print(&test_ray.direction);

	EXPECT_TRUE(vec3_eq_c(test_ray.direction, vec3_normalize_c(vec3_new(.6, .6, 1))));

	camera_destroy(camera);
}

TEST(camera, basic_ray3)
{
	t_camera *camera = camera_new(vec3_new(0, 0, 0), vec3_new(0, 0, 1), 180);

	ASSERT_NE(camera, nullptr);

	camera_prepare(camera, 1);

	t_ray test_ray = camera_generate_ray(camera, 0.5, 0.5);
	std::cout << "result: "; vec3_print(&test_ray.direction);

	EXPECT_TRUE(vec3_eq_c(test_ray.direction, vec3_new(0, 0, 1)));

	camera_destroy(camera);
}
