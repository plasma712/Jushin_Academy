#include <iostream>

using namespace std;

class cGameObject
{
public:
	virtual ~cGameObject()
	{
		cout << "�θ� �Ҹ���" << endl;
	}
};

class cPlayer : public cGameObject
{
public:
	virtual ~cPlayer() // �������̵��̶�� �θ� ���� ����.( �θ� �Ҹ��ڶ� �ڽ� �Ҹ����� �̸��� �ٸ�.)
	{
		cout << "�ڽ� �Ҹ���" << endl;
	}
};

class cMonster : public cGameObject
{

};

void main()
{
	cGameObject* pPlayer = new cPlayer;
	
	// �Ҹ��� ȣ�⵵ �������ε��� �ʿ��ϴ�. -> ���� �Ҹ���
	delete pPlayer;

}