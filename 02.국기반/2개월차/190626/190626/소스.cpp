#include <iostream>

using namespace std;

// ##1. ������ �����ε� (������ �Լ�)
// ������ �����ڸ� �������ϴ� C++����.

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

		cout << "���� ������" << endl;
	}
public:
	// ����Ʈ ���� �������� ����
	cPoint& operator = (const cPoint &copy)
	{
		m_iX = copy.m_iX;
		m_iY = copy.m_iY;

		cout << "���� ������" << endl;

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
	//	// return cPoint(x, y); // �ӽð�ü
	//	return temp;
	//}

	cPoint operator+(int iMove) const
	{
		int x = m_iX + iMove;
		int y = m_iY + iMove;

		cPoint temp(x, y);

		// return cPoint(x, y); // �ӽð�ü
		return temp;
	}

};

// cPoint AddPoint(cPoint pos1, cPoint pos2)
// {
// 	int x = pos1.GetX() + pos2.GetX();
// 	int y = pos1.GetY() + pos2.GetY();
// }

// ���� ������ �����ε�
// ���� �� �ϳ��� ��ü Ÿ���̰ų� ��ü�� ���۷��� Ÿ���̾���Ѵ�.
// cPoint operator + (int iMove, const cPoint &pos)
// {
// 	return pos + iMove;
// }

// [], () ���� �����ڵ��� �������� ������ �� ����.


void main()
{
	// cPoint pos1(100, 100);
	// cPoint pos2(200, 200);
	// //cPoint pos3 = AddPoint(pos1, pos2);
	// // ���� �����ڸ� �����ε��ϸ鼭 ��ü ���� ������ ����������.
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