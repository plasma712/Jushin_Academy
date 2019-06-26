#pragma once

// #include"cPlayer.h"
// 전방선언
class cPlayer;

class cMonster
{
private:
	cPlayer* player;

public:
	cMonster();
	~cMonster();
public:
	void Func();
};

