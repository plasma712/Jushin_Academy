#include <iostream>

using namespace std;

class cGameObject
{
public:
	virtual void Print() // �����Լ� �����͸� ���� ���̺��� �����Ϳ����� ����.
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

// // ���� ���ε��� ����ؾ��ϴ� ���� : ������ �ش�ȭ
// void Damaged(cGameObject* To, cGameObject* From);
// 
// // ���� ���ε��� �������� �� �������� ������.
// void DamagedFromMonster(cPlayer* To, cMonster* From);
// void DamagedFromMonster(cMonster* To, cPlayer* Form);
void main()
{
	// ##1. �����Լ��� ��ü������
	cWarrior	WarriorObject;

	cGameObject* ptr1 = &WarriorObject;
	cPlayer*	 ptr2 = &WarriorObject;
	cWarrior*	 ptr3 = &WarriorObject;

	// ���� Print�Լ��� �����Լ���. ������ �Լ��� ȣ�� �� ���� ��Ÿ�� �� �����ȴ�. -> �������ε�
	ptr1->Print();
	ptr2->Print();
	ptr3->Print();


	// ##2. virtual Ű���尡 �ϳ��� �����ϴ� Ŭ������ �������� ��
	// �����Ϸ��� �����Լ� ������(vfptr)�� �����Լ� ���̺�(vftable)�� �����Ѵ�.
	cout << sizeof(cGameObject) << endl;
	cout << sizeof(cPlayer) << endl;
	cout << sizeof(cWarrior) << endl;

}