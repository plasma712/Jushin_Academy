#pragma once
#include "GameObject.h"
class CPlayer :
	public CGameObject
{
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
	void KeyInput();

private:		
	float		m_fPosinX; // ������ ���� X
	float		m_fPosinY; // ������ ���� Y
	float		m_fPosinLength; // ���� ����
	
};

