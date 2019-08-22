#pragma once
#include "Monster.h"
class cStage01Boss :
	public CMonster
{
public:
	cStage01Boss();
	virtual ~cStage01Boss();
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

	bool		IsGround();
	void		IsJump();

	void		GunManRect();

};

