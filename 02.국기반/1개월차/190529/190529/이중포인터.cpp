#include<iostream>

using namespace std;

void main()
{
	// ##1. ���� ������
	// �����͵� ������ �����̹Ƿ� �ּҰ� �����Ѵ�.
	// �������� �ּҸ� ���� �Ǵٸ� �����͸� ���� �����Ͷ� �Ѵ�.
	int iA = 100;
	int* ptr = &iA;
	int** pptr = &ptr; // ���� ������

	cout << "ptr�� �ּ� : " << &ptr << endl;
	cout << "pptr�� �� : " << pptr << endl;
	cout << "iA�� �� : " << **pptr << endl;

	return;
}