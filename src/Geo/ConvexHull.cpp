//#include "..\StdAfx.h"
#include "ConvexHull.h"
#include <algorithm>
#include <complex>
//#include <crtdefs.h>


ConvexHull::ConvexHull(void)
{
	m_ListPoint.resize(0);
	m_Convex.clear();
	m_IsInput=true;
	GetArea=0.0;
}


ConvexHull::~ConvexHull(void)
{
	
	//delete m_ListPoint;
	//delete m_Convex;
	m_ListPoint.clear();
	m_Convex.clear();
}

bool ConvexHull::AddPoint(  Point2D a )
{
	if(this!=NULL)
	if(m_IsInput  )
	{	m_ListPoint.resize(m_ListPoint.size()+1);
		m_ListPoint[m_ListPoint.size()-1]=a;
		return true;
	}
	else return false;
	else return false;
}

double goc( Point2D a,Point2D b )
{
	return(float(a.y-b.y)/(a.x-b.x));
}
double goctamgiac( Point2D A,Point2D B,Point2D C )
{
	double a2=pow((double)B.x-C.x,2)+pow((double)B.y-C.y,2);
	double b2=pow((double)A.x-C.x,2)+pow((double)A.y-C.y,2);
	double c2=pow((double)B.x-A.x,2)+pow((double)B.y-A.y,2);
	double t=(a2+c2-b2)/(2*sqrt(a2)*sqrt(c2));
	if(t>1) t=1;
	if(t<-1) t=-1;
	return acos(t);
}
Point2D getSecondPoint( vector<Point2D> &myVectorPoint)
{
	Point2D a=myVectorPoint[1];
	double m_min=goc(myVectorPoint[0],myVectorPoint[1]);
	for(unsigned i=1;i<myVectorPoint.size();i++)
	{
		if(m_min>goc(myVectorPoint[0],myVectorPoint[i])) 
		{
			m_min=goc(myVectorPoint[0],myVectorPoint[i]);
			a=myVectorPoint[i];
		}
	}
	return a;
}
Point2D getNextPoint( vector<Point2D> &myVectorPoint,Point2D prePoint,Point2D currentPoint )
{
	Point2D nextPoint=myVectorPoint[0];
	double max_goc=goctamgiac(prePoint,currentPoint,nextPoint);

	for(unsigned int i=0;i<myVectorPoint.size();i++)
	{	if(myVectorPoint[i]!=prePoint && myVectorPoint[i]!=currentPoint)
	{	
		double tmp=goctamgiac(prePoint,currentPoint,myVectorPoint[i]);
		if(max_goc<tmp)
		{
			max_goc=tmp;
			nextPoint=myVectorPoint[i];
		}
	}

	}

	return nextPoint;
}


void ConvexHull::FindConvex()
{
	if(m_ListPoint.size()>1)
	{	
		Point2D tmp=this->GetMinXPoint();
		m_Convex.addPoint(this->GetMinXPoint());
		
		m_Convex.addPoint(getSecondPoint(m_ListPoint));
		Point2D nextPoint=getNextPoint(m_ListPoint, m_Convex.GetPoint(0),m_Convex.GetPoint(1));
		int num=2;
		while (nextPoint!=m_ListPoint[0])
		{
			m_Convex.addPoint(nextPoint);
			nextPoint=getNextPoint(m_ListPoint,m_Convex.GetPoint(num-1),m_Convex.GetPoint(num));
			num++;
		}
		m_Convex.addPoint(m_ListPoint[0]);
	}
}

double ConvexHull::Area()
{
	return (GetArea= m_Convex.Area());
}

bool ConvexHull::Inside( const Point2D &a )
{
	return m_Convex.InSide(a);
}

Point2D ConvexHull::GetMinXPoint()
{
	
	if(m_ListPoint.size()==0) return Point2D(-1,-1);
	else
	{
		Point2D *tmp=new Point2D();
		*tmp=m_ListPoint[0];
		for(unsigned int i=0;i<m_ListPoint.size();i++)
		{
			if((tmp->x)>(m_ListPoint[i].x))
			{
				*tmp=m_ListPoint[i];
				Point2D temp=m_ListPoint[0];
				m_ListPoint[0]=m_ListPoint[i];
				m_ListPoint[i]=temp;
				//swap m_ListPoint[i] va m_ListPoint[0]
			}
		};
		return *tmp;
	}
}

//void ConvexHull::DrawScreen( CDC *pDC )
//{	for(int i=0;i<m_ListPoint.size();i++)
//	{	Point2D tmp=m_ListPoint[i];
//		
//		tmp.Draw(pDC,0);
//		
//	}
//}

size_t ConvexHull::GetNumPoint()
{
	return m_ListPoint.size();
}

Point2D  ConvexHull::GetPoint(unsigned int Index )
{
	if(m_ListPoint.size()>0 && Index<m_ListPoint.size())
	{
		Point2D tmp=m_ListPoint[Index];
		
		return tmp;
	}
	else return Point2D(-1,-1);
}

void ConvexHull::StopInput()
{	if(m_ListPoint.size()>0)
	{	m_IsInput=false;
	
		FindConvex_QuickHull();
		Area();
		GetCentroid=m_Convex.Centroid();
	}
}

void ConvexHull::ContinueInput()
{
	m_IsInput=true;
	m_Convex.clear();
}


void ConvexHull::clear()
{
	
	m_ListPoint.resize(0);
	m_IsInput=true;
	m_Convex.clear();
}
bool IncreaseX(Point2D a,Point2D b)
{
	if(a.x<b.x) return true;
	else return false;
}
bool DecreaseX(Point2D a,Point2D b)
{
	if(a.x>b.x) return true;
	else return false;
}
double CWW(Point2D P,Point2D Q,Point2D R)
{
	double tmp=(Q.x-P.x)*(R.y-P.y)-(R.x-P.x)*(Q.y-P.y);
	return tmp;
}

double Distance(Point2D A,Point2D B,Point2D T)
{

	///a1,b1,c1 he so dt qua AB
	double a1=A.y-B.y;
	double b1=B.x-A.x;
	double c1=a1*A.x+b1*A.y;
	
	///a2,b2,c2 he so dt vuong goc voi AB
	double a2=-b1;
	double b2=a1;
	double c2=a2*T.x+b2*T.y;

	double d=a1*b2-a2*b1;
	double dx=c1*b2-c2*b1;
	double dy=a1*c2-a2*c1;

	Point2D H(dx/d,dy/d);
	return sqrt(pow(T.x-H.x,2)+pow(T.y-H.y,2));
	
}


void ConvexHull::FillHull(vector<Point2D>   & ListPoint,Point2D A,Point2D B,vector<Point2D> & ListHull)
{
	if(ListPoint.size()==0) return;
	unsigned int iPivot=0;
	double maxD=Distance(A,B,(ListPoint)[iPivot]);
	Point2D Pivot=(ListPoint)[iPivot];
	
	
	for(unsigned int i=0;i<ListPoint.size();i++)
	{
		double tmp=Distance(A,B,(ListPoint)[i]);
		if(maxD<tmp)
			{	maxD=tmp;
				Pivot=(ListPoint)[i];
				iPivot=i;
			}
	}

	ListHull.resize(ListHull.size()+1);
	ListHull[ListHull.size()-1]=Pivot;

	
	unsigned int index=0;
	Point2D Index=(ListPoint)[index];
	vector<Point2D> S1(0);
	vector<Point2D> S2(0);

	
	while(index<iPivot)
	{
		if(CWW(A,Pivot,Index)>0 )
		{
			S1.resize(S1.size()+1);
			(S1)[S1.size()-1]=Index;
		}
		Index=(ListPoint)[++index];
	}


	while(index<(ListPoint.size()-1))
	{
		if(CWW(Pivot,B,Index)>0 )
		{
			S2.resize(S2.size()+1);
			(S2)[S2.size()-1]=Index;
		}
		Index=(ListPoint)[++index];
	};

	if(CWW(Pivot,B,Index)>0 )
	{
		S2.resize(S2.size()+1);
		(S2)[S2.size()-1]=Index;
	}


	FillHull(S1,A,Pivot,ListHull);
	FillHull(S2,Pivot,B,ListHull);
	S1.clear();
	S2.clear();
}


void ConvexHull::FindConvex_QuickHull()
{

	m_Convex.clear();
	partial_sort(m_ListPoint.begin(),m_ListPoint.begin()+m_ListPoint.size(),m_ListPoint.end(),IncreaseX);
	vector<Point2D>  UpperList(0);
	vector<Point2D>  LowerList(0);
	vector<Point2D>  LowerHull(0);
	vector<Point2D>  UpperHull(0);
	for(unsigned int i=1;i<m_ListPoint.size()-1;i++)
	{
		if(CWW(m_ListPoint[0],m_ListPoint[m_ListPoint.size()-1],m_ListPoint[i])>=0) 
		{
			UpperList.resize(UpperList.size()+1);
			(UpperList)[UpperList.size()-1]=m_ListPoint[i];

		}
		else
		{
			LowerList.resize(LowerList.size()+1);
			(LowerList)[LowerList.size()-1]=m_ListPoint[i];
		}
	}

	
	FillHull(UpperList,m_ListPoint[0],m_ListPoint[m_ListPoint.size()-1],UpperHull);	
	
	partial_sort(LowerList.begin(),LowerList.begin()+LowerList.size(),LowerList.end(),DecreaseX);

	FillHull(LowerList,m_ListPoint[m_ListPoint.size()-1],m_ListPoint[0],LowerHull);
	
	m_Convex.addPoint(m_ListPoint[0]);

	partial_sort(UpperHull.begin(),UpperHull.begin()+UpperHull.size(),UpperHull.end(),IncreaseX);
	for(unsigned int i=0;i<UpperHull.size();i++) m_Convex.addPoint((UpperHull)[i]);

	m_Convex.addPoint(m_ListPoint[m_ListPoint.size()-1]);

	partial_sort(LowerHull.begin(),LowerHull.begin()+LowerHull.size(),LowerHull.end(),DecreaseX);
	for(unsigned int i=0;i<LowerHull.size();i++) m_Convex.addPoint((LowerHull)[i]);
	m_Convex.Close();

	LowerHull.clear();
	UpperHull.clear();
	LowerList.clear();
	UpperList.clear();
}

//void ConvexHull::Init_Random( int numPoint )
//{
//	/*int x_max=1366;
//	int x_min=0;
//	int y_max=768;
//	int y_min=0;
//	int i=0;
//	while(i<numPoint)
//	{
//	int x = (int)((double)rand() / (RAND_MAX + 1) * (x_max - x_min) + x_min);
//	int y = (int)((double)rand() / (RAND_MAX + 1) * (y_max - y_min) + y_min);
//	CLine tmp(Point2D(20,8),Point2D(CPoint(x,y)));
//	if((tmp.GetLen())<=8 )
//	{	AddPoint(Point2D(CPoint(x,y)));
//	i++;
//	}
//	}*/
//
//	double x_max=40;
//	double x_min=0;
//	double y_max=20;
//	double y_min=0;
//	int i=0;
//	while(i<numPoint)
//	{
//		double x = ((double)rand() / (RAND_MAX + 1) * (x_max - x_min) + x_min);
//		double y = ((double)rand() / (RAND_MAX + 1) * (y_max - y_min) + y_min);
//		CLine tmp(Point2D(x,y),Point2D(20,8));
//		double len=tmp.GetLen();
//		if((len) < 8     )
//		{
//			AddPoint(Point2D(x,y));
//			i++;
//		}
//
//
//	}
//
//}

size_t ConvexHull::GetNumPointOfConvex()
{
	return m_Convex.GetNumPoint();
}

Point2D ConvexHull::GetPointOfConvex( int Index )
{
	return m_Convex.GetPoint(Index);
}

