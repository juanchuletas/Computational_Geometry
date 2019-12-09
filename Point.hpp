
using namespace std;

class Point
{
public:
	double x,y,z;

	Point(double _x = 0.0, double _y = 0.0, double _z = 0.0); // Defining the default values of the constructor
	//Vector arithmetic
	Point operator+(Point&); //Vector addition
	Point operator-(Point&); //Vector substraction
	void print(ostream &strm); //Print the vectors
	friend Point operator*(double scalar, Point&);// Friend class because its first operand is not  of type Point!!
	//Relatinal operators: to compare vectors!
	int operator==(Point&);
	int operator!=(Point&);
	int operator<(Point&);
	int operator>(Point&);

};
//Let's declare the constructor first
//Recall that the constructor sets the inital values of the Point class
//
Point::Point(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;

}
Point Point::operator+(Point &pointIn)
{
	return Point(x + pointIn.x, y + pointIn.y, z + pointIn.z);
}
Point Point::operator-(Point &pointIn)
{
	return Point(x - pointIn.x, y - pointIn.y, z - pointIn.z);
}
void Point::print(ostream &strm)
{
	strm<<fixed<<setprecision(6);
	strm << "(" << x << "," << y <<","<<z<<")\n";
}
Point operator*(double scalar, Point &pointIn)
{
	return Point(scalar*pointIn.x,scalar*pointIn.y,scalar*pointIn.z);
}
// Relational Operators
//
int Point::operator==(Point &p)
{
	return (x == p.x && y == p.y && z==p.z);
}
int Point::operator!=(Point &p)
{
	return (x!=p.x && y!=p.y && z!=p.z);
	//return !(*this == p);
}
