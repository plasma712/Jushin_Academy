#include <iostream>

using namespace std;

// ##1. ��� ���� ������. (���� ������)
// public : Ŭ���� ���� �ܺ� ��� ���� ���.
// protected : ��Ӱ��迡���� ���� ���. �ܺο��� ���� �Ұ�.
// private : Ŭ���� ���ο����� ������ ����.

class cTest
{
public:
	void Func()
	{
		m_iA = 100;	// public ����� ��𼭵� ���� ����.
		m_iB = 200;	// private ����� ���ο����� ���� ����.
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

	obj.m_iA = 100;	// public ����� �ܺο����� ���� ����.
	obj.m_iB = 200; // private ����� �ܺο����� ���� �Ұ���.

	system("pause");
	return;
}