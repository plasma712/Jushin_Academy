#include <iostream>

using namespace std;

class cTest
{
private:
	int m_iValue;
public:
	cTest(int n) : m_iValue(n)
	{
		cout << "������" << endl;
	}
public:
	void Func()
	{
		/*this->*/ m_iValue = 200;
		cout << &/*this->*/m_iValue << endl;
	}

	void PrintThis()
	{
		// this ������ : ���� ��ü�� �ּҸ� ������ ������.
		cout << this << endl;
	}
};


void main()
{
	cTest obj1(100);
	cTest obj2(200);
	cTest obj3(300);

	obj1.Func();
	obj1.PrintThis();
	obj2.Func();
	obj2.PrintThis();
	obj3.Func();
	obj3.PrintThis();
	return;
}