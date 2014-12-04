#pragma once
//#include "DLLPSC.h"
#include "Point2D.h"

//#include ".\Obj.h"
#include "LineSegment.h"
#include <vector>
using namespace std;
/*
* Class CPolygon
* Mô tả một đa giác không tự cắt
* Gồm danh sách các đỉnh lưu theo thứ tự
*/
class CPolygon//: public Obj
{
protected:
	vector<unsigned int> m_Parts;
	vector<Point2D> m_VectorPoint;						/// Danh sách điểm của đa giác
public:
	CPolygon(void);
	virtual ~CPolygon(void);
	
	Point2D GetCentroid;									/// Biến lưu giữ trọng tâm của đa giác
	double GetArea;											/// Biến lưu giữ diện tích của đa giác
	double Area();											/// Hàm tính diện tích của đa giác
	
	Point2D Centroid();									/// Hàm tìm trọng tâm của đa giác
	bool Direction();										/// Kiểm tra hướng của đa giác ( trả về TRUE nếu đa giác có hướng theo chiều dương trục tọa độ) 
	bool IsClose();											/// Kiểm tra đa giác đã đóng kín hay chưa (trả về True nếu là đa giác kín, False ngược lại)
	bool Close();											/// Hàm đóng kín đa giác
	bool CheckForAdd(Point2D mPoint);					/// Kiểm tra điểm thêm mới có thỏa mãn điều kiện không tự cắt hay không
	bool checkAndAdd(Point2D a);							/// Thêm đỉnh vào đa giác
	void addPoint(Point2D mPoint);						/// Them ko kiem tra
	void addPoint(double x,double y);
	bool DeletePoint(int Index);							/// Xóa đỉnh thứ Index trong đa giác

	size_t GetNumPoint();										/// Trả về số lượng đỉnh của đa giác
	bool InSide(Point2D mPoint);							/// Kiểm trả điểm mPoint nằm trong hay ngoài đa giác
	Point2D GetLastPoint();								/// Trả về đỉnh cuối của đa giác
	Point2D GetPoint(unsigned int Index);							/// Trả về đỉnh thứ Index trong đa giác
	Point2D GetFirst();									/// Trả về đỉnh đầu tiên trong đa giác
	bool IsDrawing();										/// Hàm trả về true nếu đa giác đang được vẽ
	void clear();											/// xóa toàn bộ dữ liệu đa giác hiện tại
	LineSegment GetLine(unsigned int Index);								/// Trả về đoạn thẳng thứ Index trong đa giác	
	void BreakPart();
	void CloseEnd();
	vector<Point2D>& getListPoint();
	vector<unsigned int>& getListPart();
	void setListPoint(vector<Point2D>& listPoint);
	void setListPart(vector<unsigned int>& listPart);
};

