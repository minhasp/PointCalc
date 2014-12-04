//#include "..\StdAfx.h"
#include "CPolygon.h"
#include <math.h>


CPolygon::CPolygon(void)
{
	m_VectorPoint.resize(0);
	m_Parts.push_back(0);
	//m_IsDrawing=false;
	GetArea=0.0;
}


CPolygon::~CPolygon(void)
{
	m_VectorPoint.clear();

}


bool CPolygon::Direction()
{
	if(this->Area()>0) return true;
	else
		return false;
}

double CPolygon::Area()
{
	double s=0;
	if(m_VectorPoint.size()>2)
	{
		for(size_t i=0;i<m_Parts.size();i++)
		{
			size_t _start=m_Parts[i];
			size_t _end;
			double tmps=0;
			if(i==m_Parts.size()-1) 
			_end=m_VectorPoint.size()-1;
			else _end=m_Parts[i+1]-1;

			for(size_t j=_start;j<_end;j++)
			{
				tmps+=(0.5*(m_VectorPoint[j].x*m_VectorPoint[j+1].y-m_VectorPoint[j+1].x*m_VectorPoint[j].y));
			}
			s+=fabs(tmps);
		}

	}
	return (GetArea=(s));
}

Point2D CPolygon::Centroid()
{
	Point2D C=Point2D(0,0);
	double A=this->Area();

	for(unsigned int i=0;i<m_VectorPoint.size()-1;i++)
	{
		C.x+=(m_VectorPoint[i].x+m_VectorPoint[i+1].x)*(m_VectorPoint[i].x*m_VectorPoint[i+1].y-m_VectorPoint[i+1].x*m_VectorPoint[i].y);
		C.y+=(m_VectorPoint[i].y+m_VectorPoint[i+1].y)*(m_VectorPoint[i].x*m_VectorPoint[i+1].y-m_VectorPoint[i+1].x*m_VectorPoint[i].y);
	}
	//Point2D * tmp=new Point2D(C.x/(6*A),C.y/(6*A));
	
	return (GetCentroid=Point2D(C.x/(6*A),C.y/(6*A)));
}

bool CPolygon::checkAndAdd( Point2D a )
{
	
	if(CheckForAdd(a) && !this->IsClose())
	{
		m_VectorPoint.resize(m_VectorPoint.size()+1);
		m_VectorPoint[m_VectorPoint.size()-1]=a;
		return true;
	}
	else return false;
}

bool CPolygon::CheckForAdd( Point2D mPoint )
{
	if(m_VectorPoint.size()<=2) return true;
	else
	{
		Point2D A=m_VectorPoint[m_VectorPoint.size()-1];
		Point2D B=mPoint;
		int num=0;
		for(unsigned int i=0;i<m_VectorPoint.size()-2;i++)
		{
			Point2D tmp;
			LineSegment l1(A,B);
			LineSegment l2(m_VectorPoint[i],m_VectorPoint[i+1]);
			int intersec=l1.Intersection2Segment(l2,tmp.x,tmp.y);
			if(intersec==INTERESECTING) num++;
			
		};
		if(num<1) return true;
		else return false;
	}
}

bool CPolygon::DeletePoint( int  Index )
{
	int num=0;
	for(int i=0;i<Index-2;i++)
	{
		double x,y;
		LineSegment l1(m_VectorPoint[Index-1],m_VectorPoint[Index+1]);
		LineSegment l2(m_VectorPoint[i],m_VectorPoint[i+1]);
		int intersec=l1.Intersection2Segment(l2,x,y);

		if(intersec==INTERESECTING) num++;
	}
	for(unsigned int i=Index+2;i<m_VectorPoint.size()-2;i++)
	{
		double x,y;
		LineSegment l1(m_VectorPoint[Index-1],m_VectorPoint[Index+1]);
		LineSegment l2(m_VectorPoint[i],m_VectorPoint[i+1]);

		int intersec=l1.Intersection2Segment(l2,x,y);

		if(intersec==INTERESECTING) num++;
	}
	if(num==0)
	{

		for(unsigned int i=Index;i<m_VectorPoint.size()-1;i++)
		{
			m_VectorPoint[i]=m_VectorPoint[i+1];
		}
		m_VectorPoint.resize(m_VectorPoint.size()-1);

		return true;
	}
	return false;
}

bool CPolygon::InSide( Point2D mPoint )
{
	int num=0;
	Point2D O=this->Centroid();
	for(unsigned int i=0;i<m_VectorPoint.size()-1;i++)
	{		
		LineSegment l1=(this->GetLine(i));
		//Point2D *flt;
		LineSegment l2(mPoint,O);
		double x,y;
		int intersec=l1.Intersection_HalfOfLine(l2,x,y);
		if(intersec==INTERESECTING)	num++;
	}
	if(num%2==0) return false;
	else return true;
}

bool CPolygon::IsClose()
{
	if(m_VectorPoint.size()>1)
	{
		if(m_VectorPoint[0]==m_VectorPoint[m_VectorPoint.size()-1]) return true;
		else return false;
	}
	else return false;
}

Point2D CPolygon::GetLastPoint()
{
	if(m_VectorPoint.size()>0)
	{
		return  m_VectorPoint[m_VectorPoint.size()-1];
	}
	else return Point2D(-1,-1);
}

Point2D CPolygon::GetPoint(unsigned  int Index )
{
	if(m_VectorPoint.size()>0)
		return m_VectorPoint[Index];
	else return Point2D(-1,-1);
}

Point2D CPolygon::GetFirst()
{
	if(m_VectorPoint.size()>0)
		return m_VectorPoint[0];
	else return Point2D(-1,-1);
}

LineSegment CPolygon::GetLine(unsigned  int Index )
{

	if(m_VectorPoint.size()>=2 && Index<m_VectorPoint.size())
		return  LineSegment(m_VectorPoint[Index],m_VectorPoint[Index+1]);
	else return LineSegment(0,0,0,0);
}

bool CPolygon::Close()
{
	if(m_VectorPoint.size()>1)
	{

	
	int num=0;
	LineSegment line(m_VectorPoint[0],m_VectorPoint[m_VectorPoint.size()-1]);


	for(unsigned int i=1;i<m_VectorPoint.size()-2;i++)
	{
		LineSegment line2=GetLine(i);
		double x,y;
		int intersec=line.Intersection2Segment(line2,x,y);
		if(intersec==INTERESECTING) num++;
	}

	if(m_VectorPoint[m_VectorPoint.size()-1]!=m_VectorPoint[0] && num==0)
	{
		m_VectorPoint.resize(m_VectorPoint.size()+1);
		m_VectorPoint[m_VectorPoint.size()-1]=m_VectorPoint[0];

		Area();
		Centroid();
		return true;

	}
	else
	return false;
	};
	return false;

}

void CPolygon::addPoint( Point2D mPoint )
{
	m_VectorPoint.push_back(mPoint);
}

void CPolygon::addPoint( double x,double y )
{
	m_VectorPoint.push_back(Point2D(x,y));
}

void CPolygon::clear()
{
	m_VectorPoint.resize(0);
}

size_t CPolygon::GetNumPoint()
{
	return m_VectorPoint.size();
}

bool CPolygon::IsDrawing()
{
	if(m_VectorPoint.size()==0) return false;
	if(this->IsClose()) return false;
	return true;
}

vector<Point2D>& CPolygon::getListPoint()
{
	return m_VectorPoint;
}

void CPolygon::setListPoint( vector<Point2D>& listPoint )
{
	m_VectorPoint=listPoint;
}



void CPolygon::setListPart( vector<unsigned int>& listPart )
{
	m_Parts=listPart;
}

void CPolygon::BreakPart()
{
	m_VectorPoint.push_back(m_VectorPoint[m_Parts[m_Parts.size()-1]]);
	m_Parts.push_back(m_VectorPoint.size());
}

void CPolygon::CloseEnd()
{
	m_VectorPoint.push_back(m_VectorPoint[m_Parts[m_Parts.size()-1]]);

}

vector<unsigned int>& CPolygon::getListPart()
{
	return m_Parts;
}



//void CPolygon::DrawScreen( CDC *pDC )
//{
//
//}
//
//void CPolygon::OnLButtonDown( CDC *pDC,CPoint point )
//{
//
//}
//
//void CPolygon::OnRButtonDown( CDC *pDC,CPoint point )
//{
//
//}
//
//void CPolygon::OnMouseMove( CDC *pDC,CPoint point )
//{
//
//}

