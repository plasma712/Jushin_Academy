#include <iostream>

using namespace std;


// ##1. 클래스와 const
class cTest
{
private:
	const int m_iConst;
	int m_iValue;

public:
	cTest()
		// 이니셜라이저: 선언과 동시에 초기화 효과.
		:m_iConst(100), m_iValue(200)
	{
		//m_iConst = 100; // error, const 변수는 선언과 동시에 초기화
		cout << "생성자" << endl;
	}
	cTest(int a, int b) : m_iConst(a), m_iValue(b)
	{

	}
	~cTest()
	{
		cout << "소멸자" << endl;
	}
public:
	// ##2. const 멤버함수 : 읽기 전용 함수.
	// 멤버함수에 한해서 const화 가능
	void ConstFunc() const
	{
		// const 멤버함수 내부에서는 멤버변수의 값을 수정할 수 없다.
		// m_iValue = 200; // error
		int i = 200; // 지역변수 값 수정 가능.

		cout << "const 멤버 함수입니다." << endl;
		// const 멤버함수 내부에서는 const 멤버함수 호출 가능

	}

	void NormalFunc()
	{
		cout << "일반 멤버 함수 입니다." << endl;
		// 일반 멤버함수 내부에서는 const 멤버함수 호출 가능
		Func();
	}

	void Func() const
	{
		cout << "const Func" << endl;
	}
	void Func()
	{
		cout << "Func" << endl;
	}
};



void main()
{
	// ##3. const 객체
	
	const cTest obj;
	cTest obj1;
	// const 객체는 const 멤버함수만 호출 가능.
	// 즉, 자신의 멤버 값 변경을 허용하지 않는다.
	// obj.ConstFunc();	// ok
	// obj.NormalFunc();	// error

	obj.Func();
	obj1.Func();
	return;
}