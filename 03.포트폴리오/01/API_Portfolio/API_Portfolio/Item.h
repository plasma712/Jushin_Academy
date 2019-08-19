#pragma once
#include "GameObject.h"
class CItem :
	public CGameObject
{
public:
	CItem();
	virtual ~CItem();

	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int	 Update() override;
	virtual void Render(HDC hDC) override;
	virtual void Release() override;

private:
	int m_iFrame;
	int m_ItemNumber;

public:
	void SetItemFrame(int _m_iFrame);
	void ItemResult();
	virtual void SetDamaged();

private:
	void IsOutRange();
	void IsMoving();
};

