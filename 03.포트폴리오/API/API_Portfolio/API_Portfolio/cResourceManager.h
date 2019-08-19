#pragma once

using ResourceMap = unordered_map<wstring, HDC>;
using AniDataMap = unordered_map<wstring, AniData>;


class cResourceManager
{
private:
	static	bool	m_bInstantiated;
	ResourceMap		m_ImageMap;
	AniDataMap		m_AniDataMap;
	HDC				m_hDC;

public:
	cResourceManager();
	~cResourceManager();

public:
	void Init(HDC hDC);
	void Release();

public:
	HDC				Get(wstring ID);
	AniData			GetAniData(wstring ID);

private:
	void			LoadResource();

};

