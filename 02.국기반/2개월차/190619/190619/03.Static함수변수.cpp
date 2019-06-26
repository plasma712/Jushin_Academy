#include <iostream>

using namespace std;

class cTest
{
private:
	// static 멤버 변수.
	// 같은 클래스로 생성된 객체들이 공유하는 변수다. Data영역에 등록.
	static int m_iValue;
	int m_iA = 100;
	
public:			  // static 변수는 이니셜라이저로 생성과 동시에 초기화 불가능.
	cTest(int n) // : m_iValue(n)
	{
		cout << &m_iValue << endl;
	}
public:
	void Func()
	{
		cout << &m_iValue << endl;

		StaticFunc();	// OK
	}
public:
	static void StaticFunc()
	{
		// cout << this << endl; // error!
		// Func(); // error 멤버 함수도 호출 불가
		// m_iA = 200; //error , 일반 멤버에 대한 읽기, 쓰기 모두 불가

		cout << "나는 누구의 소유도 아닙니다." << endl;
	}
};

// static 멤버 변수 초기화 구문.
//// 전역변수처럼 사용됨. 객체안에 있는 것이 아님.
// static 멤버 변수는 객체 생성 없이도 사용가능.
int cTest::m_iValue = 0;

void main()
{
	//cTest obj1(100);
	//cTest obj2(200);
	//cTest obj3(300);
	//
	//obj1.Func();
	//obj2.Func();
	//obj3.Func();

	// ##2. static 멤버 함수
	// 객체 생성 없이도 호출 할 수 있다.
	// 앞으로 c++에서 전역함수를 다룰 때 static 멤버 함수로 다룬다.
	cTest::StaticFunc();

	return;
}