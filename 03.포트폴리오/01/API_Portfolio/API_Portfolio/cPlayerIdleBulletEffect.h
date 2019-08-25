#pragma once
#include "GameObject.h"
class cPlayerIdleBulletEffect :
	public CGameObject
{
public:
	bool bDeadCheck;
	void Dead();
	///////////////////////////////////////////////////
	DWORD dwCurTime;
	DWORD dwOldTime;
	DWORD dwFrameSpeed;
	bool  m_Count;
	float fx;
public:
	cPlayerIdleBulletEffect();
	virtual ~cPlayerIdleBulletEffect();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

	void fxPlus();
};

