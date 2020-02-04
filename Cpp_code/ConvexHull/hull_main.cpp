#include<iostream>
#include <iomanip>
#include "../Points/Point2D.hpp"
#include <ctime>
#include <vector>



void createConvexHull(Point2D *points,int N)
{
	double target = points[0].x;
	int leftmost;
	std::vector<Point2D> hull;
	for(int i=1; i<N; i++)
	{
		if(target>points[i].x)
		{
			target = points[i].x;
			leftmost = i;
		}

	}
	std::cout<<"The left most point is "<<target<<"\n";
	int vertex = leftmost;
	int guess_point;
	do
	{
		hull.push_back(points[vertex]);

		guess_point = (vertex + 1 )%N;
		for(int i = 0; i<N; i++)
		{
			if(points[i].getOrientation(points[vertex],points[guess_point])==1)
			{
				guess_point = i;
			}
		}
		vertex = guess_point;

	}while(vertex!=leftmost);

	std::cout<<"The convex hull is: \n";
	for(int i=0; i<hull.size(); i++)
	{
		std::cout<<hull[i].x<<", "<<hull[i].y<<"\n";
		
	}

	
}
void createVTK(Point2D *points, int N)
{
	std::cout<<"DATASET POYDATA\n";
	std::cout<<"POINTS "<<N<<" float\n";

	for(int i=0; i<N; i++)
	{
		std::cout<<points[i].x<<" "<<points[i].y<<"\n";
	}
}

int main()
{

        srand(static_cast<double>(time(0))); //number generator;
	double secretNum = ((double)rand()/(double)RAND_MAX)*10.0;


	std::cout<<"The random number is: "<<secretNum<<"\n";
	int N = 20;
	Point2D points[N];

	for(int i=0; i<N; i++)
	{
		double x = ((double)rand()/(double)RAND_MAX)*10.0;
		double y = ((double)rand()/(double)RAND_MAX)*10.0;
		points[i].setValues(x,y);
		points[i].print(cout);
	}
	createConvexHull(points,N);
	createVTK(points,N);



	






	return 0;



}
