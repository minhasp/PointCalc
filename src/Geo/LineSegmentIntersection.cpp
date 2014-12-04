#include "LineSegmentIntersection.h"


LineSegmentIntersection::LineSegmentIntersection(void)
{
}


LineSegmentIntersection::~LineSegmentIntersection(void)
{
	clear();
}

void LineSegmentIntersection::addLineSegment( double x1,double y1,double x2,double y2,void * data/*=0*/ )
{
	
}

size_t LineSegmentIntersection::calc( void *progress )
{
	return 0;
}



size_t LineSegmentIntersection::getNumberOfIntersectedPoint()
{
	return m_IntersectedPoints.size();
}

IntersectedPoint * LineSegmentIntersection::getIntersectedPoint( size_t at )
{
	if(at>=m_IntersectedPoints.size())	return 0;
	else
	{
		return m_IntersectedPoints[at];
	}
}

void LineSegmentIntersection::getResultSegments( vector<LineSegment> & result )
{
	for(unsigned int i=0;i<m_lineSegs.size();i++)
	{
		result.push_back(*m_lineSegs[i]);
	}
}

vector<LineSegment*> LineSegmentIntersection::getResultSegments_2()
{
	return m_lineSegs;
}



void LineSegmentIntersection::clear()
{
	for(unsigned int i=0;i<m_lineSegs.size();i++)
	{
		delete m_lineSegs[i];
	};
	m_lineSegs.clear();


	//for(int i=0;i<m_IntersectedPoints.size();i++)
	//{
	//	delete m_IntersectedPoints[i];
	//}

	m_IntersectedPoints.clear();
}


