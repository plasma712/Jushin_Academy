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

	RECT rc = {};	

	for (size_t i = 0; i < m_vecTile.size(); ++i)
	{
		hMemDC = CBmpMgr::GetInstance()->GetMemDC(L"Tile");
		NULL_CHECK(hMemDC);
		
		rc.left = LONG(m_vecTile[i]->fX - m_vecTile[i]->fCX * 0.5f);
		rc.top = LONG(m_vecTile[i]->fY - m_vecTile[i]->fCY * 0.5f);

		BitBlt(hDC, 
			int(rc.left - CScrollMgr::m_fScrollX), 
			int(rc.top - CScrollMgr::m_fScrollY), 
			(int)m_vecTile[i]->fCX, (int)m_vecTile[i]->fCY,
			hMemDC, m_vecTile[i]->iDrawID * (int)m_vecTile[i]->fCX, 0, SRCCOPY);
	}
}

void CBackGround::Release()
{
	for_each(m_vecTile.begin(), m_vecTile.end(), SafeDelete<TILE_INFO*>);
	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
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
