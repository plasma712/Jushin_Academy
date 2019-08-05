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
	// 1. 하드 디스크에 저장되어 있는 비트맵을 우리 프로그램 내부로 읽어와야할 것!
	// 파일로부터 가져오는거라면 첫번째 인자는 nullptr, 두번째 인자는 해당 파일의 경로를 줄 것.

	// 비트맵 읽어오는 방식 2가지.
	// DDB (Device Dependent Bitmap, 장치에 의존적인 비트맵)
	// DIB (Device Independent Bitmap, 장치에 독립적인 비트맵)
	m_hBitmap = (HBITMAP)LoadImage(nullptr, wstrFilePath.c_str(), IMAGE_BITMAP,
		0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);

	HDC hDC = GetDC(g_hWnd);

	// 2. 불러온 비트맵을 미리 그려서 저장해두어야 한다.
	// CreateCompatibleDC: 출력DC(화면DC)와 호환이 되는 메모리DC를 생성.
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// 메모리DC에 불러온 비트맵을 미리 그려 넣음.
	// SelectObject: 특정 DC에서 사용할 GDI 오브젝트를 선택하는 함수.
	// DC가 이전에 선택하고 있던 GDI 오브젝트를 반환.
	m_hOldbmp = (HBITMAP)SelectObject(m_hMemDC, m_hBitmap);
}

void CMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}
