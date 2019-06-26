#include <iostream>

using namespace std;

class cPoint
{
private:
	int m_iX;
	int m_iY;

public:
	cPoint()
		:m_iX(0), m_iY(0) {}
	cPoint(int x, int y)
		: m_iX(x), m_iY(y)
	{}

public:
	// 증감 연산자 오버로딩
	// 전위 연산자 오버로딩
	cPoint& operator++()
	{
		++m_iX;
		++m_iY;

		cout << "전위 연산자" << endl;
		return*this;
	}
	cPoint operator++(int)	//int는 후위 연산 구별하기 위한 표현법
	{
		cPoint temp(m_iX, m_iY);
		++m_iX;
		++m_iY;

		cout << "후위 연산자" << endl;
		return temp;
	}


	// 후위 연산자 오버로딩

	
public:

	void GetXY()
	{
		cout << m_iX << "," << m_iY << endl;
	}


};


void main()
{
	// 전위 연산자 오버로딩
	// cPoint Pos1(100, 100);
	// 
	// ++Pos1;
	// Pos1.GetXY();

	// 후위 연산자 오버로딩
	// 후위 연산 : 선 연산 후 증감.
	// cPoint Pos1(100, 100);
	// cPoint Pos2;
	// Pos2=Pos1++;
	// Pos1.GetXY();
	// Pos2.GetXY();
	
	// 전위, 후위 비교

	cPoint Pos1(100, 100);
	cPoint Pos2 = ++Pos1;
	Pos2.GetXY();

	cout << "---------------------------------------" << endl;
	cPoint Pos3(100, 100);
	cPoint Pos4 = Pos3++;
	Pos4.GetXY();

	return;
}