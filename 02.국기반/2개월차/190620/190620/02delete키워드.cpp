#include <iostream>

using namespace std;

void Foo(int n)
{

}

// delete Ű���� : ������ �Լ��� ���.
void Foo(float a) = delete;

void main()
{
	Foo(100);
	// Foo(3.14f); error����
	return;
}