#include <iostream>
#include <iomanip>
#include "Point.hpp"



int main()
{
	Point p1(1.5, 1.8, 3.45);
	Point p2(2.0, 2.0, 2.0);


	Point p3  = p2 + p1;
	Point p4 = p1 - p2;
	Point p5  = p2;
	Point p6;

	cout<<"The new point is :\n";
	p3.print(cout);
	p4.print(cout);
	p2.print(cout);
	p5.print(cout);
	p6.print(cout);

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

