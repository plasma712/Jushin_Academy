#pragma once
#include "GameObject.h"

class CPlayer :
	public CGameObject
{
public:
	enum STATE { IDLE, WALK, ATTACK, HIT, DEAD };

public:
	CPlayer();
	virtual ~CPlayer();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	CGameObject* CreateBullet();
	CGameObject* CreateBullet(BULLET_DIRECTION eDir);
	CGameObject* CreateShield();
	CGameObject* CreateGuideBullet();

private:
	void KeyInput();
	bool IsGround();
	void IsJump();
	void IsFrame();
	void IsChange();
	void IsOffset();
private:		
	FRAME		m_tFrame;

	float		m_fPosinX; // ������ ���� X
	float		m_fPosinY; // ������ ���� Y
	float		m_fPosinLength; // ���� ����

	bool		m_bIsJump;
	float		m_fGroundY;

	float		m_fJumpForce;	// ���� ��(v)
	float		m_fJumpAcc;		// ���� ���ӵ�(t)	
	
	STATE		m_ePreState;
	STATE		m_eCurState;
};

