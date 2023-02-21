#include <gtest/gtest.h>

using namespace std;

extern "C" {
	#include <vec3.h>
}

TEST(libvec3, new) {
  t_vec3  vec;
  double data[] = {3223, -0.13141414, 43111414};

  vec = vec3_new(data[0], data[1], data[2]);

  for (uint8_t i = 0; i < 3; i++)
    EXPECT_DOUBLE_EQ(vec.data[i], data[i]);
}

TEST(libvec3, set)
{
  t_vec3  vec;
  double data[] = {245251, -0.232441, -5131144};

  vec3_set(&vec, data[0], data[1], data[2]);

  for (uint8_t i = 0; i < 3; i++)
    EXPECT_DOUBLE_EQ(vec.data[i], data[i]);
}

TEST(libvec3, fill)
{
  t_vec3  vec;

  vec3_fill(&vec, -2424294.2424144);

  for (uint8_t i = 0; i < 3; i++)
    EXPECT_DOUBLE_EQ(vec.data[i],  -2424294.2424144);
}

