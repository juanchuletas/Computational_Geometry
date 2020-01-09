#include "Point2D.hpp"


//Point3D class is a derived class from Point2D class
//
//
class Point3D : public Point2D
{
	public:
		double z;
		Point3D(double _x, double _y, double _z);
		Point3D();
		void print(ostream &strm);
		friend Point3D operator*(double scalar, Point3D&);
		Point3D operator+(Point3D&);
};
Point3D::Point3D() : Point2D()
{
	z = 0.0;
}
Point3D::Point3D(double _x, double _y, double _z) : Point2D(_x, _y)
{
	z = _z;

}
void Point3D::print(ostream &strm)
{
	strm<<fixed<<setprecision(6);
        strm << "(" << x << ", " << y << ", "<<z<<")\n";
}
Point3D operator*(double scalar, Point3D &pointIn)
{

	return Point3D(scalar*pointIn.x, scalar*pointIn.y, scalar*pointIn.z);

}
Point3D Point3D::operator+(Point3D &p)
{
	return Point3D(x + p.x, y + p.y, z + p.z);
}
