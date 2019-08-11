#pragma once
class cBMP
{
#pragma region SingleTon

private:
	static cBMP*	m_pInstance;

public:
	static cBMP* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cBMP;

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
	HBITMAP m_BitMap;
	HBITMAP m_OldBmp;

	HDC m_MemDC;

public:
	cBMP();
	~cBMP();
public:
	HDC GetMemDC();

public:
	void LoadBmp(const wstring& wstrFilePath);
	void Release();

};

