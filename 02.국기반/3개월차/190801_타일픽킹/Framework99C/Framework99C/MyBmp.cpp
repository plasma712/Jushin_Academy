#include "stdafx.h"
#include "MyBmp.h"


CMyBmp::CMyBmp()
{
}


CMyBmp::~CMyBmp()
{
	Release();
}

HDC CMyBmp::GetMemDC() const
{
	return m_hMemDC;
}

void CMyBmp::LoadBmp(const wstring& wstrFilePath)
{
	// 1. �ϵ� ��ũ�� ����Ǿ� �ִ� ��Ʈ���� �츮 ���α׷� ���η� �о�;��� ��!
	// ���Ϸκ��� �������°Ŷ�� ù��° ���ڴ� nullptr, �ι�° ���ڴ� �ش� ������ ��θ� �� ��.

	// ��Ʈ�� �о���� ��� 2����.
	// DDB (Device Dependent Bitmap, ��ġ�� �������� ��Ʈ��)
	// DIB (Device Independent Bitmap, ��ġ�� �������� ��Ʈ��)
	m_hBitmap = (HBITMAP)LoadImage(nullptr, wstrFilePath.c_str(), IMAGE_BITMAP,
		0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	HDC hDC = GetDC(g_hWnd);

	// 2. �ҷ��� ��Ʈ���� �̸� �׷��� �����صξ�� �Ѵ�.
	// CreateCompatibleDC: ���DC(ȭ��DC)�� ȣȯ�� �Ǵ� �޸�DC�� ����.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// �޸�DC�� �ҷ��� ��Ʈ���� �̸� �׷� ����.
	// SelectObject: Ư�� DC���� ����� GDI ������Ʈ�� �����ϴ� �Լ�.
	// DC�� ������ �����ϰ� �ִ� GDI ������Ʈ�� ��ȯ.
	m_hOldbmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}
