#include "../Points/Point2D.hpp"

//The edge class will be used to represent all forms of lines
//
//
class Edge
{
	public:
		Point2D	orig;
		Point2D dest;
		Edge(Point2D &_orig, Point2D &_dest);
		Edge(void);
		//Edge &rot(void);
		//Edge &flip(void);
};
Edge::Edge(Point2D &_orig, Point2D &_dest)
{
	//An edges's origin and destimation data members are stored in data members
	//orig & dest. The Edge constructor initializes these data members
	orig = _orig;
	dest = _dest;
}
Edge::Edge(void)
{
	orig = Point2D(0.0,0.0);
	dest = Point2D(1.0,0.0);
}
