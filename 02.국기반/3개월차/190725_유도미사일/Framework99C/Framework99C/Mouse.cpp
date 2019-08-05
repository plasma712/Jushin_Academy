#include "stdafx.h"
#include "Mouse.h"


CMouse::CMouse()
{
}


CMouse::~CMouse()
{
	Release();
}

void CMouse::Initialize()
{
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;
}

int CMouse::Update()
{
	POINT pt = {};

	// ���� ���콺 Ŀ�� ��ġ�� ������ API �Լ�
	// Ŭ���̾�Ʈ ���� ��ǥ�� �ƴ� ��ü ��ũ�� ��ǥ ���� ���콺 Ŀ�� ��ġ�� ����.
	GetCursorPos(&pt);

	// ��ũ�� ��ǥ�� ���� ���콺 ��ġ�� Ŭ���̾�Ʈ ��ǥ�� ��ȯ�ϴ� API �Լ�.
	ScreenToClient(g_hWnd, &pt);

	m_tInfo.fX = float(pt.x);
	m_tInfo.fY = float(pt.y);

	return NO_EVENT;
}

void CMouse::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMouse::Release()
{
}
