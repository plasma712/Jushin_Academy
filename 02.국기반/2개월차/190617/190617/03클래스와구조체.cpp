#include <iostream>

using namespace std;

struct tagCustomer
{
	int m_iMoney;
};

class cCustomer
{
	int m_iMoney;
};

void main()
{
	tagCustomer object1;
	cCustomer object2;

	// ����ü�� ����� �⺻ public�̴�.
	object1.m_iMoney = 100;
	// Ŭ������ ����� �⺻ private�̴�.
	object2.m_iMoney = 200;

	system("pause");
	return;
}