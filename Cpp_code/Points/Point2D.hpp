#include<cmath>
using namespace std;


enum {LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION};
class Point2D
{

	public:
	
		double x,y,z;

		Point2D(double _x, double _y); // Defining the default values of the constructor
		Point2D();
		//Vector arithmetic
		Point2D operator+(Point2D&); //Vector addition
		Point2D operator-(Point2D&); //Vector substraction
		virtual void print(ostream &strm); //Print the vectors
		int classify(Point2D&, Point2D&);
		double length(void);
		void setValues(double _x,double _y);
		friend Point2D operator*(double scalar, Point2D&);// Friend class because its first operand is not  of type Point!!
		//Relational operators: to compare vectors!
		int operator==(Point2D&);
		int operator!=(Point2D&);
		int operator<(Point2D&);
		int operator>(Point2D&);

};
//Let's declare the constructor first
//Recall that the constructor sets the inital values of the Point class
//
Point2D::Point2D()
{
	x = 0.0;
	y = 0.0;
}
Point2D::Point2D(double _x, double _y)
{
	x = _x;
	y = _y;

}
Point2D Point2D::operator+(Point2D &pointIn)
{
	return Point2D(x + pointIn.x, y + pointIn.y);
}
Point2D Point2D::operator-(Point2D &pointIn)
{
	return Point2D(x - pointIn.x, y - pointIn.y);
}
void Point2D::print(ostream &strm)
{
	strm<<fixed<<setprecision(6);
	strm << "(" << x << "," << y <<")\n";
}
double Point2D::length()
{
	return sqrt(x*x + y*y);

}
void Point2D::setValues(double _x,double _y)
{
	x = _x;
	y = _y;	
}
int Point2D::classify(Point2D &p0, Point2D &p1)
{
	Point2D p2 = *this;
	Point2D a = p1 - p0;
	Point2D b = p2 - p1;
	double sa = a.x*b.y - a.y*b.x;
	if(sa>0.0)
		return LEFT;
	else if(sa<0.0)
		return RIGHT;
	else if((a.x*b.x<0.0) || (a.y*b.y<0.0))
		return BEHIND;
	else if(a.length() < b.length())
		return BEYOND;
	else if(p0 == p2)
		return ORIGIN;
	else if(p1 == p2)
		return DESTINATION;
	return BETWEEN;

}
Point2D operator*(double scalar, Point2D &pointIn)
{
	return Point2D(scalar*pointIn.x,scalar*pointIn.y);
}
// Relational Operators
//
int Point2D::operator==(Point2D &p)
{
	return (x == p.x && y == p.y);
}
int Point2D::operator!=(Point2D &p)
{
	return (x!=p.x && y!=p.y);
	//return !(*this == p);
}
