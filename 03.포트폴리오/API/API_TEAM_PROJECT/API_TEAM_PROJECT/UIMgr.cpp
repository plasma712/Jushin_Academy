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
		30,	// Rectangle로 보면 Left값
		10,	// Rectangle로 보면 Bottom값
		74, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		98, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_TopStatus, // 이미지 불러오기
		(GetPlayerLife()) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		74,	// 사진사이즈 X
		98,	// 사진사이즈 Y
		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);
	TransparentBlt(
		hDC,
		350,	// Rectangle로 보면 Left값
		10,	// Rectangle로 보면 Bottom값
		68, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		48, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_TopStageNumber, // 이미지 불러오기
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		68,	// 사진사이즈 X
		48,	// 사진사이즈 Y
		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);
	for (int Digits = 1; Digits < 7; Digits++)
	{
		TransparentBlt(
			hDC,
			300-(Digits*25),// Rectangle로 보면 Left값
			20,	// Rectangle로 보면 Bottom값
			25, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
			25, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
			m_pUIMgr_Top_UIScore, // 이미지 불러오기
			0,  // m_iAniCount*m_AniData.iWarpWidth,
			(GetScoreDigits(GetScore(),	Digits)) * 47,  // m_iAniCount*m_AniData.iWarpHeight
			47,	// 사진사이즈 X
			47,	// 사진사이즈 Y
			RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
		);
	}
	// Bottom

	TransparentBlt(
		hDC,
		30,	// Rectangle로 보면 Left값
		840,	// Rectangle로 보면 Bottom값
		304, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		52, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_BottomSubEnergyBar, // 이미지 불러오기
		GetEnergyBarLV() * 304,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		304,	// 사진사이즈 X
		52,	// 사진사이즈 Y
		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);
	TransparentBlt(
		hDC,
		335,	// Rectangle로 보면 Left값
		840,	// Rectangle로 보면 Bottom값
		64, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		64, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_BottomBoom, // 이미지 불러오기
		GetPlayerBoom() * 64,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		64,	// 사진사이즈 X
		64,	// 사진사이즈 Y
		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);
	TransparentBlt(
		hDC,
		50,	// Rectangle로 보면 Left값
		873, // Rectangle로 보면 Bottom값
		GetEnergyBarGague()*2.76,//276, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		10, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
		m_pUIMgr_BottomSubEnergyBarGague, // 이미지 불러오기
		0,  // m_iAniCount*m_AniData.iWarpWidth,
		0,
		276,// 사진사이즈 X
		10,	// 사진사이즈 Y
		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	);


	//list<CGameObject*>::iterator iter_begin = m_pUIMgrLst.begin(); // auto begin_iter = l.begin()도 가능
	//list<CGameObject*>::iterator iter_end = m_pUIMgrLst.end(); // auto end_iter = l.end()도 가능
	//for (; iter_begin != iter_end; ++iter_end)
	//{
	//	TransparentBlt(
	//		hDC,
	//		30,	// Rectangle로 보면 Left값
	//		10,	// Rectangle로 보면 Right값
	//		74, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
	//		98, // 불러오는값? 이라고해야하나 사이즈 크기에 안맞으면 늘거나 줄어들음.
	//		(*iter_begin)->GetImage(), //m_pUIMgr_TopStatus->GetImage(), // 이미지 불러오기
	//		(PlayerLife) * 74,  // m_iAniCount*m_AniData.iWarpWidth,
	//		0,
	//		74,	// 사진사이즈 X
	//		98,	// 사진사이즈 Y
	//		RGB(255, 255, 255) // 투명배경이라서 딱히 상관없음. 디폴트값으로 둠
	//	);
	//}


	//BitBlt(hDC, 100, 0, 74, 98, m_pResourceMgr->Get(L"UIStatus_Top"), 0, 0, SRCCOPY);
	//    (hDC,사진포지션X,사진포지션Y ,사진사이즈X ,사진사이즈 y)
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


