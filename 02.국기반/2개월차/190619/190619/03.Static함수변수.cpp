#include <iostream>

using namespace std;

class cTest
{
private:
	// static ��� ����.
	// ���� Ŭ������ ������ ��ü���� �����ϴ� ������. Data������ ���.
	static int m_iValue;
	int m_iA = 100;
	
public:			  // static ������ �̴ϼȶ������� ������ ���ÿ� �ʱ�ȭ �Ұ���.
	cTest(int n) // : m_iValue(n)
	{
		cout << &m_iValue << endl;
	}
public:
	void Func()
	{
		cout << &m_iValue << endl;

		StaticFunc();	// OK
	}
public:
	static void StaticFunc()
	{
		// cout << this << endl; // error!
		// Func(); // error ��� �Լ��� ȣ�� �Ұ�
		// m_iA = 200; //error , �Ϲ� ����� ���� �б�, ���� ��� �Ұ�

		cout << "���� ������ ������ �ƴմϴ�." << endl;
	}
};

// static ��� ���� �ʱ�ȭ ����.
//// ��������ó�� ����. ��ü�ȿ� �ִ� ���� �ƴ�.
// static ��� ������ ��ü ���� ���̵� ��밡��.
int cTest::m_iValue = 0;

void main()
{
	//cTest obj1(100);
	//cTest obj2(200);
	//cTest obj3(300);
	//
	//obj1.Func();
	//obj2.Func();
	//obj3.Func();

	// ##2. static ��� �Լ�
	// ��ü ���� ���̵� ȣ�� �� �� �ִ�.
	// ������ c++���� �����Լ��� �ٷ� �� static ��� �Լ��� �ٷ��.
	cTest::StaticFunc();

	return;
}