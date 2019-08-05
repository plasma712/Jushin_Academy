#pragma once
#include "GameObject.h"

class CUIMgr :public CGameObject
{
public:
	CUIMgr();
	~CUIMgr();


	// CGameObject��(��) ���� ��ӵ�
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
	int PlayerLife	;	//= 2; // 2�� �Ѿ�� �ȵ�.
	int EnergyBarLV ;	//= 1; // 5���Ѿ�ȵ�(0�� �ȵ�)
	int PlayerBoom  ;	//= 3; // 6���Ѿ�ȵ� 
	int EnergyBarGague;	//	
	int Score;			// ���ھ�
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

