#include "stdafx.h"
#include "BackGround.h"


CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
	Release();
}

void CBackGround::Initialize()
{
	LINE_INFO	tLineInfo[3] =
	{
		{ 100.f, 500.f, 300.f, 500.f },
		{ 300.f, 500.f, 500.f, 300.f },
		{ 500.f, 300.f, 700.f, 300.f }
	};

	m_LineLst.push_back(tLineInfo[0]);
	m_LineLst.push_back(tLineInfo[1]);
	m_LineLst.push_back(tLineInfo[2]);
}

int CBackGround::Update()
{
	return NO_EVENT;
}

void CBackGround::Render(HDC hDC)
{
	//LINE_INFO*
	for (auto& pLine : m_LineLst)
	{
		MoveToEx(hDC, (int)pLine->fStartX, (int)pLine->fStartY, nullptr);
		LineTo(hDC, (int)pLine->fEndX, (int)pLine->fEndY);
	}
}

void CBackGround::Release()
{
	m_LineLst.clear();
}

list<LINE_INFO*> CBackGround::GetLineLst()
{
	return m_LineLst;
}

