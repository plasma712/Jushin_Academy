#pragma once
// #include"cMonster.h"

// 전방선언
// 외부에 해당 클래스가 존재함을 알리는 문법
// 헤더의 상호참조 방지.
class cMonster;

class cPlayer
{
private:
	// 전방선언만으로 해당 클래스의 메모리 크기를 알 수 없다.
	// 따라서 포인터로 선언해야함.
	cMonster* Monster;

public:
	cPlayer();
	~cPlayer();
public:
	void Func();
};

