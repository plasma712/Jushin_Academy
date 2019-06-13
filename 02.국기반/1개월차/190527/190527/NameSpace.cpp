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
	cout << "플레이어" << endl;
}

void Monster::Render()
{
	cout << "몬스터" << endl;
}

void main()
{
	Player::Render();
	Monster::Render();

	return;
}