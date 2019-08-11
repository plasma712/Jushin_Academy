#pragma once
#include "cGameObject.h"
class cBullet :
	public cGameObject
{

public:
	cBullet();
	virtual ~cBullet();

	// cGameObject을(를) 통해 상속됨
	virtual void Init() override;
	virtual int Update() override;
	virtual void Draw(HDC hdc) override;
	virtual void Release() override;

public:

	void Move();

	bool bRight;

	void SetbRight(bool _bRight);
	void SetState(STATEBULLET _m_CurState);
	void SpeedCheck();

//////////////////////////////////////

	FRAME		m_Frame;
	void IsFrame();
	void Animation();
	STATEBULLET		m_PreState;
	STATEBULLET		m_CurState;

	float fSizeX;
	float fSizeY;


/////////////////////////////////////

	void vIDLE_RIGHT();
	void vMIDDLE_RIGHT();
	void vFULL_RIGHT();
	void vIDLE_LEFT();
	void vMIDDLE_LEFT();
	void vFULL_LEFT();

};

