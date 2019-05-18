#include <stdio.h>
#include <stdlib.h>

typedef struct Point
{
	double x,y,z;
}point_t;

void create_point(point_t *this, double x,double y,double z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}
point_t cross_product(point_t A, point_t B)
{
	point_t p;

	p.x = A.y*B.z - A.z*B.y;
	p.y = A.z*B.x - A.x*B.z;
	p.z = A.x*B.y - A.y*B.x;
	return p;
}
int main (void)
{
	point_t A,B,C,p;

	create_point(&A,0.0,0.0,0.0);
	create_point(&B,0.0,0.0,0.0);
	create_point(&C,0.0,0.0,0.0);

	p = cross_product(A,B);

	printf("Cross Point coordinates: (%lf, %lf,%lf)\n",p.x,p.y,p.z);
	return 0;
}
