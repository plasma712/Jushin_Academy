#include <iostream>

using namespace std;

// ##1. 인라인함수
// 함수 코드를 코드 라인 안에 삽입하는 함수.
// 일반함수 호출보다 빠르다.


// 인라인 함수 무조건 안되는 경우 
// 1. 재귀함수.
// 2. 클래스 선언부, 정의부 (cpp / h )로 나눌경우 


// * 인라인은 무조건 되는 것이 아니라 컴파일러가 판단하여 넣거나 뺀다.
// 단점 : 메모리를 많이 먹을 수 있음.

inline int Add(int _a, int _b)
{
	return _a + _b;
}

void main()
{
	Add(10, 20);
	return;
}