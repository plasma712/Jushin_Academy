#include <iostream>

using namespace std;

// ##1. *** 클래스의 4대 속성
// 1. 은닉화 (hidding Information)
// 2. 캡슐화 (encapsulation)
// 3. 상속성 (inheritance)
//	  자식클래스들의 공통된 요소들을 부모 클래스가 물려준다. 코드 재사용 극대화.
//	  부모클래스는 자식클래스들의 추상적인 존재가 된다.

// 4. 다형성 (polymorphism)
//	  여러 객체가 하나의 메시지를 통해 각기 다른 형태를 취하는 것.
//    프로그래밍 유연성 극대화

// ##2. 은닉화 (hidding Information)
// 멤버 제어를 private으로 외부에서 접근을 막는다. 데이터 보호.

class cPlayer
{
public :
	int GetAttack()	// Get함수. (은닉된 데이터 읽기 전용)
	{
		return m_iAtt;
	}

public:
	void SetDamaged(int _iAtt)	//Set함수. (은닉된 데이터 쓰기허용)
	{
		m_iHp -= _iAtt;
	}

private:
	int m_iAtt;
	int m_iHp;
	int m_iMaxHp;

};

void main()
{

	system("pause");
	return;
}