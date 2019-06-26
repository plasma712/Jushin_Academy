#include <iostream>

using namespace std;

// ##1. 복사 생성자
// 1. 객체 생성시 복사가 이루어 질 때
// 2. 함수의 인자로 객체가 전달 받았을 때 (call by value)
// 3. 함수의 반환 값으로 객체를 반환할 때 (call by value)

// 사용자가 복사생성자를 명시하지 않을 때, 디폴트 복사 생성자가 자동으로 생성된다.


class cTest
{
private:
	int m_iValueA;
	int m_iValueB;
public:
	cTest() = default; // 디폴트 생성자와 같은 효과

	cTest(int _a,int _b) : m_iValueA(_a),m_iValueB(_b)
	{}

	// 복사 생성자 원형
	cTest(const cTest& _obj)
	{
		m_iValueA = _obj.m_iValueA;
		m_iValueB = _obj.m_iValueB;

		cout << "복사 생성자" << endl;
	}

	// cTest(const cTest& _obj) = delete;

public:
	void PrintMember()
	{
		cout << m_iValueA << endl;
		cout << m_iValueB << endl;
	}
};

// ##3. 함수의 인자로 객체를 전달 받았을 때(call by value) 복사생성자 호출.
void Func(cTest obj)
{

}

// ## 4. 함수의 반환값으로 객체를 반환할 때 (call by value) 복사생성자 호출.

cTest Foo()
{
	cTest obj;
	return obj;
}

void main()
{
	//// ##2.객체 생성시 객체 간 복사가 이루어질 때 복사 생성자 호출.
	// cTest objA(100, 200);
	// // cTest objB = objA;	//복사 생성자 호출
	// cTest objB(objA);
	// objB.PrintMember();

	// cTest objA(100, 200);
	// Func(objA); //call by value

	Foo();

	
	return;
}