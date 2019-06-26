#include <iostream>

using namespace std;

// 대입 연산자를 명시하지 않으면 컴파일러가 디폴트 대입 연산자를 생성한다.

// **** 컴파일러가 자동 생성하는 4가지
// 1. 디폴트 생성자
// 2. 디폴트 소멸자
// 3. 디폴트 복사생성자
// 4. 디폴트 복사소멸자
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
	// 얕은 복사에 유의해라.
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



};


void main()
{

	cPoint Pos1(100, 100);
	cPoint Pos2 = Pos1;
	cout << Pos2.GetX() << "," << Pos2.GetY() << endl;

	cPoint Pos3;
	Pos3 = Pos1;
	cout << Pos3.GetX() << "," << Pos3.GetY() << endl;


	return;
}