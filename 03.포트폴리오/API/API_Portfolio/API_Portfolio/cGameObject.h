#pragma once
class cGameObject
{
protected:
	INFO m_Info;
	RECT m_Rect;
	
	float m_fSpeed;
	float m_fHp;
	float m_fAtk;

	bool m_bImmortal;
	bool m_bDead;

	wstring m_wstrObjectKey;

	////////////////
	bool m_WallCrush;

public:
	cGameObject();
	virtual ~cGameObject();

public:

	virtual void Init() = 0;
	virtual int Update() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void Release() = 0;

public:	
	void UpdateRect(); // ªÁ¿Ã¡Ó

	void SetINFO(float _fX, float _fY);
	INFO GetINFO();
	RECT GetRECT();

	void SetImmortal(bool _m_bImmortal);
	bool GetImmortal();

	void SetDead(bool _m_bImmortal, bool _m_bDead);
	bool GetDead();

	void SetPos(float _fX, float _fY);

public:

	float GetHp();
	void  SetHpDecrease(float _fAtk);
	
	float GetAttack();
	
	bool GetWallCrush();

};

