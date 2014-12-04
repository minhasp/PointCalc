#include "CompareLine.h"
#include "IntersectedPoint_Derived.h"

#include <math.h>

#ifndef abs
#define abs fabs
#endif

CompareLine::CompareLine( double _y )
{
	y=_y;
	x=0.0;
}

CompareLine::CompareLine()
{
	x=y=0.0;
}


CompareLine::~CompareLine(void)
{
}


double CWW(IntersectedPoint_Derived P,IntersectedPoint_Derived Q,IntersectedPoint_Derived R)
{
	return (  (Q.x-P.x)*(R.y-P.y)-(R.x-P.x)*(Q.y-P.y)  );
	 
}
bool CompareLine::operator()( LineSegment L1,LineSegment L2 )const volatile
	///Định nghĩa khi nào thì L1<L2 ( trả về true khi L1<l2)
{
	LineSegment sweepLine(0,y,1,y);
	double xA,yA,xB,yB;

	/// xA,yA là tọa độ giao điểm của l1 với đường thẳng quét ngang
	/// xB,yB là tọa độ giao điểm của l2 với đường thẳng quét ngang

	int b1=sweepLine.Intersection2Segment(L1,xA,yA);
	int b2=sweepLine.Intersection2Segment(L2,xB,yB);
	if(b1==-1 && b2==-1) 
		///Nếu cả 2 đoạn đồng thời nằm trên đường quét ngang
	{
		if((L1.x1 < L2.x1) && abs(L1.x1-L2.x1)>ep) return true;
		else return false;
	};
	if(b1==-1)
		///Nếu đoạn L1 nằm trên đường thẳng quét ngang
	{	///So sánh với đường quét dọc
		///Nếu L2 ở bên phải đường quét dọc tại vị trí của đường quét ngang thì L2>L1;
		//if(b2==-1) 
		if(x<xB && abs(x-xB)>ep) return true;
		else return false;
	}

	if(b2==-1)
		///Tương tự với trường hợp L2 nằm trên đường quét ngang
	{
		if(x>xA || abs(x-xA)<ep) return true;
		else return false;
	}
	if(b1==-2) xA=-9999;			/// Trường hợp này chưa sử dụng
	if(b2==-2) xB=-9999;			/// Trường hợp này chưa sử dụng

	
	if(abs(xA-xB)<ep)
	{
		double cww=CWW(IntersectedPoint_Derived(xA,yA),IntersectedPoint_Derived(L1.x2,L1.y2),IntersectedPoint_Derived(L2.x2,L2.y2));
		if(abs(cww)<ep)
		{
			double cww2=CWW(IntersectedPoint_Derived(xA,yA),IntersectedPoint_Derived(L2.x1,L2.y1),IntersectedPoint_Derived(L1.x1,L1.y1));
			if(abs(cww2)<ep)
			{
				if(L1.y1<L2.y1) return true;
				else return false;
			}
			else
				if(cww2>0)
				{
					if(x<xA && abs(x-xA)>ep) return true;
					else return false;
				}
				else
				{
					if(x>xA || abs(x-xA)<ep) return true;
					else return false;
				}
		}
		else
		if(cww>0)
		{
			if(x>xA || abs(x-xA)<ep)
			return true;
			else return false;

		}
		else 
		{
			if(x<xA && abs(x-xA)>ep) return true;
			else return false;
		}
	}
	else
	if(xA<xB) 
		return true;
	else 
		return false;
	

}

bool CompareLine::operator()( LineSegment *L1,LineSegment *L2 )const volatile
{
	return operator()(*L1,*L2);
}


void CompareLine::setvalue( double _y )
{
	y=_y;
	x=-9999;
}



void CompareLine::setvalue( double _x,double _y )
{
	y=_y;
	x=_x;
}

double CompareLine::getx()
{
	return x;
}

double CompareLine::gety()
{
	return y;
}
