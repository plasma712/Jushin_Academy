#include <iostream>

using namespace std;

// namespace ���� : �ߺ��� �̸� �浹 ����. C++���� ������ �����̴�.

namespace Player
{
	void Render()
	{
		cout << "�÷��̾� ������" << endl;
	}
}

namespace Monster
{
	void Render()
	{
		cout << "���� ������" << endl;
	}
}


void main()
{
	Player::Render();
	Monster::Render();
}