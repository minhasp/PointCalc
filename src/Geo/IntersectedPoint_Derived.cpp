#include "IntersectedPoint_Derived.h"


IntersectedPoint_Derived::IntersectedPoint_Derived(void)
{
	x=y=0;

	m_ListLineSegment.comp.setvalue(100);
	m_ListLineSegment.clear();
}

IntersectedPoint_Derived::IntersectedPoint_Derived( double _x,double _y )
{
	x=_x;
	y=_y;
	m_typeOfPoint=0;
}

IntersectedPoint_Derived::IntersectedPoint_Derived( double _x,double _y,int typeOfPoint )
{
	x=_x;y=_y;
	m_typeOfPoint=typeOfPoint;
}




IntersectedPoint_Derived::~IntersectedPoint_Derived(void)
{
}




void IntersectedPoint_Derived::getLineSegment( std::vector<LineSegment * > & lineSeg )
{
	lineSeg.clear();
	map<LineSegment*,int,CompareLine>::iterator it=m_ListLineSegment.begin();
	while(it!=m_ListLineSegment.end())
	{
		lineSeg.push_back(it->first);
		it++;
	}

}


void IntersectedPoint_Derived::AddLineToList( LineSegment *lineseg )
{

	m_ListLineSegment.insert(pair<LineSegment*,int>(lineseg,m_ListLineSegment.size()));
}
