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
	// ���� ������ �����ε�
	// ���� ������ �����ε�
	cPoint& operator++()
	{
		++m_iX;
		++m_iY;

		cout << "���� ������" << endl;
		return*this;
	}
	cPoint operator++(int)	//int�� ���� ���� �����ϱ� ���� ǥ����
	{
		cPoint temp(m_iX, m_iY);
		++m_iX;
		++m_iY;

		cout << "���� ������" << endl;
		return temp;
	}


	// ���� ������ �����ε�

	
public:

	void GetXY()
	{
		cout << m_iX << "," << m_iY << endl;
	}


};


void main()
{
	// ���� ������ �����ε�
	// cPoint Pos1(100, 100);
	// 
	// ++Pos1;
	// Pos1.GetXY();

	// ���� ������ �����ε�
	// ���� ���� : �� ���� �� ����.
	// cPoint Pos1(100, 100);
	// cPoint Pos2;
	// Pos2=Pos1++;
	// Pos1.GetXY();
	// Pos2.GetXY();
	
	// ����, ���� ��

	cPoint Pos1(100, 100);
	cPoint Pos2 = ++Pos1;
	Pos2.GetXY();

	cout << "---------------------------------------" << endl;
	cPoint Pos3(100, 100);
	cPoint Pos4 = Pos3++;
	Pos4.GetXY();

	return;
}