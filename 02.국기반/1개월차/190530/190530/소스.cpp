#include <iostream> 

using namespace std;

int Add(int a, int b);
void PrintHello();

void main()
{
	// ##1. �Լ� ������
	// �Լ��� �̸��� �Լ� �ڵ尡 ��ϵǾ��ִ� �޸� �������� �ּҸ� �ǹ��Ѵ�.
	// �Լ��̸��� �� �������̴�.

	// cout << Add << endl;
	// Add(10, 20);
	

	// ##2. �Լ� ������ Ÿ��.
	// ��ȯŸ��(*������)(�Ű�����Ÿ��)
	int(*ptr)(int, int) = Add;
	void(*ptr2)() = PrintHello;


	int iResult = ptr(10, 20);
	cout << iResult << endl;
	ptr2();

	return;
}

int Add(int a, int b)
{
	return a + b;
}

void PrintHello()
{
	cout << "Hello" << endl;
}