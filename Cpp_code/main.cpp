#include <iostream>
#include <iomanip>
#include "Point3D.hpp"

int Orientation(Point2D &p0, Point2D &p1, Point2D &p2)
{
	Point2D a = p1 - p0;
	Point2D b = p2 - p1; 
	double sa = a.x*b.y - b.x*a.y;
	if(sa>0.0)
	{
		return 1;
	}
	else if(sa<0.0)
	{
		return -1;
	}

	return 0;
}


int main()
{
	Point2D p1(1.5, 1.8);
	Point2D p2(2.0, 2.0);
	Point3D p9(1.0,2.0,3.0);
	Point3D p10 = 2.0*p9;


	Point2D p3  = p2 + p1;
	Point2D p4 = p1 - p2;
	Point2D p5  = p2;
	Point3D p6 = p9 + p10;

	cout<<"The new point is :\n";
	p3.print(cout);
	p4.print(cout);
	p2.print(cout);
	p5.print(cout);
	p9.print(cout);
	p10.print(cout);
	p6.print(cout);
	cout<<"Point 3 length is: "<<p3.length()<<"\n";
	cout<<"Point p3 is :"<<p3.classify(p2,p3)<<"\n";

	if(p5==p2)
	{
		cout<<"Point p3 and p4 are the same\n";
	}
	else
	{
		cout<<"Point p3 and p4 are not the same\n";

	}
	if(p5!=p2)
		cout<<"Point p5 and p1 are differents\n";
	else
		cout<<"Point p5 and p2 are not differents\n";



	return 0;
}

