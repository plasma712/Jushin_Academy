#include <iostream>

using namespace std;

// ##1. ��ũ�� �Լ�
// �ڵ带 �ܼ� ġȯ�ϹǷ� �Ϲ� �Լ��� ���� ����ӵ��� ������.
// �ڷ����� ���������� �ʴ�.
// �Լ��ڵ尡 ������� �����ϱⰡ �ſ� ��ٷӴ�.
#define PI 3.14f


// #define SQUARE(X) X * X
#define SQUARE(X) (X) * (X)

// ���� ���̸� ���ϴ� ��ũ��
#define ARER_CIRCLE(R) SQUARE(R) * PI


// #define SAFE_DELETE(ptr) if(ptr){delete ptr; ptr = nullptr;}
// ��ũ�ΰ� �����̻� �� �� \ Ȱ��.
#define SAFE_DELETE(ptr) \
if(ptr)					 \
{						 \
	delete ptr;			 \
	ptr = nullptr;		 \
}


void main()
{

	// ## 1. ��ũ�� �Լ�.
	// cout << SQUARE(2) << endl; // cout << 2 * 2 << endl;
	cout << SQUARE(2 + 2) << endl; // cout << (2 + 2) * (2 + 2) << endl;

	int* p = new int;
	SAFE_DELETE(p);

	system("pause");
	return;
}