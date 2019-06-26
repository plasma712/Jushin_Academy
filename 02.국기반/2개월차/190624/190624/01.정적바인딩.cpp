#include <iostream>

using namespace std;

class cGameObject
{
public:
	void Print()
	{
		cout << "Game Object" << endl;
	}
};

class cPlayer : public cGameObject
{
public:
	void Print()
	{
		cout << "Player Object" << endl;
	}
};

class cWarrior : public cPlayer
{
public:
	void Print()
	{
		cout << "Warrior Object" << endl;
	}
};

void main()
{
	// ##1. 오버라이딩과 다형성
	// cGameObject Gameobject;
	// cPlayer		PlayerObject;
	// cWarrior    Warrior;

	// 정적바인딩 : 누구의 함수를 호출할지가 컴파일 시점에 결정된다.
	// 이 때 객체 타입으로 호출 함수가 결정된다.
	// Gameobject.Print();
	// PlayerObject.Print();
	// Warrior.Print();


	// ##2. 오버라이딩과 객체포인터
	//cPlayer		PlayerObject;
	cWarrior	WarriorObject;

	cGameObject* ptr1 = &WarriorObject;
	cPlayer*	 ptr2 = &WarriorObject;
	cWarrior*	 ptr3 = &WarriorObject;

	// 정적 바인딩 때문에 다형성이 제대로 이루어지지 있지 않음.
	// 이 때 컴파일러는 단순히 포인터 타입(객체타입)으로 판단해버린다.
	// 동적 바인딩으로 바꿔야한다. -> virtual 키워드 역할.
	ptr1->Print();
	ptr2->Print();
	ptr3->Print();

	cout << sizeof(cGameObject) << endl;
	cout << sizeof(cPlayer) << endl;
	cout << sizeof(cWarrior) << endl;
}