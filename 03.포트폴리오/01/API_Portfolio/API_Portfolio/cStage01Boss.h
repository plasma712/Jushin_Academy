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
	void vBossFSM();

	Stage01Boss		 m_PreState;
	Stage01Boss		 m_CurState;

	bool		m_bAnimationWorking;

	float		m_fGroundY;
	bool		m_bIsJump;
	float		m_fJumpForce;
	float		m_fJumpAcc;

	bool		m_Direction;

	bool		IsGround();
	void		IsJump();

	void		BossRect();


	CGameObject* CreatePattern01Bullet();
	OBJLIST*		m_pBulletLst;
	void SetBulletLst(OBJLIST* pBulletLst);

#pragma region 애니메이션함수

	void vSTART_RIGHT();
	void vSTART_LEFT();
	void vIDLE_RIGHT();
	void vIDLE_LEFT();
	void vIDLE_WALK_RIGHT();
	void vIDLE_WALK_LEFT();
	void vATTACK01_RIGHT();
	void vATTACK01_LEFT();

#pragma endregion
};

