#include <iostream>

using namespace std;

class cGameObject
{
public:
	virtual void Print() // 가상함수 데이터를 만든 테이블은 데이터영역에 들어간다.
	{
		cout << "Game Object" << endl;
	}
};

class cPlayer : public cGameObject
{
public:
	virtual void Print() override
	{
		cout << "Player Object" << endl;
	}

};

class cWarrior : public cPlayer
{
public:
	virtual void Print() override
	{
		cout << "Warrior Object" << endl;
	}
};

class cMonster : public cGameObject
{

};

// // 동적 바인딩을 사용해야하는 이유 : 다형성 극대화
// void Damaged(cGameObject* To, cGameObject* From);
// 
// // 정적 바인딩을 고집했을 때 유연성이 떨어짐.
// void DamagedFromMonster(cPlayer* To, cMonster* From);
// void DamagedFromMonster(cMonster* To, cPlayer* Form);
void main()
{
	// ##1. 가상함수와 객체포인터
	cWarrior	WarriorObject;

	cGameObject* ptr1 = &WarriorObject;
	cPlayer*	 ptr2 = &WarriorObject;
	cWarrior*	 ptr3 = &WarriorObject;

	// 이제 Print함수는 가상함수다. 누구의 함수를 호출 할 지는 런타임 때 결정된다. -> 동적바인딩
	ptr1->Print();
	ptr2->Print();
	ptr3->Print();


	// ##2. virtual 키워드가 하나라도 존재하는 클래스를 컴파일할 때
	// 컴파일러는 가상함수 포인터(vfptr)와 가상함수 테이블(vftable)을 생성한다.
	cout << sizeof(cGameObject) << endl;
	cout << sizeof(cPlayer) << endl;
	cout << sizeof(cWarrior) << endl;

}