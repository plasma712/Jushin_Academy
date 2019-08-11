#include "stdafx.h"
#include "BmpMgr.h"

IMPLEMENT_SINGLETON(CBmpMgr)

CBmpMgr::CBmpMgr()
{
}


CBmpMgr::~CBmpMgr()
{
	Release();
}

HDC CBmpMgr::GetMemDC(const wstring& wstrObjectKey) const
{
	auto iter_find = m_mapBmp.find(wstrObjectKey);

	if (m_mapBmp.end() == iter_find)
		return nullptr;


	return iter_find->second->GetMemDC();
}

void CBmpMgr::LoadBmp(const wstring& wstrFilePath, const wstring& wstrObjectKey)
{
	auto iter_find = m_mapBmp.find(wstrObjectKey);

	if (m_mapBmp.end() != iter_find)
		return;

	CMyBmp* pBmp = new CMyBmp;
	pBmp->LoadBmp(wstrFilePath);

	m_mapBmp.insert({ wstrObjectKey, pBmp });
}

void CBmpMgr::Release()
{
	for (auto& MyPair : m_mapBmp)
		SafeDelete(MyPair.second);

	m_mapBmp.clear();
}
