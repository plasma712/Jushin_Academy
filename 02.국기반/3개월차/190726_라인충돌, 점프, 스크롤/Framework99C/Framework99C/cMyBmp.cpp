#include "stdafx.h"
#include "cMyBmp.h"


cMyBmp::cMyBmp()
{
}


cMyBmp::~cMyBmp()
{
	Release();
}


void cMyBmp::LoadBitmap(const wstring & wstrFilePath)
{
	//string str = "Hello";
	//// const char* p = str; // error
	//const char* p = str.c_str();

	// 1. 하드 디스크에 저장되어 있는 비트맵을 우리 프로그램 내부로 읽어와야할 것!
	// 파일로부터 가져오는거라면 첫번째 인자는 nullptr, 두번째 인자는 해당 파일의 경로를 줄것
	
	// 비트맵 읽어오는 방식 2가지
	// DDB (Device Dependent BitMap)   장치에 의존적인 비트맵
	// DIB (Device Independent BitMap) 장치에 독립적인 비트맵

	m_hBitmap = (HBITMAP)LoadImage
							(
							 nullptr,
							 wstrFilePath.c_str(),
							 IMAGE_BITMAP,
							 0,	// 경로 파일의 원본파일크기 불러오기 0이면
							 0, // 경로 파일의 원본파일크기 불러오기 0이면
							LR_CREATEDIBSECTION
							);

	HDC hDC = GetDC(g_hWnd);

	// 2. 불러온 비트맵을 미리 그려서 저장해두어야 한다.
	// 메모리 DC
	// CreateCompatibleDC : 출력DC(화면DC)와 호환이 되는 메모리 DC 생성
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// 메모리DC에 불러온 비트맵을 미리 그려 넣음.
	// SelectObject: 특정 DC에서 사용할 GDI 오브젝트를 선택하는 함수.
	// DC가 이전에 선택하고 있던 GDI 오브젝트를 반환
	m_hOldbmp=(HBITMAP)SelectObject(m_hMemDC, m_hBitmap);


}



void cMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}
