#include <iostream>

using namespace std;

// ##1. ����ü (union) -> ����� ���� �ڷ���

union uniBox
{
	int a;
	short b;
};

struct tagBox
{
	int a;
	short b;
};

// ��� ����� �ϳ��� �޸𸮸� �����ϱ� ������ �Ʒ��� ���� ����� ������ �� �ִ�.
union uniMatrix
{
	struct
	{
		float _11, _12, _13;
		float _21, _22, _23;
		float _31, _23, _33;
	};

	float m[3][3];
};

void main()
{
	// ����ü vs ����ü
	// ����ü�� ����ü�� �޸� ��� ����� �ϳ��� �޸𸮸� �����Ѵ�.
	// ��� �� ���� ū �޸𸮸� �����Ѵ�.
	//cout << sizeof(uniBox) << endl;
	//cout << sizeof(tagBox) << endl;
	//
	// uniBox uBox={10,20}; ����üó�� �ʱ�ȭ X
	//uniBox uBox;
	//
	//cout << &(uBox.a) << endl;
	//cout << &(uBox.b) << endl;

	uniMatrix mat;
	mat.m[1][1] = 3.14;

	return;
}