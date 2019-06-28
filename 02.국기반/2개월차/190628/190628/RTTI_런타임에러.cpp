#include <iostream>
#include <typeinfo>
using namespace std;

// ##1. RTTI (RunTime Type Information)
// 런타임 도중에 타입의 정보를 알아낼 수 있는 C++ 기법
// 가상함수 테이블에 현재 클래스 타입 이름도 같이 기록됨.


class cBase
{
public:
	virtual ~cBase() {};
};

class cChild : public cBase
{
public:
	virtual void ChildFunc()
	{
		cout << "자식함수" << endl;
	}
};

void main()
{

	// ##1. 올바르지 않은 다운 캐스팅의 문제점.
	// cBase의 가상함수 테이블에는 cChildFunc함수가 존재하지 않으므로 런타임 에러
	// cBase* ptr = new cBase;
	// 
	// // static_cast<cChild*>(ptr)->ChildFunc();
	// // 
	// delete ptr;

	// ##2. typeid 연산자
	// cBase* ptr1 = new cBase;
	// cBase* ptr2 = new cChild;
	// 
	// cout << typeid(ptr1).name() << endl;
	// cout << typeid(ptr2).name() << endl;
	// 
	// cout << "---------------------------------------" << endl;
	// 
	// cout << typeid(*ptr1).name() << endl;
	// cout << typeid(*ptr2).name() << endl;

	//delete ptr1;
	//delete ptr2;

	// ##3. typeid 연산자로 해결

	// cBase* ptr = new cBase;
	// cBase* ptr = new cChild;
	// 
	// if (!strcmp("class cChild", typeid(*ptr).name()))
	// 	static_cast<cChild*>(ptr)->ChildFunc();
	// else
	// 	cout << "다운 캐스팅이 올바르지 않습니다." << endl;
	// 
	// delete ptr;

	// ##4. 결국 dynamic_cast는 RTTI를 기반으로 작동한다.
	return;
}