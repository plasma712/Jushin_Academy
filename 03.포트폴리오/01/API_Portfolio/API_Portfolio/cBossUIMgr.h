#pragma once
#include "GameObject.h"
class cBossUIMgr :
	public CGameObject
{
public:
	cBossUIMgr();
	virtual ~cBossUIMgr();

	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	int m_iFrame = 3;


	HDC		m_pUIMgr_BossHpFrame;
	HDC		m_pUIMgr_BossCurrentHp;
	//HDC		m_pUIMgr_BossHpDecrease;


private:
	CResourceManager*	m_pResourceMgr;
};

