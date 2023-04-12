#include "render/render.h"
#include <math.h>
#include <stdlib.h>

double	to_degrees(double radians)
{
	return (radians * (180.0 * M_PI));
}

double	to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

double	screenx_to_modelx(uint32_t x, uint32_t width)
{
	if (width == 1)
		return (0);
	return ((double)x / (width));
}

double	screeny_to_modely(uint32_t y, uint32_t height)
{
	if (height == 1)
		return (0);
	return (1 - ((double)y / (height)));
}

double	random_double(void)
{
	return ((double)rand() / (double)RAND_MAX);
}
