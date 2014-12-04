#pragma once
#include <vector>
#include "LineSegment.h"
//#define ep 0.0000000001
#define max_num_line 5000
#define max_length_line 20
//#include "DLLPSC.h"
using namespace std;
class  IntersectedPoint
{
public:
	double x;
	double y;
public:
	IntersectedPoint();
	IntersectedPoint(double _x,double _y);
	virtual void getLineSegment(vector<LineSegment * > & lineSeg);


	bool operator==(const IntersectedPoint &a);
	bool operator!=(const IntersectedPoint &a);
	bool operator>(const  IntersectedPoint &a);
	bool operator<(const  IntersectedPoint &a);
	virtual ~IntersectedPoint();
};

