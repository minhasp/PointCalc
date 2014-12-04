#include "ComparePoint.h"


ComparePoint::ComparePoint(void)
{
}


ComparePoint::~ComparePoint(void)
{
}

bool ComparePoint::operator()( IntersectedPoint d1,IntersectedPoint d2 )const volatile
{
	return d1<d2;

}

bool ComparePoint::operator()( IntersectedPoint *d1,IntersectedPoint *d2 )const volatile
{
	return operator()(*d1,*d2);
}

//bool ComparePoint::operator()( IntersectedPoint_Derived*d1,IntersectedPoint_Derived*d2 )
//{
//	return ((*d1)<(*d2));
//}
