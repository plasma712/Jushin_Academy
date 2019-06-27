#include <iostream>

using namespace std;

// ##1. Has a 관계

// Has - a 관계 상속

class cSword
{
private:

public:
	void Using()
	{
		cout << "검을 휘두른다." << endl;
	}

};

class cAxe
{
public:
	void Using()
	{
		cout << "뚝배기를 찍는다" << endl;
	}
};

// Has - a 관계 상속의 문제점
// 1. 플레이어는 무조건 검을 들고 있어야 한다. (종속적이다.)
// 2. 다중상속으로 변질된다.
// class  cPlayer : public cSword , public cAxe	// 다중 상속
// {												// 모호성
// 												// 다이아몬드 꼴이 나온다
// private:
// 
// public:
// };

// Has - a는 상속이 아닌 포함관계로 구성하는게 옳다.
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