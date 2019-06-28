#include <iostream>

using namespace std;
// ##1. 템플릿 (Template)
// 동일한 로직에 대해 여러 자료형을 호환할 수 있게 프로그램을 작성하도록 도와주는 C++ 문법.
// 프로그램을 작성하도록 도와주는 C++문법


// ##2. 함수 템플릿
// 아래와 같은 모양의 함수를 찍어내겠다는 템플릿(틀)이다.
// 구체적인 호출 코드가 없으면 함수 코드는 생성되지 않는다.

template <typename T>
T Add(T a, T b)
{
	return a + b;
}

// 템플릿의 특수화
// 템플릿이 여러 자료형을 호환하지만
// 특정 자료형에 대해서 별도의 다른 동작이 필요할 때
template<>
const char* Add(const char*a,const char*b)
{
	int iTotalLen = strlen(a) + strlen(b);
	char* cTemp = new char;

	//cTemp= strcat();
	return a;
}



void main()
{
	// ##3. 템플릿 함수
	
	// 이 때 int 타입을 가진 함수코드가 선언된다. (컴파일시점)
	int iResult = Add<int>(10, 20); 
	iResult = Add<int>(100, 200); // 위에서 이미 생성된 int 코드를 재사용.

	// 이 때 float 타입을 가진 함수코드가 생성된다. (컴파일시점)
	// float fResult = Add(3.14f, 3.f); // 자료형을 명시하지 않아도 컴파일러가 매개변수로 구별해준다.
	float fResult = Add<float>(3.14f, 3.f);

	// 때론 예외사항이 필요하다.
	char* pTotal = Add<char*>("Hello", "World");
	cout << pTotal << endl;

	delete[] pTotal;


	return;
}