#include <gtest/gtest.h>

using namespace std;

extern "C" {
	#include <vec3.h>
}

TEST(libvec3, dot)
{
	t_vec3 vec1, vec2;
	double res_test, res_vec;

	vec1 = vec3_new(5232424.131331313, -0.3131313 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	res_test = 0;
	for (uint8_t i = 0; i < 3; i++)
		res_test += vec1.data[i] * vec2.data[i];
	EXPECT_DOUBLE_EQ(res_vec, res_test);

	vec1 = vec3_new(1, 0, 0);
	vec2 = vec3_new(0, 1, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, 0);

	vec1 = vec3_new(1, 0, 0);
	vec2 = vec3_new(1, 0, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, 1);

	vec1 = vec3_new(1, 0, 0);
	vec2 = vec3_new(-1, 0, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, -1);

	vec1 = vec3_new(0, 1, 0);
	vec2 = vec3_new(0, 1, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, 1);

	vec1 = vec3_new(0, 1, 0);
	vec2 = vec3_new(0, -1, 0);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, -1);

	vec1 = vec3_new(0, 0, 1);
	vec2 = vec3_new(0, 0, 1);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, 1);

	vec1 = vec3_new(0, 0, 1);
	vec2 = vec3_new(0, 0, -1);
	res_vec = vec3_dot(&vec1, &vec2);
	EXPECT_DOUBLE_EQ(res_vec, -1);
}

TEST(libvec3, cross)
{
	t_vec3 vec1, vec2, vec_res;
	double test_res[3];

	vec1 = vec3_new(1, 0, 0);
	vec2 = vec3_new(0, 1, 0);
	vec_res = vec3_cross(&vec1, &vec2);
	test_res[0] = 0;
	test_res[1] = 0;
	test_res[2] = 1;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);
	
	vec1 = vec3_new(1, 0, 0);
	vec2 = vec3_new(0, 0, 1);
	vec_res = vec3_cross(&vec1, &vec2);
	test_res[0] = 0;
	test_res[1] = -1;
	test_res[2] = 0;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(0, 1, 0);
	vec2 = vec3_new(0, 0, 1);
	vec_res = vec3_cross(&vec1, &vec2);
	
	test_res[0] = 1;
	test_res[1] = 0;
	test_res[2] = 0;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(0, 0, 1);
	vec2 = vec3_new(0, 1, 0);
	vec_res = vec3_cross(&vec1, &vec2);

	test_res[0] = -1;
	test_res[1] = 0;
	test_res[2] = 0;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);


	vec1 = vec3_new(-242, 0 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, -0.01);
	vec_res = vec3_cross(&vec1, &vec2);
	
	test_res[0] = vec1.data[1] * vec2.data[2] - vec1.data[2] * vec2.data[1];
	test_res[1] = vec1.data[2] * vec2.data[0] - vec1.data[0] * vec2.data[2];
	test_res[2] = vec1.data[0] * vec2.data[1] - vec1.data[1] * vec2.data[0];

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);		vec1 = vec3_new(-242, 0 , 4.5131);
	vec2 = vec3_new(242, 0.4241213, -0.01);
	vec_res = vec3_cross(&vec1, &vec2);
	
	test_res[0] = vec1.data[1] * vec2.data[2] - vec1.data[2] * vec2.data[1];
	test_res[1] = vec1.data[2] * vec2.data[0] - vec1.data[0] * vec2.data[2];
	test_res[2] = vec1.data[0] * vec2.data[1] - vec1.data[1] * vec2.data[0];

	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);	
}

TEST(libvec3, normalize)
{
	t_vec3 vec1, vec_res;
	double test_res[3];

	vec1 = vec3_new(1, 0, 0);
	vec_res = vec3_normalize(&vec1);
	test_res[0] = 1;
	test_res[1] = 0;
	test_res[2] = 0;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(0, 1, 0);
	vec_res = vec3_normalize(&vec1);
	test_res[0] = 0;
	test_res[1] = 1;
	test_res[2] = 0;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(0, 0, 1);
	vec_res = vec3_normalize(&vec1);
	test_res[0] = 0;
	test_res[1] = 0;
	test_res[2] = 1;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(1, 1, 1);
	vec_res = vec3_normalize(&vec1);
	test_res[0] = 0.57735026918962576450914878050196;
	test_res[1] = 0.57735026918962576450914878050196;
	test_res[2] = 0.57735026918962576450914878050196;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);

	vec1 = vec3_new(1, 2, 3);
	vec_res = vec3_normalize(&vec1);
	test_res[0] = 0.2672612419124244;
	test_res[1] = 0.5345224838248488;
	test_res[2] = 0.8017837257372732;
	for (uint8_t i = 0; i < 3; i++)
		EXPECT_DOUBLE_EQ(vec_res.data[i], test_res[i]);
}
