#pragma once
#include "IntersectedPoint.h"
#include "IntersectedPoint_Derived.h"

/*
* ComparePoint lớp so sánh 2 điểm
*/
class ComparePoint
{
public:
	bool operator()(IntersectedPoint d1,IntersectedPoint d2)const volatile;		///Định nghĩa So sánh 2 điểm
	bool operator()(IntersectedPoint *d1,IntersectedPoint *d2)const volatile;
	//bool operator()(IntersectedPoint_Derived*d1,IntersectedPoint_Derived*d2);
	///Định nghĩa So sánh 2 con trỏ điểm
	ComparePoint(void);
	~ComparePoint(void);
};

