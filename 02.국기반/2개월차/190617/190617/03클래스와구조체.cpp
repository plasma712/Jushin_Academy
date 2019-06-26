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

	// 구조체의 멤버는 기본 public이다.
	object1.m_iMoney = 100;
	// 클래스의 멤버는 기본 private이다.
	object2.m_iMoney = 200;

	system("pause");
	return;
}