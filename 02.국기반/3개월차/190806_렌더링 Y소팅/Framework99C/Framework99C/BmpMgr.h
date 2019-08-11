#pragma once

#include "MyBmp.h"

class CBmpMgr
{
	DECLARE_SINGLETON(CBmpMgr)

private:
	CBmpMgr();
	~CBmpMgr();

public:
	HDC GetMemDC(const wstring& wstrObjectKey) const;

public:
	void LoadBmp(const wstring& wstrFilePath, const wstring& wstrObjectKey);

private:
	void Release();

private:
	map<wstring, CMyBmp*>	m_mapBmp;
};

