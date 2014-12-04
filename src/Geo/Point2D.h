/*
 * Point2D.h
 *
 *  Created on: Nov 19, 2014
 *      Author: minh
 */

#ifndef POINT2D_H_
#define POINT2D_H_

#define ep 1e-7
#define EP 1e-7
#define PARALLEL -2
#define COINCIDENT -1
#define NOT_INTERESECTING 0
#define INTERESECTING 1

class Point2D {
public:
	Point2D();
	Point2D(double _x,double _y);
	double DistanceTo(Point2D otherPt);

//	void setX(double value);
//	void setY(double value);
	virtual ~Point2D();
//	const double getX();
//	const double getY();
	const bool operator==(Point2D a);
	bool operator!=(Point2D a);
public:
	double x;
	double y;
};

#endif /* POINT2D_H_ */
