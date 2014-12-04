/*
 * LineSegment.cpp
 *
 *  Created on: Nov 20, 2014
 *      Author: minh
 */

#include "LineSegment.h"
#include <stdlib.h>
LineSegment::LineSegment() {
	// TODO Auto-generated constructor stub
	x1=y1=x2=y2=0.0;
}

LineSegment::~LineSegment() {
	// TODO Auto-generated destructor stub
}

LineSegment::LineSegment(double _x1,double _y1,double _x2,double _y2)
{
	x1=_x1;
	y1=_y1;
	x2=_x2;
	y2=_y2;

}

LineSegment::LineSegment(  Point2D  startPt, Point2D endPt)
{
	x1=startPt.x;
	y1=startPt.y;
	x2=endPt.x;
	y2=endPt.y;
}
int LineSegment::Intersection2Segment(LineSegment b,double &x,double &y)
{

	///Tìm a1,b1,c1 (3 tham số của phương trình đường thẳng chứa đoạn thẳng *this)

		double a1=this->y1-this->y2;
		double b1=-(this->x1-this->x2);
		double c1=this->x1*(this->y1-this->y2)-this->y1*(this->x1-this->x2);


		///Tìm a2,b2,c2 (3 tham số của phương trình đường thẳng chứa đoạn thẳng b)

		double a2=b.y1-b.y2;
		double b2=-(b.x1-b.x2);
		double c2=b.x1*(b.y1-b.y2)-b.y1*(b.x1-b.x2);

		///Tính định thức để tìm tọa độ giao điểm

		double d=a1*b2-a2*b1;
		double dx=c1*b2-c2*b1;
		double dy=a1*c2-a2*c1;

		/// Trường hợp 2 đoạn thẳng song song hoặc nằm trên 1 đường thẳng

		if(abs(d)<ep)
		{
			if(abs(dx)<ep) return COINCIDENT;
			else
			return PARALLEL;
		}

		///(x,y) là tọa độ của giao điểm

		x=dx/d;
		y=dy/d;


		///Kiểm tra điểm giao cắt có nằm giữa 2 đoạn hay không
		///Nếu nằm ngoài trả về 0, Nằm trong trả về 1

		if((((b.x1<b.x2 ||abs(b.x1-b.x2)<ep ) && (b.x1 < x || abs(b.x1 - x)<ep) && (x<b.x2 || abs(x-b.x2)<ep))||((b.x1>b.x2 ||abs(b.x1-b.x2)<ep ) && (b.x1>x ||abs(b.x1-x)<ep ) && (x>b.x2 || abs(x-b.x2)<ep)))&&(((b.y1<b.y2 ||abs(b.y1-b.y2)<ep ) && (b.y1<y ||abs(b.y1-y)<ep )  && (y<b.y2 ||abs(y-b.y2)<ep ))||((b.y1>b.y2 || abs(b.y1-b.y2)<ep) && (b.y1>y||abs(b.y1-y)<ep  ) && (y>b.y2 ||abs(y-b.y2)<ep ))))

		{
			if((((this->x2<this->x1||abs(this->x2-this->x1)<ep) && (this->x2<x||abs(this->x2-x)<ep) && (x<this->x1||abs(x-this->x1)<ep))||((this->x2>this->x1||abs(this->x2-this->x1)<ep) && (this->x2>x||abs(this->x2-x)<ep) && (x>this->x1||abs(x-this->x1)<ep)))    &&  (((this->y2<this->y1 ||abs(this->y2-this->y1)<ep) && (this->y2<y ||abs(this->y2-y)<ep) && (y<this->y1 ||abs(y-this->y1)<ep))||((this->y2>this->y1||abs(this->y2-this->y1)<ep) && (this->y2>y||abs(this->y2-y)<ep) && (y>this->y1||abs(y-this->y1)<ep)))    )
			{
				return INTERESECTING;
			}
			else
			{
				return NOT_INTERESECTING;
			}
		}
		else {
			return NOT_INTERESECTING;
		}



}


int LineSegment::Intersection_HalfOfLine(const LineSegment &b,double &x,double &y)
{
	Point2D A(x1,y1);
	Point2D B(x2,y2);
	Point2D C(b.x1,b.y1);
	Point2D D(b.x2,b.y2);


	///Tìm a1,b1,c1 (3 tham số của phương trình đường thẳng chứa đoạn thẳng *this)

	double a1=A.y-B.y;
	double b1=-(A.x-B.x);
	double c1=A.x*(A.y-B.y)-A.y*(A.x-B.x);


	///Tìm a2,b2,c2 (3 tham số của phương trình đường thẳng chứa đoạn thẳng b)

	double a2=C.y-D.y;
	double b2=-(C.x-D.x);
	double c2=C.x*(C.y-D.y)-C.y*(C.x-D.x);

	///Tính định thức để tìm tọa độ giao điểm

	double d=a1*b2-a2*b1;
	double dx=c1*b2-c2*b1;
	double dy=a1*c2-a2*c1;

	/// Trường hợp 2 đoạn thẳng song song hoặc nằm trên 1 đường thẳng thì bỏ qua

	if(abs(d)<ep)
	{
		if(abs(dx)<ep) return COINCIDENT;
		else
			return PARALLEL;
	}

	///(x,y) là tọa độ của giao điểm

	x=dx/d;
	y=dy/d;


	///Kiểm tra điểm giao cắt có nằm giữa đoạn thẳng this hay không
	/// (x,y) nằm giữa khi x nằm giữa x1,x2 và y nằm giữa y1,y2

	if(
		(
		((A.x < B.x || abs(A.x - B.x)<ep) && (A.x<x||abs(A.x-x)<ep) && (x<B.x||abs(x-B.x)<ep))||
		((A.x > B.x || abs(A.x - B.x)<ep) && (A.x>x||abs(A.x-x)<ep) && (x>B.x||abs(x-B.x)<ep))
		)
		&&
		(
		((A.y < B.y||abs(A.y - B.y)<ep) && (A.y<y||abs(A.y-y)<ep) && (y<B.y||abs(y-B.y)<ep )) ||
		((A.y > B.y||abs(A.y - B.y)<ep) && (A.y>y||abs(A.y-y)<ep) && (y>B.y||abs(y-B.y)<ep))
		)
		)

		/// kiểm tra xem giao điểm có nằm trên nửa đường thẳng B hay không
	{

		if(
			(
			((D.x>C.x||abs(D.x-C.x)<ep) && (x>C.x||abs(x-C.x)<ep))
			||
			((D.x<C.x||abs(D.x-C.x)<ep) && (x<C.x||abs(x-C.x)<ep))
			)
			&&
			(
			((D.y>C.y||abs(D.y-C.y)<ep) && (y>C.y||abs(y-C.y)<ep))
			||
			((D.y<C.y||abs(D.y-C.y)<ep) && (y<C.y||abs(y-C.y)))
			)
			)
			return true;
		else return false;
	}
	else return false;
}

LineSegment::LineSegment(void * _from,void * _to)
{
	Point2D* From=(Point2D*)_from;
	Point2D* To=(Point2D*)_to;
	x1=From->x;
	y1=From->y;
	x2=To->x;
	y2=To->y;
}
