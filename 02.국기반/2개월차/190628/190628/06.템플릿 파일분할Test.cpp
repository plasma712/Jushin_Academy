#include <iostream>

// ���ø��� ���Ϻ��� ���� �� cpp���� include ���־�� ���� ���尡 �ȴ�.
// ���� ���ø��� ��������� ����� ��� �ۼ��Ѵ�.
#include "Test.h"
#include "Test.cpp"
using namespace std;

void main()
{
	cTest<int> functor;
	cout << functor(10, 20) << endl;
}
