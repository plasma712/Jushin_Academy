#pragma once
#include "cGameObject.h"
class cPlayer :
	public cGameObject
{
public:
	cPlayer();
	virtual ~cPlayer();

	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;

public:
	//list<LINE*> m_LineList; // 백그라운드에서 불러옴. 라인충돌을 위해서
	FRAME		m_Frame;



private:
	void KeyInput();
	void IsFrame();
	void Animation();
	void OffSet();

	bool GroundCheck();
	void Jump();

	STATEPLAYER		m_PreState;
	STATEPLAYER		m_CurState;

	bool		bFirstStart;
	bool		m_bIsJump;
	float		m_fGroundY;
	float		m_fJumpForce;
	float		m_fJumpAcc;

	bool        bRight; // true는 RIGHT방향 false는 LEFT방향
	float       m_fAnimationWorking;
	bool		m_bAniISJump;
	float		m_OffSetSpeed;
//////////////////////////////////////////////

	cGameObject* Create_IDLE_Bullet();
	cGameObject* Create_Middle_Charge_Bullet(bool _bRight);
	cGameObject* Create_Full_Charge_Bullet(bool _bRight);

	//OBJLIST*   m_BulletLst;

///////////////////////////////////////////////
#pragma region 애니메이션함수


	void vIDLE_GAMESTART_RIGHT();
	void vIDLE_RIGHT();
	void vWALK_RIGHT();
	void vIDLE_ATTACK_RIGHT();
	void vREINFORCE_ATTACK_RIGHT();
	void vWALK_ATTACK_RIGHT();
	void vDASH_RIGHT();
	void vDASH_ATTACK_RIGHT();
	void vDASH_STOP_RIGHT();
	void vJUMP_RIGHT();
	void vJUMP_ATTACK_RIGHT();
	/// 추가해야함 

///////////////////////////////////////////////
	void vIDLE_GAMESTART_LEFT();
	void vIDLE_LEFT();
	void vWALK_LEFT();
	void vIDLE_ATTACK_LEFT();
	void vREINFORCE_ATTACK_LEFT();
	void vWALK_ATTACK_LEFT();
	void vDASH_LEFT();
	void vDASH_ATTACK_LEFT();
	void vDASH_STOP_LEFT();
	void vJUMP_LEFT();
	void vJUMP_ATTACK_LEFT();
	/// 추가해야함 
#pragma endregion


};

