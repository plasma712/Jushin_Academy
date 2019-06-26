#include <iostream>

using namespace std;

// ���� �����ڸ� ������� ������ �����Ϸ��� ����Ʈ ���� �����ڸ� �����Ѵ�.

// **** �����Ϸ��� �ڵ� �����ϴ� 4����
// 1. ����Ʈ ������
// 2. ����Ʈ �Ҹ���
// 3. ����Ʈ ���������
// 4. ����Ʈ ����Ҹ���
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
	// ���� ���翡 �����ض�.
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