#include "stdafx.h"
#include "UIMgr.h"
#include "ResourceManager.h"


CUIMgr::CUIMgr()
{
}


CUIMgr::~CUIMgr()
{
}

void CUIMgr::Initialize()
{
	//m_pUIMgr_TopStatus = CMainGame::GetInstance()->GetResource()->Get(L"UIStatus_Top");
	//SetPlayerLife(2);

	//m_pUIMgr_TopStageNumber = CMainGame::GetInstance()->GetResource()->Get(L"UI_Top_StageNumber");
	//
	//m_pUIMgr_Top_UIScore = CMainGame::GetInstance()->GetResource()->Get(L"UIScore_Top");
	//SetScroe(0);


	//m_pUIMgr_BottomSubEnergyBar = CMainGame::GetInstance()->GetResource()->Get(L"UISubEnergyBar");
	//SetEnergyBarLV(0);

	//m_pUIMgr_BottomBoom = CMainGame::GetInstance()->GetResource()->Get(L"UIBoom");
	//SetPlayerBoom(3);

	//m_pUIMgr_BottomSubEnergyBarGague = CMainGame::GetInstance()->GetResource()->Get(L"UISubEnergyBarGauge");
	////SetEnergyBarGague(50);

	m_pUIMgr_PlayerHpFrame = CMainGame::GetInstance()->GetResource()->Get(L"HPBar");
	m_pUIMgr_PlayerHp = CMainGame::GetInstance()->GetResource()->Get(L"CurrentHP");
	m_pUIMgr_PlayerLife = CMainGame::GetInstance()->GetResource()->Get(L"life");
	m_pUIMgr_PlayerHpDecrease = CMainGame::GetInstance()->GetResource()->Get(L"DecreaseHP");

}


int CUIMgr::Update()
{
	return NO_EVENT;
}

void CUIMgr::Render(HDC hDC)
{
	// Top

	TransparentBlt
	(
		hDC,
		30,	// Rectangle�� ���� Left��
		100,	// Rectangle�� ���� Bottom��
		100, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		146, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_PlayerHpFrame, // �̹��� �ҷ�����
		(GetPlayerLife()) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		100,	// ���������� X
		146,	// ���������� Y
		RGB(200, 0, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);

	TransparentBlt
	(
		hDC,
		57,	// Rectangle�� ���� Left��
		105,										// ���⼭ ü�� �ܸ�ŭ +����
		14, 
		90,											// ���⼭ ü�� �ܸ�ŭ -����
		m_pUIMgr_PlayerHp, // �̹��� �ҷ�����
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		14,	// ���������� X
		90,	// ���������� Y
		RGB(200, 0, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);

	TransparentBlt
	(
		hDC,
		93.5,	// Rectangle�� ���� Left��
		210,	// Rectangle�� ���� Bottom��
		20, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		20, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_PlayerLife, // �̹��� �ҷ�����
		32, // ��� ���⼭ üũ 16 * ������
		0,
		16,	// ���������� X
		16,	// ���������� Y
		RGB(200, 0, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);

}

void CUIMgr::Release()
{
}

void CUIMgr::SetPlayerLife(int _PlayerLife)
{
	PlayerLife += _PlayerLife;

	if (PlayerLife < 0)
	{
		PlayerLife = 0;
	}
	else if (PlayerLife > 2)
	{
		PlayerLife = 2;
	}
}

void CUIMgr::SetEnergyBarLV(int _EnergyBarLV)
{
	EnergyBarLV += _EnergyBarLV;

	//if (EnergyBarLV <= 0)
	//{
	//	EnergyBarLV = 1;
	//}
	/*else*/ if (EnergyBarLV >= 4)
	{
		EnergyBarLV = 4;
	}
}

void CUIMgr::SetPlayerBoom(int _PlayerBoom)
{
	PlayerBoom += _PlayerBoom;

	if (PlayerBoom < 0)
	{
		PlayerBoom = 1;
	}
	else if (PlayerBoom >= 10)
	{
		PlayerBoom = 9;
	}

}

void CUIMgr::SetEnergyBarGague(float _EnergyBarGague)
{
	if (GetEnergyBarLV() > 3)
		return;

	EnergyBarGague += _EnergyBarGague;

	
	if (EnergyBarGague < 0)
	{
		EnergyBarGague = 0;
	}
	else if (EnergyBarGague >= 100)
	{
		EnergyBarGague -= 100;
		SetEnergyBarLV(1);
	}

}

void CUIMgr::SetScroe(int _Score)
{
	Score += _Score;

	if (Score >= 1000000)
	{
		Score = 999999;
	}

}

int CUIMgr::GetPlayerLife()
{
	return PlayerLife;
}

int CUIMgr::GetEnergyBarLV()
{
	return EnergyBarLV;
}

int CUIMgr::GetPlayerBoom()
{
	return PlayerBoom;
}

int CUIMgr::GetEnergyBarGague()
{
	return EnergyBarGague;
}

int CUIMgr::GetScore()
{
	return Score;
}

int CUIMgr::GetScoreDigits(int _Score, int _Digits)
{
	switch (_Digits)
	{
	case 1:
		return _Score % 10;
	case 2:
		return _Score / 10 % 10;
	case 3:
		return _Score / 100 % 10;
	case 4:
		return _Score / 1000 % 10;
	case 5:
		return _Score / 10000 % 10;
	case 6:
		return _Score / 100000;

	default:
		break;
	}
	return 0;
}


