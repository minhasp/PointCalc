#pragma once
#include "LineSegmentIntersection.h"
//#include "DLLPSC.h"
class  BadLineSegmentIntersection :
	public LineSegmentIntersection
{
	map<IntersectedPoint_Derived*,int,ComparePoint>	m_mapPoints;

public:
	 BadLineSegmentIntersection(void);
	
	 void addLineSegment(double x1,double y1,double x2,double y2,void * data=0);
	 size_t calc(void *progress=0);
	 size_t getNumberOfIntersectedPoint();
	 IntersectedPoint * getIntersectedPoint(size_t at);
	 void getResultSegments(vector<LineSegment> & result);

	 void clear();
	 ~BadLineSegmentIntersection(void);
};

