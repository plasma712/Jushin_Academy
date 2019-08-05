#include "stdafx.h"
#include "cMyBmp.h"


cMyBmp::cMyBmp()
{
}


cMyBmp::~cMyBmp()
{
}

void cMyBmp::LoadBmp(const wstring & wstrFilePath, const wstring & wstrObjectKey)
{
	auto iter_find = m_mapBmp.find(wstrObjectKey);

	if (m_mapBmpend() != iter_find)
		return;

	cMyBmp* pBmp = new cMyBmp;
	pBmp->LoadBmp(wstrFilePath);
}

HDC cMyBmp::GetMemDC() const
{
	auto iter_find = m_mapBm

	return HDC();
}
