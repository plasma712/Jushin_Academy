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
	// ##1. �������̵��� ������
	// cGameObject Gameobject;
	// cPlayer		PlayerObject;
	// cWarrior    Warrior;

	// �������ε� : ������ �Լ��� ȣ�������� ������ ������ �����ȴ�.
	// �� �� ��ü Ÿ������ ȣ�� �Լ��� �����ȴ�.
	// Gameobject.Print();
	// PlayerObject.Print();
	// Warrior.Print();


	// ##2. �������̵��� ��ü������
	//cPlayer		PlayerObject;
	cWarrior	WarriorObject;

	cGameObject* ptr1 = &WarriorObject;
	cPlayer*	 ptr2 = &WarriorObject;
	cWarrior*	 ptr3 = &WarriorObject;

	// ���� ���ε� ������ �������� ����� �̷������ ���� ����.
	// �� �� �����Ϸ��� �ܼ��� ������ Ÿ��(��üŸ��)���� �Ǵ��ع�����.
	// ���� ���ε����� �ٲ���Ѵ�. -> virtual Ű���� ����.
	ptr1->Print();
	ptr2->Print();
	ptr3->Print();

	cout << sizeof(cGameObject) << endl;
	cout << sizeof(cPlayer) << endl;
	cout << sizeof(cWarrior) << endl;
}