#include "stdafx.h"
#include "MyButton.h"


CMyButton::CMyButton()
	: m_iDrawID(0)
{
}


CMyButton::~CMyButton()
{
	Release();
}

void CMyButton::Initialize()
{
	m_tInfo.fCX = 150.f;
	m_tInfo.fCY = 150.f;
}

int CMyButton::Update()
{
	CGameObject::UpdateRect();

	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	// RECT 영역 안에 점(POINT)가 들어오면 TRUE
	if (PtInRect(&m_tRect, pt))
	{
		if (CKeyMgr::GetInstance()->KeyUp(KEY_LBUTTON))
		{
			if (!lstrcmp(L"StartButton", m_wstrObjectKey.c_str()))
			{
				CSceneMgr::GetInstance()->SceneChange(SCENE_STAGE);
				return CHANGE_SCENE;
			}
			else if (!lstrcmp(L"EditButton", m_wstrObjectKey.c_str()))
			{
				CSceneMgr::GetInstance()->SceneChange(SCENE_EDIT);
				return CHANGE_SCENE;
			}
			else if (!lstrcmp(L"ExitButton", m_wstrObjectKey.c_str()))
			{
				DestroyWindow(g_hWnd);
				return NO_EVENT;
			}

		}

		m_iDrawID = 1;
	}
	else
		m_iDrawID = 0;

	return NO_EVENT;
}

void CMyButton::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	HDC hMemDC = CBmpMgr::GetInstance()->GetMemDC(m_wstrObjectKey);
	NULL_CHECK(hMemDC);

	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
		hMemDC, m_iDrawID * (int)m_tInfo.fCX, 0, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(255, 255, 255));
}

void CMyButton::Release()
{
}
