/*
 * Point2D.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: minh
 */

#include "Point2D.h"
#include <math.h>
Point2D::Point2D() {
	// TODO Auto-generated constructor stub
	x=y=0.0;
}

Point2D::~Point2D() {
	// TODO Auto-generated destructor stub
}

Point2D::Point2D(double _x,double _y)
{
	x=_x;
	y=_y;
}


double Point2D::DistanceTo(Point2D otherPt)
{
	double X=x-otherPt.x;
	double Y=y-otherPt.y;
	return sqrt (X*X+Y*Y);
	//return 0;
}

//const double Point2D::getX()
//{
//	return x;
//}
//const double Point2D::getY()
//{
//	return y;
//}
//
//void Point2D::setX(double value)
//{
//	x=value;
//}
//void Point2D::setY(double value)
//{
//	y=value;
//}


const bool Point2D::operator==(Point2D a)
		{
	if(fabs(this->x-a.x)<EP && fabs(this->y-a.y)<EP)
		return true;
	else return false;
		}
bool Point2D::operator!=(Point2D a)
		{
	if(fabs(this->x-a.x)>EP || fabs(this->y-a.y)>EP) return true;
	else return false;
		}
