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
	m_pUIMgr_TopStatus = CMainGame::GetInstance()->GetResource()->Get(L"UIStatus_Top");
	SetPlayerLife(2);

	m_pUIMgr_TopStageNumber = CMainGame::GetInstance()->GetResource()->Get(L"UI_Top_StageNumber");
	
	m_pUIMgr_Top_UIScore = CMainGame::GetInstance()->GetResource()->Get(L"UIScore_Top");
	SetScroe(0);


	m_pUIMgr_BottomSubEnergyBar = CMainGame::GetInstance()->GetResource()->Get(L"UISubEnergyBar");
	SetEnergyBarLV(0);

	m_pUIMgr_BottomBoom = CMainGame::GetInstance()->GetResource()->Get(L"UIBoom");
	SetPlayerBoom(3);

	m_pUIMgr_BottomSubEnergyBarGague = CMainGame::GetInstance()->GetResource()->Get(L"UISubEnergyBarGauge");
	//SetEnergyBarGague(50);

}


int CUIMgr::Update()
{
	return NO_EVENT;
}

void CUIMgr::Render(HDC hDC)
{
	// Top

	TransparentBlt(
		hDC,
		30,	// Rectangle�� ���� Left��
		10,	// Rectangle�� ���� Bottom��
		74, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		98, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_TopStatus, // �̹��� �ҷ�����
		(GetPlayerLife()) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		74,	// ���������� X
		98,	// ���������� Y
		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);
	TransparentBlt(
		hDC,
		350,	// Rectangle�� ���� Left��
		10,	// Rectangle�� ���� Bottom��
		68, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		48, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_TopStageNumber, // �̹��� �ҷ�����
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		68,	// ���������� X
		48,	// ���������� Y
		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);
	for (int Digits = 1; Digits < 7; Digits++)
	{
		TransparentBlt(
			hDC,
			300-(Digits*25),// Rectangle�� ���� Left��
			20,	// Rectangle�� ���� Bottom��
			25, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
			25, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
			m_pUIMgr_Top_UIScore, // �̹��� �ҷ�����
			0,  // m_iAniCount*m_AniData.iWarpWidth,
			(GetScoreDigits(GetScore(),	Digits)) * 47,  // m_iAniCount*m_AniData.iWarpHeight
			47,	// ���������� X
			47,	// ���������� Y
			RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
		);
	}
	// Bottom

	TransparentBlt(
		hDC,
		30,	// Rectangle�� ���� Left��
		840,	// Rectangle�� ���� Bottom��
		304, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		52, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_BottomSubEnergyBar, // �̹��� �ҷ�����
		GetEnergyBarLV() * 304,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		304,	// ���������� X
		52,	// ���������� Y
		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);
	TransparentBlt(
		hDC,
		335,	// Rectangle�� ���� Left��
		840,	// Rectangle�� ���� Bottom��
		64, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		64, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_BottomBoom, // �̹��� �ҷ�����
		GetPlayerBoom() * 64,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		64,	// ���������� X
		64,	// ���������� Y
		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);
	TransparentBlt(
		hDC,
		50,	// Rectangle�� ���� Left��
		873, // Rectangle�� ���� Bottom��
		GetEnergyBarGague()*2.76,//276, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		10, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_pUIMgr_BottomSubEnergyBarGague, // �̹��� �ҷ�����
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		276,// ���������� X
		10,	// ���������� Y
		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	);


	//list<CGameObject*>::iterator iter_begin = m_pUIMgrLst.begin(); // auto begin_iter = l.begin()�� ����
	//list<CGameObject*>::iterator iter_end = m_pUIMgrLst.end(); // auto end_iter = l.end()�� ����
	//for (; iter_begin != iter_end; ++iter_end)
	//{
	//	TransparentBlt(
	//		hDC,
	//		30,	// Rectangle�� ���� Left��
	//		10,	// Rectangle�� ���� Right��
	//		74, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
	//		98, // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
	//		(*iter_begin)->GetImage(), //m_pUIMgr_TopStatus->GetImage(), // �̹��� �ҷ�����
	//		(PlayerLife) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
	//		0,
	//		74,	// ���������� X
	//		98,	// ���������� Y
	//		RGB(255, 255, 255) // �������̶� ���� �������. ����Ʈ������ ��
	//	);
	//}


	//BitBlt(hDC, 100, 0, 74, 98, m_pResourceMgr->Get(L"UIStatus_Top"), 0, 0, SRCCOPY);
	//    (hDC,����������X,����������Y ,����������X ,���������� y)
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


