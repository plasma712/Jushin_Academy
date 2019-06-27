#pragma once
#include "cGameObject.h"


class cMonster :public cGameObject
{
public:
	cMonster();
	cMonster(
		int  _InherentNumber,
		const char* _cName,
		int  _iAtk,
		int  _iDef,
		int  _iHp,
		int  _iMaxHp,
		int  _iLv,
		int  _iExp,
		int  _iGold
	);
	~cMonster();

public: // �⺻ ����
	virtual void Init() override;
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Release() override;
public:
	//�迭���� �����ڸ� ���� �ʱ�ȭ �Ұ���?

	void SetConstructor(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold);
	
};

