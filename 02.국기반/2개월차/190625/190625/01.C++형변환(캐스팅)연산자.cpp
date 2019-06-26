#include <iostream>

using namespace std;


// ##1. C++ 형변환(캐스팅) 
// static_cast,dynamic_cast,_Const_cast,reinterpret_cast

void main()
{
	// ##2. static _cast (정적 캐스팅)
	// 형변환 시점 : 컴파일 시점.
	// int a = (int)3.14f;				 // C   스타일의 명시적 형변환
	// int b = static_cast<int>(3.14f); // C++ 스타일의 명시적 형변환
	// 
	// int c = 100;
	// double* ptr = (double*)&c;  // C 스타일은 강제 형변환 허용.
	// double* ptr = static_cast<double*>(&c);  // 스타일보다 안전! 컴파일 단계에서 에러.



}