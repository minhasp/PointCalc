#pragma once
#include <vector>
#include "IntersectedPoint_Derived.h"
//#include "IProgress.h"
#include <map>
#include "CompareLine.h"
#include "ComparePoint.h"
using namespace std;

/*
*	LineSegmentIntersection là lớp cơ sở, tạo một giao diện chung cho việc tính giao cắt của một tập hợp đoạn thẳng
*	nhiệm vụ :
*	+ Quản lý một tập các đoạn thẳng để tính toán
*	+ Quản lý danh sách các điểm giao cắt.
*/
class  LineSegmentIntersection
{
protected:


	vector<IntersectedPoint*> m_IntersectedPoints;						///Lưu danh sách các giao điểm 	

	vector<LineSegment*> m_lineSegs;									///Lưu danh sách các đoạn thẳng


	
public:
	LineSegmentIntersection(void);


	virtual void addLineSegment(double x1,double y1,double x2,double y2,void * data=0);
	/// Thêm một đoạn (x1, y1)-(x2, y2) thẳng vào tập hợp. Trong đó data là kiểu dữ liệu gắn kèm với đoạn thẳng.

	virtual size_t calc(void * progress=0);
	/// Tính toàn bộ giao cắt của tập hơp và trả về số lượng các điểm giao cắt

	virtual size_t getNumberOfIntersectedPoint();
	/// Trả về số lượng điểm giao.

	virtual IntersectedPoint * getIntersectedPoint(size_t at);
	/// Trả về điểm giao cắt tại vị trí at.

	virtual void getResultSegments(vector<LineSegment> & result);
	/// Trả về toàn bộ các đoạn thẳng sau khi đã tính toán bao gồm cả đoạn thẳng có giao cắt và không có giao cắt.

	virtual vector<LineSegment*> getResultSegments_2();

	virtual void clear();
	/// Thu hồi bộ nhớ đã được cấp phát và sử dụng

	virtual ~LineSegmentIntersection(void);
};



