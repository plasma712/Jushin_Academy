#pragma once
#include "GameObject.h"
class CBullet;
class CPlayer :
	public CGameObject
{
public:
	CPlayer();
	virtual			~CPlayer();
	bool	   m_bReinforce;

public:
	void			SetBulletLst(OBJLIST* pBulletLst);

public:
	// CGameObject을(를) 통해 상속됨
	virtual void	Initialize() override;
	virtual int		Update() override;
	virtual void	Render(HDC hDC) override;

private:
	virtual void	Release() override;

private:
	CGameObject*	CreateBullet();
	CGameObject*	CreateMiddleChargeBullet();
	CGameObject*	CreateFullChargeBullet();
	void			CreateBomb();
	void			KeyInput();
	void			IsOutRange();
	void			OffSet();

private:
	int				m_bulletCount;
	OBJLIST*		m_pBulletLst;
	CKeyManager*	m_pKeyMgr;
	bool			bInputable;
	HDC				m_AppearPlayerImage;
	AniData			m_AppearPlayerData;

	float			m_ApperSpeed;

	int            GetEnergy();


	void		   IsFrame();
	void		   IsAniMation();


	STATEPLAYER		m_PreState;
	STATEPLAYER		m_CurState;

	bool       m_bAnimationWorking;

	bool       m_Direction;		//True는 Right방향
	float	   m_OffSetSpeed;

	bool       m_DashCheck;
	bool	   m_DashSpeedUp;

	float	   BulletNumber;

	DWORD	   m_Reinforce_dwOldTime;
	DWORD	   m_Reinforce_dwCurTime;
	DWORD      m_Reinforce_CheckTime;
	float      m_Reinforce_Time;
public:
	bool IsGround();
	void IsJump();
//////////////////////////////////////////////////
	list<LINE*> m_LineList; // 라인에디터를 통해서 호출.
	float		m_fGroundY;

	bool		m_bIsJump;
	float		m_fJumpForce;
	float		m_fJumpAcc;

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