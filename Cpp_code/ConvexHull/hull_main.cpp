#include<iostream>
#include <iomanip>
#include "../Points/Point2D.hpp"
#include <ctime>


int main()
{

        srand(static_cast<double>(time(0))); //number generator;
	double secretNum = ((double)rand()/(double)RAND_MAX)*10.0;


	std::cout<<"The random number is: "<<secretNum<<"\n";

	Point2D points[3];

	for(int i=0; i<3; i++)
	{
		double x = ((double)rand()/(double)RAND_MAX)*10.0;
		double y = ((double)rand()/(double)RAND_MAX)*10.0;
		points[i].setValues(x,y);
		points[i].print(cout);
	}
	std::cout<<points[1].x<<"\n";






	return 0;



}
