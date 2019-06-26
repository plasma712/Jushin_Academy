#include <iostream>

using namespace std;

// ##1. 클래스 생성자
// 객체 생성 시 무조건 자동 호출되는 함수의 일종.
// 사용자가 생성자를 명시하지 않으면 컴파일러가 디폴트 생성자를 만들어준다.
// 클래스 멤버 초기화 시 유용하다.
 
// *** 객체의 생성 과정
// 메모리 할당 -> 생성자 호출.

class cTest
{
private:
	int m_Value;
public:
	// 디폴트 생성자의 형태
	cTest()
	{
		m_Value = 0;
		cout << "디폴트 생성자 입니다." << endl;
	}

	// 인자있는 생성자.
	// 사용자가 생성자를 명시하는 순간 컴파일러는 디폴트 생성자를 만들어주지 않는다.
	cTest(int n)
	{
		cout << "m_Value를 ("<< n << ")값으로 초기화하는 인자있는 생성자 입니다." << endl;
		m_Value = n;
	}
	

};


void main()
{
	// // ##1. 정적할당 시 생성자 호출
	// cTest obj; // 인자없는 (디폴트) 생성자 호출.
	// cTest obj2(200);

	// ##2. 동적할당 시 생성자 호출
	cTest* ptr1 = nullptr;
	ptr1 = new cTest; // 인자없는(디폴트) 생성자 호출.

	cTest* ptr2 = nullptr;
	ptr2 = new cTest(200);	// 인자있는 생성자 호출.

	cTest* ptr3 = (cTest*)malloc(sizeof(cTest));

	system("pause");
	return;
}