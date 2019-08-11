#pragma once

class cGameObject;

class cLineEditer
{
#pragma region SingleTon

private:
	static cLineEditer*	m_pInstance;

public:
	static cLineEditer* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cLineEditer;

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
public:
	int m_fSpeed;
	bool m_bStart;
	POINTFLOAT m_tStartPoint;
	list<LINE*> m_LineList;

public:
	cLineEditer();
	~cLineEditer();

public:
	void Initialize();
	int Update();
	void Draw(HDC & hDC);
	void Release();

public:
	void WriteData();
	void ReadData();

};

