#include <iostream>

using namespace std;

// ##1. 클래스 소멸자
// 객체 소멸 시 소멸자가 호출된다.
// 사용자가 소멸자를 명시하지 않으면 컴파일러가 디폴트 소멸자를 만들어준다.

// *** 객체 소멸 과정
// 소멸자 호출 -> 메모리 반납.


class cTest
{
private:
	int* m_ptr;
public:
	cTest()
	{
		//m_ptr=
	}

	// 소멸자의 형태
	~cTest()
	{
		// 현재 클래스의 멤버 해제 시 소멸자는 유용하다.
		cout << "소멸자 입니다." << endl;
	}
};


void main()
{
	// ##2. 정적할당 시
	// cTest obj;

	// cout << "프로세스 진행중.." << endl;
	// cout << "프로세스 진행중.." << endl;
	// cout << "프로세스 진행중.." << endl;
	// ##3. 동적할당 시

	cTest* ptr = new cTest;

	cout << "프로세스 진행중.." << endl;
	cout << "프로세스 진행중.." << endl;

	delete ptr;
	cout << "프로세스 진행중.." << endl;


	


	system("pause");
	return;
}