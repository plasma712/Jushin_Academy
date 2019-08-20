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
		30,	// Rectangle로 보면 Left값
		100,	// Rectangle로 보면 Bottom값
		100, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		146, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_PlayerHpFrame, // 이미지 불러오기
		(GetPlayerLife()) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		100,	// 사진사이즈 X
		146,	// 사진사이즈 Y
		RGB(200, 0, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);

	TransparentBlt
	(
		hDC,
		57,	// Rectangle로 보면 Left값
		105,										// 여기서 체력 단만큼 +해줌
		14, 
		90,											// 여기서 체력 단만큼 -해줌
		m_pUIMgr_PlayerHp, // 이미지 불러오기
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		14,	// 사진사이즈 X
		90,	// 사진사이즈 Y
		RGB(200, 0, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);

	TransparentBlt
	(
		hDC,
		93.5,	// Rectangle로 보면 Left값
		210,	// Rectangle로 보면 Bottom값
		20, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		20, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_PlayerLife, // 이미지 불러오기
		32, // 목숨 여기서 체크 16 * 라이프
		0,
		16,	// 사진사이즈 X
		16,	// 사진사이즈 Y
		RGB(200, 0, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
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


