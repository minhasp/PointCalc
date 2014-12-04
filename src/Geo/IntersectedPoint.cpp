#include "IntersectedPoint.h"
#include <math.h>
#ifndef abs
#define abs fabs
#endif
void IntersectedPoint::getLineSegment( vector<LineSegment * > & lineSeg )
{

}

IntersectedPoint::IntersectedPoint()
{
	x=y=0;
}

IntersectedPoint::IntersectedPoint( double _x,double _y )
{
	x=_x;
	y=_y;
}


bool IntersectedPoint::operator>( const IntersectedPoint &a )
{
	if(!(*this<a) && !(*this==a)) return true;
	else return false;
}

bool IntersectedPoint::operator<( const IntersectedPoint &a )
{
	if((this->y>a.y)||(this->y==a.y && this->x<a.x)) return true;
	else return false;
}



bool IntersectedPoint::operator==(const IntersectedPoint &a )
{
	
	if(abs(x-a.x)<ep && abs(y-a.y)<ep) return true;
	else return false;
}

bool IntersectedPoint::operator!=(const IntersectedPoint &a )
{
	if(!(*this==a)) return true;
	else return false;
}

IntersectedPoint::~IntersectedPoint()
{

}
