#include <iostream>

using namespace std;

class cTest
{
private:
	int m_iValue;
public:
	cTest(int n) : m_iValue(n)
	{
		cout << "생성자" << endl;
	}
public:
	void Func()
	{
		/*this->*/ m_iValue = 200;
		cout << &/*this->*/m_iValue << endl;
	}

	void PrintThis()
	{
		// this 포인터 : 현재 객체의 주소를 저장한 포인터.
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