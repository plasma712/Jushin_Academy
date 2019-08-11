#pragma once

//const DWORD KEY_UP = 0x00000001;	// 0000 0000 0000 0000 0000 0000 0000 0001
//const DWORD KEY_DOWN = 0x00000002;	// 0000 0000 0000 0000 0000 0000 0000 0010
//const DWORD KEY_LEFT = 0x00000004;	// 0000 0000 0000 0000 0000 0000 0000 0100
//const DWORD KEY_RIGHT = 0x00000008;	// 0000 0000 0000 0000 0000 0000 0000 1000
//
//const DWORD KEY_RETURN = 0x00000010;	// 0000 0000 0000 0000 0000 0000 0001 0000
//const DWORD KEY_SPACE = 0x00000020;	// 0000 0000 0000 0000 0000 0000 0010 0000
//
//const DWORD KEY_LBUTTON = 0x00000040;	// 0000 0000 0000 0000 0000 0000 0100 0000
//const DWORD KEY_RBUTTON = 0x00000080;	// 0000 0000 0000 0000 0000 0000 1000 0000
//
//const DWORD KEY_Z = 0x00000100;
//const DWORD KEY_X = 0x00000200;
//const DWORD KEY_C = 0x00000400;

///////////////////////////////
// 라인 에디터에서 사용할 키

//const DWORD KEY_A = 0x00000800;
//const DWORD KEY_D = 0x00001000;
//const DWORD KEY_Q = 0x00002000; // 스타트
//const DWORD KEY_S = 0x00004000; // 저장
//
#define KEY_END 0xff

class cKeyMgr
{
#pragma region SingleTon

private:
	static cKeyMgr*	m_pInstance;

public:
	static cKeyMgr* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cKeyMgr;

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
	//DWORD m_dwKey;
	//DWORD m_dwKeyDown;
	//DWORD m_dwKeyUp;
public:

	cKeyMgr();
	~cKeyMgr();
public:
	void Update();

public:
	bool	m_bIsKey[KEY_END];


	bool KeyPressing(int _iKey);
	bool KeyDown(int _iKey);
	bool KeyUp(int _iKey);


};

