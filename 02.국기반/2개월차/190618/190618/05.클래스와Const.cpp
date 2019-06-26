#include <iostream>

using namespace std;


// ##1. Ŭ������ const
class cTest
{
private:
	const int m_iConst;
	int m_iValue;

public:
	cTest()
		// �̴ϼȶ�����: ����� ���ÿ� �ʱ�ȭ ȿ��.
		:m_iConst(100), m_iValue(200)
	{
		//m_iConst = 100; // error, const ������ ����� ���ÿ� �ʱ�ȭ
		cout << "������" << endl;
	}
	cTest(int a, int b) : m_iConst(a), m_iValue(b)
	{

	}
	~cTest()
	{
		cout << "�Ҹ���" << endl;
	}
public:
	// ##2. const ����Լ� : �б� ���� �Լ�.
	// ����Լ��� ���ؼ� constȭ ����
	void ConstFunc() const
	{
		// const ����Լ� ���ο����� ��������� ���� ������ �� ����.
		// m_iValue = 200; // error
		int i = 200; // �������� �� ���� ����.

		cout << "const ��� �Լ��Դϴ�." << endl;
		// const ����Լ� ���ο����� const ����Լ� ȣ�� ����

	}

	void NormalFunc()
	{
		cout << "�Ϲ� ��� �Լ� �Դϴ�." << endl;
		// �Ϲ� ����Լ� ���ο����� const ����Լ� ȣ�� ����
		Func();
	}

	void Func() const
	{
		cout << "const Func" << endl;
	}
	void Func()
	{
		cout << "Func" << endl;
	}
};



void main()
{
	// ##3. const ��ü
	
	const cTest obj;
	cTest obj1;
	// const ��ü�� const ����Լ��� ȣ�� ����.
	// ��, �ڽ��� ��� �� ������ ������� �ʴ´�.
	// obj.ConstFunc();	// ok
	// obj.NormalFunc();	// error

	obj.Func();
	obj1.Func();
	return;
}