#pragma once
// #include"cMonster.h"

// ���漱��
// �ܺο� �ش� Ŭ������ �������� �˸��� ����
// ����� ��ȣ���� ����.
class cMonster;

class cPlayer
{
private:
	// ���漱������ �ش� Ŭ������ �޸� ũ�⸦ �� �� ����.
	// ���� �����ͷ� �����ؾ���.
	cMonster* Monster;

public:
	cPlayer();
	~cPlayer();
public:
	void Func();
};

