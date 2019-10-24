#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Create a point struct which has two float variables: x and y
Create a function that constructs a point
It should take it's x and y coordinate as parameter
Create a function that takes 2 points and returns the distance between them
Example:
*/

typedef struct {
    float x;
    float y;
}point_t;

point_t create_point(float x, float y)
{
    point_t temp = {x, y};
    return temp;
}

float distance (point_t first, point_t second)
{
    return sqrtf((first.x - second.x) * (first.x - second.x) + (first.y - second.y) * (first.y - second.y));
}

int main()
{
	point_t p1 = create_point(1, 1);
	point_t p2 = create_point(1, 5.5);
	float dist = distance(p1, p2);
	printf("%f", dist);
	return 0;
}
