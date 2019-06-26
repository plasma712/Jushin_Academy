#include <iostream>

using namespace std;

// ##1. ���� ������
// 1. ��ü ������ ���簡 �̷�� �� ��
// 2. �Լ��� ���ڷ� ��ü�� ���� �޾��� �� (call by value)
// 3. �Լ��� ��ȯ ������ ��ü�� ��ȯ�� �� (call by value)

// ����ڰ� ��������ڸ� ������� ���� ��, ����Ʈ ���� �����ڰ� �ڵ����� �����ȴ�.


class cTest
{
private:
	int m_iValueA;
	int m_iValueB;
public:
	cTest() = default; // ����Ʈ �����ڿ� ���� ȿ��

	cTest(int _a,int _b) : m_iValueA(_a),m_iValueB(_b)
	{}

	// ���� ������ ����
	cTest(const cTest& _obj)
	{
		m_iValueA = _obj.m_iValueA;
		m_iValueB = _obj.m_iValueB;

		cout << "���� ������" << endl;
	}

	// cTest(const cTest& _obj) = delete;

public:
	void PrintMember()
	{
		cout << m_iValueA << endl;
		cout << m_iValueB << endl;
	}
};

// ##3. �Լ��� ���ڷ� ��ü�� ���� �޾��� ��(call by value) ��������� ȣ��.
void Func(cTest obj)
{

}

// ## 4. �Լ��� ��ȯ������ ��ü�� ��ȯ�� �� (call by value) ��������� ȣ��.

cTest Foo()
{
	cTest obj;
	return obj;
}

void main()
{
	//// ##2.��ü ������ ��ü �� ���簡 �̷���� �� ���� ������ ȣ��.
	// cTest objA(100, 200);
	// // cTest objB = objA;	//���� ������ ȣ��
	// cTest objB(objA);
	// objB.PrintMember();

	// cTest objA(100, 200);
	// Func(objA); //call by value

	Foo();

	
	return;
}