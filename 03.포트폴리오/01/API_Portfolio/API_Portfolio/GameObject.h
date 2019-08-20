#pragma once
class CGameObject
{
public:
	CGameObject();
	virtual	~CGameObject();

public:
	const INFO&		GetInfo() const;
	const RECT&		GetRect() const;
	const HDC&		GetImage() const;
	// virtual
public:
	virtual void	Initialize() = 0;
	virtual int		Update() = 0;
	virtual void	Render(HDC hDC) = 0;

protected:
	virtual void	Release() = 0;

public:
	void			SetPos(float x, float y);
	void			SetDead(bool bIsDead);

	void			SetDirection(float dir);
	void			SetSpeed(float speed);
	void			SetSprite(wstring sprite);
	void			SetRect();
	void			SetAniCount(int _count);
	virtual void	SetDamaged();
	int				GetAniCount();
	AniData			GetAniData();
	void		    SetBulletDirection(bool _bDirection);
	void			SetAniFrameSpeed(DWORD _FrameSpeed);
	void			vSetBulletNumber(int _BulletNumber);
	int				BulletNumber;

	

protected:
	void			UpdateRect();

protected:
	INFO			m_tInfo;
	RECT			m_tRect;
	float			m_fDirection;
	float			m_fSpeed;
	int				m_iHP;
	HDC				m_Image;
	bool			m_bIsDead;

	int				m_iCount;
	AniData			m_AniData;
	int				m_iAniCount;

	bool			m_bDirection;

};
