#pragma once
#include "Scene.h"
class CLogoScene :
	public CScene
{
public:
	CLogoScene();
	~CLogoScene();

public:
	// CScene��(��) ���� ��ӵ�
	virtual void	Initialize();
	virtual void	Update() override;
	virtual void	Render() override;

private:
	virtual void	Release() override;

	// CScene��(��) ���� ��ӵ�
	virtual void LoadMonster() override;

	CKeyManager*	m_pKeyMgr;

	DWORD	   dwOldTime;
	DWORD	   dwCurTime;


	bool bKeyPressCheck;
	int iKeyCheck;

	int PressEnterTime;

	void vPressEnterTime();
	bool Check;
};

