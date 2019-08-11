#include "stdafx.h"
#include "cLineEditer.h"
#include "cGameObject.h"
#include "cMousePoint.h"


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
	POINTFLOAT MousePos;
	MousePos.x = cMousePoint::GetPos().x - cScrollMgr::m_fScrollX;
	MousePos.y = cMousePoint::GetPos().y - cScrollMgr::m_fScrollY;

	if (m_LineList.size() != 0)
	{
		m_tStartPoint.x = m_LineList.front()->tLPoint.x;
		m_tStartPoint.y = m_LineList.front()->tLPoint.y;
	}
	if (GetFocus() == g_hwnd)
	{
		if (cKeyMgr::GetInstance()->KeyPressing('A'))
		{

		}
		if (cKeyMgr::GetInstance()->KeyPressing('D'))
		{

		}
		if (cKeyMgr::GetInstance()->KeyPressing('Q'))
		{
			m_bStart = false;
			m_tStartPoint = MousePos;
			if (m_bStart == false)
			{
				m_LineList.push_back(new LINE(m_tStartPoint, MousePos));
			}
			m_bStart = true;
		}

		if (cKeyMgr::GetInstance()->KeyPressing(VK_LBUTTON))
		{
			if (m_bStart)
			{
				m_LineList.push_back(new LINE(m_LineList.back()->tRPoint, MousePos));
			}
		}

		if (cKeyMgr::GetInstance()->KeyPressing(VK_RETURN))
		{
			WriteData();
		}


	}

	return 0;
}

void cLineEditer::Draw(HDC & hDC)
{
	// 라인그리기
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

	// 폰트 출력
	RECT rFont = { 10, 10, 200, 200 };
	wchar_t wcTmp[128];
	swprintf(wcTmp, 128, L"X : %d, Y : %d",
		int(cMousePoint::GetPos().x),
		int(cMousePoint::GetPos().y));
	DrawText(hDC, wcTmp, -1, &rFont, NULL);

	rFont.top = 30;
	swprintf(wcTmp, 128, L"Start : %d", int(m_bStart));
	DrawText(hDC, wcTmp, -1, &rFont, NULL);

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
	if (MessageBox(g_hwnd, L"저장 하시겠습니까 ? ", L"SystemMessage", MB_OKCANCEL) == IDCANCEL)
	{
		return;
	}

	HANDLE hFile = INVALID_HANDLE_VALUE;
	DWORD dwByte = 0;

	hFile = CreateFile(L"../Line.dat", GENERIC_WRITE, NULL,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)	// 오류출력(예외처리)
		MessageBox(g_hwnd, L"저장 오류 !", NULL, NULL);

	for (list<LINE*>::iterator iter = m_LineList.begin();
		iter != m_LineList.end(); ++iter)
	{
		WriteFile(hFile, (*iter), sizeof(LINE), &dwByte, NULL);
	}
	CloseHandle(hFile);

}

void cLineEditer::ReadData()
{
	HANDLE hFile = INVALID_HANDLE_VALUE;
	DWORD dwByte;

	if (MessageBox(g_hwnd, L"로드 하시겠습니까?", L"SystemMessage", MB_OKCANCEL) == IDCANCEL)
		return;

	this->Release();	// List초기화

	hFile = CreateFile(L"../Line.dat", GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
	{
		MessageBox(g_hwnd, L"Error : 파일을 찾을수 없습니다.", NULL, NULL);
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

	// 중복값 삭제, 혹여나 문제있으면 삭제해도 무방함.
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
