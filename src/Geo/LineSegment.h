/*
 * LineSegment.h
 *
 *  Created on: Nov 20, 2014
 *      Author: minh
 */

#ifndef LINESEGMENT_H_
#define LINESEGMENT_H_

extern int noname(int i);


#include "Point2D.h"
class LineSegment {
public:
	LineSegment();
	LineSegment(double x1,double y1,double x2,double y2);
	LineSegment( Point2D  startPt, Point2D endPt);
	LineSegment(void * _from,void * _to);

	int Intersection2Segment(LineSegment otherLine,double &x,double &y);
	///HÃ m tÃ¬m giao Ä‘iá»ƒm cá»§a 2 Ä‘oáº¡n tháº³ng  .return 1 náº¿u 2 Ä‘oáº¡n giao nhau (tá»�a Ä‘á»™ lÆ°u trong tham sá»‘ x,y), 0 ngÆ°á»£c láº¡i
	///return -2 náº¿u 2 Ä‘oáº¡n song song
	///return -1 náº¿u 2 Ä‘oáº¡n náº±m trÃªn 1 Ä‘Æ°á»�ng tháº³ng



	int Intersection_HalfOfLine(const LineSegment &b,double &x,double &y);


	virtual ~LineSegment();
public:
	double x1;
	double y1;
	double x2;
	double y2;

};

#endif /* LINESEGMENT_H_ */
