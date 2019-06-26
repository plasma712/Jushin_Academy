#include <iostream>

using namespace std;

// ##1. 연산자 오버로딩 (연산자 함수)
// 기존의 연산자를 재정의하는 C++문법.

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

	cPoint(const cPoint &copy)
	{
		m_iX = copy.m_iX;
		m_iY = copy.m_iY;

		cout << "복사 생성자" << endl;
	}
public:
	// 디폴트 대입 연산자의 원형
	cPoint& operator = (const cPoint &copy)
	{
		m_iX = copy.m_iX;
		m_iY = copy.m_iY;

		cout << "대입 연산자" << endl;

		return *this;

	}
public:
	int GetX()
	{
		return m_iX;
	}
	int GetY()
	{
		return m_iY;
	}

	//cPoint operator+(const cPoint& pos) const
	//{
	//	int x = m_iX + pos.m_iX;
	//	int y = m_iY + pos.m_iY;
	//
	//	cPoint temp(x, y);
	//
	//	// return cPoint(x, y); // 임시객체
	//	return temp;
	//}

	cPoint operator+(int iMove) const
	{
		int x = m_iX + iMove;
		int y = m_iY + iMove;

		cPoint temp(x, y);

		// return cPoint(x, y); // 임시객체
		return temp;
	}

};

// cPoint AddPoint(cPoint pos1, cPoint pos2)
// {
// 	int x = pos1.GetX() + pos2.GetX();
// 	int y = pos1.GetY() + pos2.GetY();
// }

// 전역 연산자 오버로딩
// 인자 중 하나는 객체 타입이거나 객체의 래퍼런스 타입이어야한다.
// cPoint operator + (int iMove, const cPoint &pos)
// {
// 	return pos + iMove;
// }

// [], () 등의 연산자들은 전역으로 정의할 수 없다.


void main()
{
	// cPoint pos1(100, 100);
	// cPoint pos2(200, 200);
	// //cPoint pos3 = AddPoint(pos1, pos2);
	// // 덧셈 연산자를 오버로딩하면서 객체 간의 덧셈이 가능해졌다.
	// cPoint pos3 = pos1 + pos2;
	// cout << pos3.GetX() << "," << pos3.GetY() << endl;
	// //cPoint pos4 = pos1.operator+(pos2);
	

	// ##3.
	// cPoint Pos1(100, 100);
	// cPoint Pos2 = Pos1 + 500;
	// cout << Pos2.GetX() << "," << Pos2.GetY() << endl;
	// 
	// cPoint Pos3 = 500 + Pos1;
	// cout << Pos3.GetX() << "," << Pos3.GetY() << endl;

	cPoint Pos1(100,100);
	cPoint Pos2 = Pos1;
	cout << Pos2.GetX() << "," << Pos2.GetY() << endl;

	cPoint Pos3;
	Pos3 = Pos1;
	cout << Pos3.GetX() << "," << Pos3.GetY() << endl;


	return;
}