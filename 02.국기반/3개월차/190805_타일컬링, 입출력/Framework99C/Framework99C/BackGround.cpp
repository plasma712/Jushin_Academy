#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
	Release();
}

const list<LINE_INFO*>& CBackGround::GetLineLst() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_LineLst;
}

void CBackGround::Initialize()
{
	m_tInfo.fX = 400.f;
	m_tInfo.fY = 300.f;

	m_tInfo.fCX = (float)WINCX;
	m_tInfo.fCY = (float)WINCY;

	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Back.bmp", L"BackGround");
	CBmpMgr::GetInstance()->LoadBmp(L"../Image/Tile.bmp", L"Tile");

	TILE_INFO* pTile = nullptr;

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			pTile = new TILE_INFO;

			pTile->fX = TILECX * 0.5f + TILECX * j;
			pTile->fY = TILECY * 0.5f + TILECY * i;
			pTile->fCX = (float)TILECX;
			pTile->fCY = (float)TILECY;
			pTile->iDrawID = 0;
			pTile->iOption = 0;

			m_vecTile.push_back(pTile);
		}
	}
}

int CBackGround::Update()
{	
	IsPicking();

	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	
	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"BackGround");
	NULL_CHECK(hMemDC);

	BitBlt(hDC, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, 0, 0, SRCCOPY);

	// 컬링
	// 화면 또는 시야 범위 안에 존재하는 오브젝트들에 대해서만 연산처리하는 최적화 기법.
	int iRow = (int)CScrollMgr::m_fScrollY / TILECY;
	int iCol = (int)CScrollMgr::m_fScrollX / TILECX;

	int iRowEnd = iRow + WINCY / TILECY;
	int iColEnd = iCol + WINCX / TILECX;

	RECT rc = {};	

	for (int i = iRow; i < iRowEnd + 2; ++i)
	{
		for(int j = iCol; j < iColEnd + 2; ++j)
		{
			int iIndex = i * TILEX + j;

			// 벡터의 범위를 넘어서는 인덱싱 예외처리.
			if(0 > iIndex || (size_t)iIndex >= m_vecTile.size())
				continue;

			hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Tile");
			NULL_CHECK(hMemDC);

			rc.left = LONG(m_vecTile[iIndex]->fX - m_vecTile[iIndex]->fCX * 0.5f);
			rc.top = LONG(m_vecTile[iIndex]->fY - m_vecTile[iIndex]->fCY * 0.5f);

			BitBlt(hDC,
				int(rc.left - CScrollMgr::m_fScrollX),
				int(rc.top - CScrollMgr::m_fScrollY),
				(int)m_vecTile[iIndex]->fCX, (int)m_vecTile[iIndex]->fCY,
				hMemDC, m_vecTile[iIndex]->iDrawID * (int)m_vecTile[iIndex]->fCX, 0, SRCCOPY);
		}
	}	
}

void CBackGround::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), SafeDelete<TILE_INFO*>);
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

void CBackGround::SaveTile(const wstring& wstrFilePath)
{
	// Win API의 파일 개방 함수.
	HANDLE hFile = CreateFile(wstrFilePath.c_str(), GENERIC_WRITE, 0, 0,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

	// 파일 개방 실패
	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Save Tile Failed", L"System Error", MB_OK);
		return;
	}

	DWORD dwBytes = 0;

	for (auto& pTile : m_vecTile)
	{
		// Win API 파일 출력 함수.
		WriteFile(hFile, pTile, sizeof(TILE_INFO), &dwBytes, nullptr);
	}

	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Save Tile Success", L"System Ok", MB_OK);
}

void CBackGround::LoadTile(const wstring & wstrFilePath)
{
	HANDLE hFile = CreateFile(wstrFilePath.c_str(), GENERIC_READ, 0, 0,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
	{
		MessageBox(g_hWnd, L"Load Tile Failed", L"System Error", MB_OK);
		return;
	}

	if (!m_vecTile.empty())
	{
		for_each(m_vecTile.begin(), m_vecTile.end(), SafeDelete<TILE_INFO*>);
		m_vecTile.clear();
		m_vecTile.shrink_to_fit();
	}

	DWORD dwBytes = 0;
	TILE_INFO tTileInfo = {};

	while (true)
	{
		ReadFile(hFile, &tTileInfo, sizeof(TILE_INFO), &dwBytes, nullptr);

		// 더이상 불러올 것이 없다면
		if (0 == dwBytes)
			break;

		m_vecTile.push_back(new TILE_INFO(tTileInfo));
	}

	CloseHandle(hFile);

	MessageBox(g_hWnd, L"Load Tile Success", L"System Ok", MB_OK);
}

void CBackGround::IsPicking()
{
	if (CKeyMgr::GetInstance()->KeyUp(KEY_LBUTTON))
	{		
		POINT pt = {};
		GetCursorPos(&pt);
		ScreenToClient(g_hWnd, &pt);

		int iRow = int(pt.y + CScrollMgr::m_fScrollY) / TILECY;
		int iCol = int(pt.x + CScrollMgr::m_fScrollX) / TILECX;

		// index = i * 가로너비 + j
		int iIndex = iRow * TILEX + iCol;

		if (0 > iIndex || (size_t)iIndex >= m_vecTile.size())
			return;

		m_vecTile[iIndex]->iDrawID = 1;
	}
}
