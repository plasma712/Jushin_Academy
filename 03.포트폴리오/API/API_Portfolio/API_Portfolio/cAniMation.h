#pragma once

#include "cBMP.h"

class cAniMation
{
#pragma region SingleTon

private:
	static cAniMation*	m_pInstance;

public:
	static cAniMation* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cAniMation;

		return m_pInstance;
	}
	void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
#pragma endregion

private:
	map<wstring, cBMP*> m_mapBmp;

public:
	cAniMation();
	~cAniMation();

	void Release();

public:
	HDC GetMemDC(const wstring& wstrObjectKey) const;
	void LoadBmp(const wstring& wstrFilePath, const wstring& wstrObjectKey);


};

