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
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	return m_LineLst;
}

void CBackGround::Initialize()
{
	
}

int CBackGround::Update()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// ScreenToClient�� ��ȯ�� ���콺��ǥ�� �׻� ȭ�� ���� ��ǥ�̴�.
	// ȭ�� ��ǥ -> ���� ���� ��ǥ ��ȯ.
	pt.x += (LONG)CScrollMgr::m_fScrollX;

	if (CKeyMgr::GetInstance()->KeyDown(KEY_LBUTTON))
	{
		LINE_INFO* pLine = new LINE_INFO;
		pLine->fStartX = (float)pt.x;
		pLine->fStartY = (float)pt.y;
		pLine->fEndX = (float)pt.x;
		pLine->fEndY = (float)pt.y;

		m_LineLst.push_back(pLine);
	}

	if (CKeyMgr::GetInstance()->KeyUp(KEY_LBUTTON))
	{
		m_LineLst.back()->fEndX = (float)pt.x;
		m_LineLst.back()->fEndY = (float)pt.y;
	}

	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	// auto: LINE_INFO*
	for (auto& pLine : m_LineLst)
	{
		// ���� ���� ��ǥ -> ȭ�� ��ǥ�� ��ȯ.
		MoveToEx(hDC, int(pLine->fStartX - CScrollMgr::m_fScrollX), (int)pLine->fStartY, nullptr);
		LineTo(hDC, int(pLine->fEndX - CScrollMgr::m_fScrollX), (int)pLine->fEndY);
	}
}

void CBackGround::Release()
{
	for_each(m_LineLst.begin(), m_LineLst.end(), SafeDelete<LINE_INFO*>);
	m_LineLst.clear();
}
