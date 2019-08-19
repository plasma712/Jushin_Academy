#include "stdafx.h"
#include "cLineEditer.h"
#include "GameObject.h"


cLineEditer* cLineEditer::m_pInstance = nullptr;

cLineEditer::cLineEditer()
{

}


cLineEditer::~cLineEditer()
{
}

void cLineEditer::Initialize()
{
	m_bStart = false;
}

int cLineEditer::Update()
{
	return 0;
}

void cLineEditer::Draw(HDC & hDC)
{
	// ���α׸���
	MoveToEx
	(
		hDC,
		int(m_tStartPoint.x - cScrollMgr::m_fScrollX),
		int(m_tStartPoint.y),
		NULL
	);

	for (list<LINE*>::iterator iter = m_LineList.begin();
		iter != m_LineList.end(); ++iter)
	{
		LineTo
		(
			hDC,
			int((*iter)->tRPoint.x - cScrollMgr::m_fScrollX),
			int((*iter)->tRPoint.y)
		);
	}

}

void cLineEditer::Release()
{
	for (list<LINE*>::iterator iter = m_LineList.begin();
		iter != m_LineList.end();)
	{
		SafeDelete(*iter);
		iter = m_LineList.erase(iter);
	}
	m_LineList.clear();
}

void cLineEditer::WriteData()
{

}

void cLineEditer::ReadData()
{
	HANDLE hFile = INVALID_HANDLE_VALUE;
	DWORD dwByte;

	//if (MessageBox(g_hWnd, L"�ε� �Ͻðڽ��ϱ�?", L"SystemMessage", MB_OKCANCEL) == IDCANCEL)
	//	return;

	this->Release();	// List�ʱ�ȭ

	hFile = CreateFile(L"../Line.dat", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(g_hWnd, L"Error : ������ ã���� �����ϴ�.", NULL, NULL);
		return;
	}

	while (true)
	{
		LINE* pLine = new LINE;

		ReadFile(hFile, pLine, sizeof(LINE), &dwByte, NULL);

		m_LineList.push_back(pLine);

		if (dwByte == 0)
			break;
	}

	// �ߺ��� ����, Ȥ���� ���������� �����ص� ������.
	list<LINE*>::iterator iter_er = m_LineList.begin();
	for (; iter_er != m_LineList.end();)
	{
		if ((*iter_er)->tLPoint.x == (*iter_er)->tRPoint.x)
			iter_er = m_LineList.erase(iter_er);
		else
			iter_er++;
	}

	CloseHandle(hFile);

}
