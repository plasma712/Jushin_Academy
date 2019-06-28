#include <iostream>

using namespace std;

// ##1. 여러 typename을 받는 함수 템플릿
template <typename T1, typename T2, typename T3>
void Func(T1 a, T2 b, T3)
{

}

void main()
{
	Func<int, float, double>(10, 3.14f, 3.141592);

	return;
}