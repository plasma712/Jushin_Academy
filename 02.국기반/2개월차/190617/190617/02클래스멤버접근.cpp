#include <iostream>

using namespace std;

// ##1. 멤버 접근 지정자. (제어 지시자)
// public : 클래스 내부 외부 모두 접근 허용.
// protected : 상속관계에서는 접근 허용. 외부에서 접근 불가.
// private : 클래스 내부에서만 접근이 가능.

class cTest
{
public:
	void Func()
	{
		m_iA = 100;	// public 멤버는 어디서든 접근 가능.
		m_iB = 200;	// private 멤버는 내부에서만 접근 가능.
	}
public:
	int m_iA;
	int a;
	int b;
private:
	int m_iB;
	int c;
};


void main()
{
	cTest obj;

	obj.m_iA = 100;	// public 멤버는 외부에서도 접근 가능.
	obj.m_iB = 200; // private 멤버는 외부에서는 접근 불가능.

	system("pause");
	return;
}