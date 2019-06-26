#include <iostream>

using namespace std;

// ##1. 매크로 함수
// 코드를 단순 치환하므로 일반 함수에 비해 실행속도가 빠르다.
// 자료형에 의존적이지 않다.
// 함수코드가 길어지면 정의하기가 매우 까다롭다.
#define PI 3.14f


// #define SQUARE(X) X * X
#define SQUARE(X) (X) * (X)

// 원의 넓이를 구하는 매크로
#define ARER_CIRCLE(R) SQUARE(R) * PI


// #define SAFE_DELETE(ptr) if(ptr){delete ptr; ptr = nullptr;}
// 매크로가 두줄이상 일 때 \ 활용.
#define SAFE_DELETE(ptr) \
if(ptr)					 \
{						 \
	delete ptr;			 \
	ptr = nullptr;		 \
}


void main()
{

	// ## 1. 매크로 함수.
	// cout << SQUARE(2) << endl; // cout << 2 * 2 << endl;
	cout << SQUARE(2 + 2) << endl; // cout << (2 + 2) * (2 + 2) << endl;

	int* p = new int;
	SAFE_DELETE(p);

	system("pause");
	return;
}