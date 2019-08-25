#pragma once
class cGunManBomb: public CGameObject
{
public:
	cGunManBomb();
	cGunManBomb(float x, float y, bool _Direction);
	virtual~cGunManBomb();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	void IsMoving();
	void IsOutRange();

private:
	int m_iFrame;

	void vFirstPoint();

	int sx, sy;
	bool Monster_Direction;
	double t = -10;


};

