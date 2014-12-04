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
	///Hàm tìm giao điểm của 2 đoạn thẳng  .return 1 nếu 2 đoạn giao nhau (tọa độ lưu trong tham số x,y), 0 ngược lại
	///return -2 nếu 2 đoạn song song
	///return -1 nếu 2 đoạn nằm trên 1 đường thẳng



	int Intersection_HalfOfLine(const LineSegment &b,double &x,double &y);


	virtual ~LineSegment();
private:
	double x1;
	double y1;
	double x2;
	double y2;

};

#endif /* LINESEGMENT_H_ */
