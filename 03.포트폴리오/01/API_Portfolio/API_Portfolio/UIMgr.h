#pragma once
#include "GameObject.h"

class CUIMgr :public CGameObject
{
public:
	CUIMgr();
	~CUIMgr();


	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;

	virtual int Update() override;

	virtual void Render(HDC hDC) override;

	virtual void Release() override;

private:
	int m_iFrame=3;

	HDC	m_pUIMgr_TopStatus;
	HDC	m_pUIMgr_TopStageNumber;
	HDC	m_pUIMgr_BottomSubEnergyBar;
	HDC	m_pUIMgr_BottomBoom;
	HDC	m_pUIMgr_BottomSubEnergyBarGague;

	HDC	m_pUIMgr_Top_UIScore;

private:
	CResourceManager*	m_pResourceMgr;
	int PlayerLife	;	//= 2; // 2를 넘어서는 안됨.
	int EnergyBarLV ;	//= 1; // 5를넘어선안됨(0도 안됨)
	int PlayerBoom  ;	//= 3; // 6을넘어선안됨 
	int EnergyBarGague;	//	
	int Score;			// 스코어
	//list<CGameObject*> m_pUIMgrLst;

public:
	void SetPlayerLife(int _PlayerLife);
	void SetEnergyBarLV(int _EnergyBarLV);
	void SetPlayerBoom(int _PlayerBoom);
	void SetEnergyBarGague(float _EnergyBarGague);
	void SetScroe(int _Score);

	int GetPlayerLife();
	int GetEnergyBarLV();
	int GetPlayerBoom();
	int GetEnergyBarGague();
	int GetScore();
	int GetScoreDigits(int _Score,int _Digits);
};

