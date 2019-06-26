#include <iostream>

using namespace std;

void Foo(int n)
{

}

// delete 키워드 : 삭제된 함수를 명시.
void Foo(float a) = delete;

void main()
{
	Foo(100);
	// Foo(3.14f); error오류
	return;
}