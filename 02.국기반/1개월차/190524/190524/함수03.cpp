#include <iostream>

using namespace std;

// ##1. �Լ� �����ε�
// ���� �̸����� �Լ��� �������ϴ� C++ �����̴�.
// ���α׷����� �� �� �����ϰ� �ۼ� �����ִ� �����̴�.

// void Print() // �Լ� �����ε��� ��ȯŸ������ �����ϴ� ������ �ƴϴ�!
// {
// 	cout << "Hello" << endl;
// }
// 
// float Print() // ������ error!
// {
// 	cout << "World" << endl;
// }

int Add(int a, int b)
{
	return a + b;
}

int Add(int a, int b,int c)
{
	return a + b + c;
}

float Add(float a, float b)
{
	return a + b;
}



void main()
{
	// �Լ� �����ε��� ���� �̸��� �Լ��� �Ű������� �����Ѵ�.
	// cout << Add(3.14f,10.f) << endl;

	// �Լ� �����ε��� �Ű����� �����ε� �����Ѵ�.
	cout << Add(1, 2, 3) << endl;

	return;
}