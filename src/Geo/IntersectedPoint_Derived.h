#pragma once
#include "LineSegment.h"
#include "IntersectedPoint.h"

#include <map>
#include <vector>
#include "CompareLine.h"
using namespace std;

/*
* Class IntersectedPoint_Derived biểu diễn 1 điểm trong mặt phẳng tọa độ OXY
*	với danh sách các đoạn thẳng giao cắt tại nó
*	và kiểu của điểm ( là đầu mút , hay giao điểm )
*/
class IntersectedPoint_Derived: public  IntersectedPoint
{
public:
	map<LineSegment*,int,CompareLine> m_ListLineSegment;			///Danh sách đoạn thẳng đi qua điểm này
	int m_typeOfPoint;												///=1: Nếu là điểm đầu, =2 điểm cuối
																	///=3: Giao điểm 
																	
public:
	IntersectedPoint_Derived(void);
	IntersectedPoint_Derived(double x,double y);
	IntersectedPoint_Derived(double x,double y,int typeOfPoint);
	void AddLineToList(LineSegment *lineseg);						///Chèn thêm 1 đoạn vào danh sách các đoạn đi qua điểm này

	void getLineSegment(std::vector<LineSegment * > & lineSeg);		/// trả về danh sách các đoạn thẳng cắt nhau tại điểm này
	~IntersectedPoint_Derived(void);
};

