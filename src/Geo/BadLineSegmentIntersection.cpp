#include "BadLineSegmentIntersection.h"
#include "LineSegment.h"

BadLineSegmentIntersection::BadLineSegmentIntersection(void)
{
}


BadLineSegmentIntersection::~BadLineSegmentIntersection(void)
{
	BadLineSegmentIntersection::clear();
}

void BadLineSegmentIntersection::addLineSegment( double x1,double y1,double x2,double y2,void * data/*=0*/ )
{
	m_lineSegs.push_back(new LineSegment(x1,y1,x2,y2));
}

size_t BadLineSegmentIntersection::calc( void *progress/*=0*/ )
{
	map<IntersectedPoint_Derived*,int,ComparePoint>::iterator it;

	double x,y;
	for(int i=0;i<m_lineSegs.size()-1;i++)
	{
		for(int j=i+1;j<m_lineSegs.size();j++)
		{
			int intersected = m_lineSegs[i]->Intersection2Segment(*m_lineSegs[j],x,y);

			//if(progress!=0) ;//progress->tick();

			if(intersected==1)
			{



				IntersectedPoint_Derived* tmp=new IntersectedPoint_Derived(x,y);
				it=m_mapPoints.find(tmp);	///Kiểm tra điểm này có trong danh sách giao điểm chưa
				if(it!=m_mapPoints.end())
				{	///Nếu đã tồn tại thì thêm 2 đoạn đang xét vào danh sách những đoạn đi qua điểm này
					it->first->AddLineToList(m_lineSegs[i]);
					it->first->AddLineToList(m_lineSegs[j]);
					delete tmp;
				}
				else
				{
					tmp->AddLineToList(m_lineSegs[i]);
					tmp->AddLineToList(m_lineSegs[j]);
					m_mapPoints.insert(pair<IntersectedPoint_Derived*,int>(tmp,0));
				}


			}	
			else
				if(intersected==-1)
					///Trường hợp 2 đoạn nằm trên 1 đường thẳng nhưng có  chung đầu mút
				{
					IntersectedPoint_Derived D1(m_lineSegs[i]->x1,m_lineSegs[i]->y1);
					IntersectedPoint_Derived D2(m_lineSegs[i]->x2,m_lineSegs[i]->y2);
					IntersectedPoint_Derived E1(m_lineSegs[j]->x1,m_lineSegs[j]->y1);
					IntersectedPoint_Derived E2(m_lineSegs[j]->x2,m_lineSegs[j]->y2);

					if(D1==E2 )
					{
						IntersectedPoint_Derived *tmp=new IntersectedPoint_Derived(D1.x,D1.y);
						tmp->AddLineToList(m_lineSegs[i]);
						tmp->AddLineToList(m_lineSegs[j]);
						m_mapPoints.insert(pair<IntersectedPoint_Derived*,int>(tmp,0));

					}
					if(D2==E1)
					{
						IntersectedPoint_Derived *tmp=new IntersectedPoint_Derived(D2.x,D2.y);
						tmp->AddLineToList(m_lineSegs[i]);
						tmp->AddLineToList(m_lineSegs[j]);
						m_mapPoints.insert(pair<IntersectedPoint_Derived*,int>(tmp,0));
					}
				}
		}
	};


	///copy cac diem tu Map tra ve vector
	map<IntersectedPoint_Derived*,int,ComparePoint>::iterator it_2=m_mapPoints.begin();

	while(it_2!=m_mapPoints.end())
	{
		m_IntersectedPoints.push_back(it_2->first);
		it_2++;
	}
	return m_IntersectedPoints.size();
}

size_t BadLineSegmentIntersection::getNumberOfIntersectedPoint()
{
	return m_IntersectedPoints.size();
}

IntersectedPoint * BadLineSegmentIntersection::getIntersectedPoint( size_t at )
{	
	return LineSegmentIntersection::getIntersectedPoint(at);	
}

void BadLineSegmentIntersection::getResultSegments( vector<LineSegment> & result )
{
	return LineSegmentIntersection::getResultSegments(result);
}

void BadLineSegmentIntersection::clear()
{
	map<IntersectedPoint_Derived*,int,ComparePoint>::iterator it= m_mapPoints.begin();
	while(it!=m_mapPoints.end())
	{

		delete it->first;
		it++;
	}
	m_mapPoints.clear();
}



