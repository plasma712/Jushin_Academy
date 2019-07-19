#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual ~CGameObject();

public:
	void SetPos(float x, float y);
	INFO GetPos();
	// virtual
public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC hDC) = 0;

protected:
	virtual void Release() = 0;

	// 
protected:
	void UpdateRect();

protected:
	INFO	m_tInfo;
	RECT	m_tRect;

	float	m_fSpeed;
	bool	m_bIsDead;
};

