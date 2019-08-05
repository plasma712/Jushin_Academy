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

	// 1. �ϵ� ��ũ�� ����Ǿ� �ִ� ��Ʈ���� �츮 ���α׷� ���η� �о�;��� ��!
	// ���Ϸκ��� �������°Ŷ�� ù��° ���ڴ� nullptr, �ι�° ���ڴ� �ش� ������ ��θ� �ٰ�
	
	// ��Ʈ�� �о���� ��� 2����
	// DDB (Device Dependent BitMap)   ��ġ�� �������� ��Ʈ��
	// DIB (Device Independent BitMap) ��ġ�� �������� ��Ʈ��

	m_hBitmap = (HBITMAP)LoadImage
							(
							 nullptr,
							 wstrFilePath.c_str(),
							 IMAGE_BITMAP,
							 0,	// ��� ������ ��������ũ�� �ҷ����� 0�̸�
							 0, // ��� ������ ��������ũ�� �ҷ����� 0�̸�
							LR_CREATEDIBSECTION
							);

	HDC hDC = GetDC(g_hWnd);

	// 2. �ҷ��� ��Ʈ���� �̸� �׷��� �����صξ�� �Ѵ�.
	// �޸� DC
	// CreateCompatibleDC : ���DC(ȭ��DC)�� ȣȯ�� �Ǵ� �޸� DC ����
	m_hMemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWnd, hDC);

	// �޸�DC�� �ҷ��� ��Ʈ���� �̸� �׷� ����.
	// SelectObject: Ư�� DC���� ����� GDI ������Ʈ�� �����ϴ� �Լ�.
	// DC�� ������ �����ϰ� �ִ� GDI ������Ʈ�� ��ȯ
	m_hOldbmp=(HBITMAP)SelectObject(m_hMemDC, m_hBitmap);


}



void cMyBmp::Release()
{
	SelectObject(m_hMemDC, m_hOldbmp);
	DeleteDC(m_hMemDC);
	DeleteObject(m_hBitmap);
}
