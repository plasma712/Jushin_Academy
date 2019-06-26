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
	cPoint& operator += (const cPoint& copy)
	{
		m_iX += copy.m_iX;
		m_iY += copy.m_iY;

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

	void GetXY()
	{
		cout << m_iX << "," << m_iY << endl;
	}


};


void main()
{

	cPoint Pos1(100, 100);
	cPoint Pos2(200, 200);

	Pos2 += Pos1;
	Pos2.GetXY();
	return;
}