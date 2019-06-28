#include <iostream>

using namespace std;

template<typename T>
class cAdd
{
public:
	T operator()(T a, T b)
	{
		return a + b;
	}
};

// ##1. 클래스 템플릿 특수화
template<>
class cAdd<char*>
{
public:
	char* operator()(char* a, char* b)
	{

	}
};

void main()
{

	cAdd<int> functor1;
	cout << functor1(10,20) << endl;

	cAdd<char*> functor2;
	//char* pName = functor2("Hello", "World");
	cout << pName << endl;

	delete[] pName;
	return;
}