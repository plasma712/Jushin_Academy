#include <iostream> 

using namespace std;

static int iMyGlobal;

int MyFunc(int n = 0)
{
	//int iA = 0;
	// static ����(��������) : Data������ ��ϵǴ� ������.
	static int iA = 0;  // ���� �ѹ��� �ʱ�ȭ ����
	iA += n;
	return iA;
}

void main()
{
	static int iMyStatic;

	// ���������� ����(Static)������ �ʱ�ȭ�� 0���� �ڵ����� ���ش�.(�ʱ�ȭ �����ٰ��)
	cout << iMyGlobal << endl;
	cout << iMyStatic << endl;



	// for (int i = 0; i < 5; i++)
	// 	MyFunc(10);
	// 
	// cout << MyFunc() << endl;
	// cout << iA << endl; // erorr, ���������� ������ ����Ư���� ���´�.
	// return;
}