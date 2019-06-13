#include <iostream>

using namespace std;

// ##1. 디폴트 매개변수
// 함수를 더 유연하게 구성하는 문법. C++부터 등장.

int Add(int a, int b, int c = 0/*디폴트 매개변수*/)
{
	return a + b + c;
}

int Add(int a, int b) // 위 함수의 c 매개변수가 디폴트로 설정되어있어 현재함수와 모호하게 된다. 그래서 에러
{					  // 위의 함수의 디폴트 매개변수를 삭제를 하면 함수오버로딩으로 가능하다.
	return a + b;
}

// 디폴트 매개변수를 오른쪽 매개변수부터 채워 나가야 한다.
// 현재 인자 b에 디폴트를 설정하고 싶다면 C에게도 디폴트가 설정되어야 한다.

int Min(int a, int b, int c) // error
{
	return a - b - c;
}