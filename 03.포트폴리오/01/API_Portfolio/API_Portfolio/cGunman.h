#pragma once
#include "Monster.h"
class cGunman :
	public CMonster
{
public:
	cGunman();
	virtual ~cGunman();

public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;

public:
	void IsFrame();
	void IsAniMation();
	void vGunManFSM();

	GUNMAN		 m_PreState;
	GUNMAN		 m_CurState;

	bool		m_bAnimationWorking;

	float		m_fGroundY;
	bool		m_bIsJump;
	float		m_fJumpForce;
	float		m_fJumpAcc;

	bool		m_Direction;

	bool		IsGround();
	void		IsJump();

	void		GunManRect();


	CGameObject* CreateGunManBullet();
	OBJLIST*		m_pBulletLst;
	void SetBulletLst(OBJLIST* pBulletLst);


	DWORD		dwPatternCurTime;
	DWORD		dwPatternOldTime;
	DWORD		dwPatternFrameSpeed;

	void		vPatternRand();
	//int			FSMNumber;
	void	    vIsMove();
	int			iRandom;
	//int iRandom = rand() % 100;

	

#pragma region 애니메이션함수

	void vIDLE_RIGHT();
	void vIDLE_LEFT();
	void vIDLE_WALK_RIGHT();
	void vIDLE_WALK_LEFT();
	void vATTACK_RIGHT();
	void vATTACK_LEFT();

#pragma endregion


};

