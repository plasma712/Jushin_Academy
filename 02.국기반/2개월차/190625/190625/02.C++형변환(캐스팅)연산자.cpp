#include <iostream>

using namespace std;




class cBase
{
public:
	virtual ~cBase() {}
public:
	void Func()
	{
		cout << "Base 멤버 함수" << endl;
	}

};

class cChild : public cBase
{
public:
	void Func()
	{
		cout << "Child 멤버 함수" << endl;
	}
};

void main()
{
	// ##1. Static_cast의 문제점
	// cBase* ptr = new cBase;

	// static_cast는 해당 다운캐스팅이 올바른 것인지 잘못된 것인지 파악 못함.
	// 부모클래스는 자식클래스의 멤버함수,변수를 사용할 수 없다.
	// static_cast<cChild*>(ptr)->Func();

	// ##2. dynamic_cast
	// 형변환 시점 : 런타임
	// 클래스에서만 사용이 가능한 연산자.
	// 사용조건 : 클래스 내부에 virtual 키워드가 반드시 존재해야 함.

	// cBase* ptr = new cBase;
	// //cChild* ptr2 = static_cast<cChild*>(ptr);
	// 
	// cChild* ptr2 = dynamic_cast<cChild*>(ptr);
	// 
	// if (ptr2 == nullptr)
	// 	cout << "잘못된 다운캐스팅 입니다." << endl;
	// 
	// cout << "올바른 다운캐스팅 입니다." << endl;
	// 
	// delete ptr;

	// ##3. dynamic_cast의 형변환 대상은 클래스의 포인터나 래퍼런스 타입이어야한다.
	cBase base;
	cChild child = dynamic_cast<cChild>(base);

}