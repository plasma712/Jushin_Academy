#pragma once
#include "Monster.h"
class cRolling :
	public CMonster
{
public:
	cRolling();
	virtual ~cRolling();


public:
	virtual void Initialize() override;
	virtual int  Update() override;
	virtual void Render(HDC hDC) override;

public:
	void IsFrame();
	void IsAniMation();
	void vRollingFSM();

	ROLLING		 m_PreState;
	ROLLING		 m_CurState;

	bool		m_bAnimationWorking;

	float		m_fGroundY;
	bool		m_bIsJump;
	float		m_fJumpForce;
	float		m_fJumpAcc;

	bool		IsGround();
	void		IsJump();

	void		RollingRect();



#pragma region 애니메이션함수

	void vIDLE_RIGHT();
	void vIDLE_LEFT();
	void vIDLE_ROLLING_ATTACK_RIGHT();
	void vIDLE_ROLLING_ATTACK_LEFT();
	void vIDLE_ROLLING_ATTACK_RIGHT_STOP();
	void vIDLE_ROLLING_ATTACK_LEFT_STOP();

	void vLEFT_RIGHT();
	void vRIGHT_LEFT();

#pragma endregion


};

