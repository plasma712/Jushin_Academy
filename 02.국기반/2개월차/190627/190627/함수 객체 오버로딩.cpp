#include <iostream>

using namespace std;

// ##1. �Լ� ��ü (Functor, �Լ���)
// () �����ڸ� �����ε��Ͽ� ��ġ ��ü�� �Լ�ó�� �ٷ� �� �ִ�.

class cAdd
{
public:
	// �Լ� ȣ�� ������ �����ε��� �Ű����� ������ ������ ����.(������ �����ε����� �ٸ� ���)
	int operator() (int a, int b)
	{
		return a + b;
	}
};

void main()
{
	cAdd functor;	// �Լ���ü
	cout << "10 + 20 = " << functor(10, 20) << endl;
	cout << "40 + 50 = " << cAdd()(40, 50) << endl;
	return;
}