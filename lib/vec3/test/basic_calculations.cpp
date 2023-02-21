#include <gtest/gtest.h>

using namespace std;

extern "C" {
	#include <vec3.h>
}

TEST(libvec3, add)
{
	t_vec3 vec1, vec2, vec_res;

	vec1 = vec3_new(-242, 0 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, -0.01);

	vec_res = vec3_add(&vec1, &vec2);

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec1.data[i] + vec2.data[i]);
}

TEST(libvec3, subtract)
{
	t_vec3 vec1, vec2, vec_res;

	vec1 = vec3_new(-242, 0 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, -0.01);

	vec_res = vec3_subtract(&vec1, &vec2);

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec1.data[i] - vec2.data[i]);
}

TEST(libvec3, multiply)
{
	t_vec3 vec1, vec2, vec_res;

	vec1 = vec3_new(-242, 0 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, -0.01);

	vec_res = vec3_multiply(&vec1, &vec2);

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec1.data[i] * vec2.data[i]);
}

TEST(libvec3, divide)
{
	t_vec3 vec, vec_res;

	vec = vec3_new(-242, 0 , 4.5131);

	vec_res = vec3_divide(&vec, 5.42425252);

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec.data[i] / 5.42425252);
	
	vec_res = vec3_divide(&vec, -0.01);
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec.data[i] / -0.01);
}

TEST(libvec3, scalar)
{
	t_vec3 vec, vec_res;

	vec = vec3_new(-242, 0 , 4.5131);

	vec_res = vec3_scalar(&vec, -1.24132);
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec.data[i] * -1.24132);
	
	vec_res = vec3_scalar(&vec, -0.01);
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec.data[i] * -0.01);	
	
	vec_res = vec3_scalar(&vec, 0);
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], vec.data[i] * 0);	
}

