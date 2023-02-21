#include "render.h"
#include <math.h>

double to_degrees(double radians)
{
	return (radians * (180.0 * M_PI));
}

double to_radians(double degrees)
{
	return (degrees * (M_PI / 180.0));
}

uint32_t	rgb_to_rgba(const uint8_t	color[3])
{
    return (color[0] << 24 | color[1] << 16 | color[2] << 8 | 0xFF);
}
