//============================================================================
// Name        : H1.cpp
// Author      : MinhNv
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//#include <unistd.h>
#include <string>
#include <map>
#include <stdio.h>
#include "./Geo/Point2D.h"
#include "Geo/LineSegment.h"
#include "Geo/ConvexHull.h"
#include "Geo/CPolygon.h"
using namespace std;
int noname(int i)
{
	return (i+1);
}
int main() {


	cout<<"Hello from c++ from linux \n";
	cout<<"Hello from c++ from windows \n";

	Point2D ptA(1.0,1.0);
	Point2D ptB(2.0,3.0);
	Point2D ptC,ptD;
	double tmp;

	cout<<"Point A x=";cin>>tmp;ptA.x=(tmp);
	cout<<"Point A y=";cin>>tmp;ptA.y=(tmp);

	cout<<"Point B x=";cin>>tmp;ptB.x=(tmp);
	cout<<"Point B y=";cin>>tmp;ptB.y=(tmp);

	wcout<<"Distance="<<ptA.DistanceTo(ptB)<<endl;



	cout<<"Point C x=";cin>>tmp;ptC.x=(tmp);
	cout<<"Point C y=";cin>>tmp;ptC.y=(tmp);

	cout<<"Point D x=";cin>>tmp;ptD.x=(tmp);
	cout<<"Point D y=";cin>>tmp;ptD.y=(tmp);

	LineSegment l1(ptA,ptB);
	LineSegment l2(ptC,ptD);

	double x,y;

	int result=l1.Intersection2Segment(l2,x,y);


	cout<<"Result ABxCD ="<<result<<"="<<x<<";"<<y<<endl;

	ConvexHull cvh;
	cvh.AddPoint(ptA);
	cvh.AddPoint(ptB);
	cvh.AddPoint(ptC);
	cvh.AddPoint(ptD);

	if(result)
	{
		cvh.AddPoint(Point2D(x,y));
	}

	cvh.FindConvex_QuickHull();
	CPolygon  resultConvex= cvh.m_Convex;

	int numOfPoint=resultConvex.GetNumPoint();
	for	(int i=0;i<numOfPoint;i++)
	{
		cout<<"Point at "<<i<<"="<<resultConvex.GetPoint(i).x<<";"<<resultConvex.GetPoint(i).y<<endl;
	}

	cin.get();
	return 1;
}
