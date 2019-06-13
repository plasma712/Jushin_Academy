#include <iostream>

using namespace std;

// ##1. 공용체 (union) -> 사용자 정의 자료형

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

// 모든 멤버가 하나의 메모리를 공유하기 때문에 아래와 같이 행렬을 정의할 수 있다.
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
	// 공용체 vs 구조체
	// 공용체는 구조체와 달리 모든 멤버가 하나의 메모리를 공유한다.
	// 멤버 중 가장 큰 메모리를 공유한다.
	//cout << sizeof(uniBox) << endl;
	//cout << sizeof(tagBox) << endl;
	//
	// uniBox uBox={10,20}; 구조체처럼 초기화 X
	//uniBox uBox;
	//
	//cout << &(uBox.a) << endl;
	//cout << &(uBox.b) << endl;

	uniMatrix mat;
	mat.m[1][1] = 3.14;

	return;
}