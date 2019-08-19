#pragma once

using ResourceMap = unordered_map<wstring, HDC>;
using AniDataMap = unordered_map<wstring, AniData>;

class CResourceManager
{
public:
	CResourceManager();
	~CResourceManager();

public:
	void			Initialize(HDC hDC);

private:
	void			Release();

public:
	HDC				Get(wstring ID);
	AniData			GetAniData(wstring ID);

private:
	void			LoadResource();

private:
	static	bool	m_bInstantiated;
	ResourceMap		m_ImageMap;
	AniDataMap		m_AniDataMap;
	HDC				m_hDC;
};
