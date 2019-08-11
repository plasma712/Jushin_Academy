#include "stdafx.h"
#include "cAniMation.h"

cAniMation *cAniMation::m_pInstance = nullptr;

cAniMation::cAniMation()
{
}


cAniMation::~cAniMation()
{
	Release();
}

void cAniMation::Release()
{
	for (auto& BMP : m_mapBmp)
	{
		SafeDelete(BMP.second);
	}
	m_mapBmp.clear();
}

HDC cAniMation::GetMemDC(const wstring & wstrObjectKey) const
{
	auto iter_find = m_mapBmp.find(wstrObjectKey);

	if (m_mapBmp.end() == iter_find)
		return nullptr;

	return iter_find->second->GetMemDC();
}

void cAniMation::LoadBmp(const wstring & wstrFilePath, const wstring & wstrObjectKey)
{
	auto iter_find = m_mapBmp.find(wstrObjectKey);

	if (m_mapBmp.end() != iter_find)
		return;

	cBMP* pBmp = new cBMP;
	pBmp->LoadBmp(wstrFilePath);

	m_mapBmp.insert({ wstrObjectKey, pBmp });
}

