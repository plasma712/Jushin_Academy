#include <iostream>

using namespace std;

namespace Player
{
	void Render();
}
namespace Monster
{
	void Render();
}


void Player::Render()
{
	cout << "�÷��̾�" << endl;
}

void Monster::Render()
{
	cout << "����" << endl;
}

void main()
{
	Player::Render();
	Monster::Render();

	return;
}