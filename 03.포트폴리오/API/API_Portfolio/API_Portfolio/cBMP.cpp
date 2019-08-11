#include "stdafx.h"
#include "cBMP.h"

cBMP* cBMP::m_pInstance = nullptr;

cBMP::cBMP()
{
}


cBMP::~cBMP()
{
	Release();
}

HDC cBMP::GetMemDC()
{
	return m_MemDC;
}

void cBMP::LoadBmp(const wstring & wstrFilePath)
{
	m_BitMap = (HBITMAP)LoadImage
	(
		nullptr,
		wstrFilePath.c_str(),
		IMAGE_BITMAP,
		0,
		0,
		LR_CREATEDIBSECTION | LR_LOADFROMFILE
	);

	HDC hdc = GetDC(g_hwnd);

	m_MemDC = CreateCompatibleDC(hdc);
	ReleaseDC(g_hwnd, hdc);

	m_OldBmp = (HBITMAP)SelectObject(m_MemDC, m_BitMap);
}

void cBMP::Release()
{
	SelectObject(m_MemDC, m_OldBmp);
	DeleteDC(m_MemDC);
	DeleteObject(m_BitMap);
}
