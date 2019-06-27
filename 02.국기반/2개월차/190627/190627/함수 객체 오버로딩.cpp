#include <iostream>

using namespace std;

// ##1. 함수 객체 (Functor, 함수자)
// () 연산자를 오버로딩하여 마치 객체를 함수처럼 다룰 수 있다.

class cAdd
{
public:
	// 함수 호출 연산자 오버로딩은 매개변수 개수에 제한이 없다.(연산자 오버로딩과는 다른 모습)
	int operator() (int a, int b)
	{
		return a + b;
	}
};

void main()
{
	cAdd functor;	// 함수객체
	cout << "10 + 20 = " << functor(10, 20) << endl;
	cout << "40 + 50 = " << cAdd()(40, 50) << endl;
	return;
}