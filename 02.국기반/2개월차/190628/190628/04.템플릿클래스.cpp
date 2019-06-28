#include <iostream>

using namespace std;

// ##1. 클래스 템플릿.

template <typename T>
class cPoint
{
private:
	T m_X;
	T m_Y;
};


template <typename T, int size = 5>
class cArray
{
private:
	T m_Array[size];	// 템플릿이라서 가능하다! 아직 코드가 만들어지기 전 단계
};

void main()
{
	// ## 2. 템플릿 클래스
	cPoint<int>		intPos;    // 이때 int에 대한 코드가 생성. (컴파일시점)
	cPoint<float>   floatPos;  // 이때 float에 대한 코드가 생성. (컴파일시점)

	cArray<int> array1;
	cArray<float, 10>array2;

	// 아래 시점에서 코드가 생성되기 때문에 위와 같이 배열 선언가능.
	cout << sizeof(array1) << endl;
	cout << sizeof(array2) << endl;

	return;
}