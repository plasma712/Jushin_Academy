#include <iostream>

using namespace std;

// ##1. Has a ����

// Has - a ���� ���

class cSword
{
private:

public:
	void Using()
	{
		cout << "���� �ֵθ���." << endl;
	}

};

class cAxe
{
public:
	void Using()
	{
		cout << "�ҹ�⸦ ��´�" << endl;
	}
};

// Has - a ���� ����� ������
// 1. �÷��̾�� ������ ���� ��� �־�� �Ѵ�. (�������̴�.)
// 2. ���߻������ �����ȴ�.
// class  cPlayer : public cSword , public cAxe	// ���� ���
// {												// ��ȣ��
// 												// ���̾Ƹ�� ���� ���´�
// private:
// 
// public:
// };

// Has - a�� ����� �ƴ� ���԰���� �����ϴ°� �Ǵ�.
class cPlayer
{
private:
	cSword m_sword;
	cAxe m_axe;
public:
	void Using()
	{
		m_sword.Using();
		m_axe.Using();
	}
};


void main()
{
	cPlayer player;
	player.Using();
	return;
}