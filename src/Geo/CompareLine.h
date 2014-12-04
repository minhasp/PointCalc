#pragma once
#include "LineSegment.h"


/*
* Lớp CompareLine định nghĩa các phép so sánh của các đoạn thẳng ứng với vị trí hiện tại của đường thẳng quét
* 
*/
class CompareLine
{
private:
	double y;						/// Vị trí tung độ hiện tại của đường thằng quét.
	double x;						/// Tọa độ X của điểm dừng (dùng trong trường hợp có đoạn thẳng nằm trên đường thẳng quét)
public:
	CompareLine();
	CompareLine(double _y);
	void setvalue(double _y);										
	void setvalue(double _x,double _y);								/// Thiết lập vị trí của đường thẳng quét
	bool operator()(LineSegment L1,LineSegment L2)const volatile;					/// Định nghĩa So sánh 2 đoạn thẳng dựa vào vị trí đường thẳng quét
	bool operator()(LineSegment *L1,LineSegment *L2)const volatile;				/// Định nghĩa So sánh 2 con trỏ đoạn thẳng bằng cách so sánh 2 giá trị mà nó trỏ đến
	double getx();
	double gety();
	~CompareLine(void);
};

