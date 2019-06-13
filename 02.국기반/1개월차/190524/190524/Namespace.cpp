#include <iostream>

using namespace std;

// namespace 목적 : 중복된 이름 충돌 방지. C++부터 등장한 문법이다.

namespace Player
{
	void Render()
	{
		cout << "플레이어 렌더링" << endl;
	}
}

namespace Monster
{
	void Render()
	{
		cout << "몬스터 렌더링" << endl;
	}
}


void main()
{
	Player::Render();
	Monster::Render();
}