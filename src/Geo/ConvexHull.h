#pragma once
#include "Point2D.h"
#include "CPolygon.h"
//#include "Obj.h"
//#include "DLLPSC.h"
#include <vector>
//#include <crtdefs.h>
using namespace  std;
	/**
    * Class ConvexHull:
	* Biểu diễn Bao lồi bao gồm
	* - 1 danh sách điểm lưu trong m_ListPoint
	* - 1 đa giác chính là bao lồi của tập điểm
    */
class  ConvexHull//:public Obj
{
public:
	vector <Point2D> m_ListPoint;				///Lưu danh sách tập điểm
	CPolygon m_Convex;								///Đa giác bao lồi của tập điểm
private:


	/*
	* FillHull : Hàm tìm bao lồi
	* Với tập điểm đầu vào ListPoint
	* A,B là 2 điểm biên
	* Các điểm nằm trên bao được lưu trong ListHull
	*/
	void FillHull(vector<Point2D>  & ListPoint,Point2D A,Point2D B,vector<Point2D> & ListHull);

public:

	ConvexHull(void);





	~ConvexHull(void);

	bool m_IsInput;								/// Biến trạng thái , True nếu đang cho phép nhập điểm vào danh sách




	bool AddPoint(Point2D a);				/// thêm điểm vào danh sách bao lồi


	double GetArea;								/// Biến lưu giá trị diện tích
	Point2D GetCentroid;						/// Biến lưu tâm của đa giác bao lồi


	Point2D GetMinXPoint();					/// Trả về điểm trái nhất trong danh sách
	Point2D GetPoint(unsigned int Index);				/// Trả về điểm thứ Index trong danh sách điểm
	Point2D GetPointOfConvex(int Index);		/// Trả về điểm thứ Index trong đa giác bao lồi
		

	size_t GetNumPoint();							/// Trả về số lượng điểm trong danh sách điểm
	size_t GetNumPointOfConvex();					/// Trả về số lượng điểm trên bao lồi
	double Area();								/// Hàm tính diện tích đa giác bao lồi
	bool Inside(const Point2D &a);			/// Kiểm tra điểm a nằm trong hay ngoài bao lồi ( True nằm trong, False ngược lại)

	void FindConvex();							/// Hàm tìm kiểm bao lồi theo giải thuật ....
	void FindConvex_QuickHull();				/// Hàm tìm kiểm bao lồi theo giải thuật QuickHull
	
	void StopInput();							/// Kết thúc quá trình nhập điểm vào danh sách
	void ContinueInput();						/// Tiếp tục nhập điểm vào danh sách
	void clear();								/// Xóa hết dữ liệu về ConvexHull hiện thời

	//void Init_Random(int numPoint);				/// Khới tạo ngẫu nhiên danh sách điểm với số lượng numPoint


};

