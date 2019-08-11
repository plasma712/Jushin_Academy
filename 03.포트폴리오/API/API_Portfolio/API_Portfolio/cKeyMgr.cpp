#include "stdafx.h"
#include "cKeyMgr.h"

cKeyMgr* cKeyMgr::m_pInstance = nullptr;


cKeyMgr::cKeyMgr()
	//: m_dwKey(0), m_dwKeyDown(0), m_dwKeyUp(0)
{
}


cKeyMgr::~cKeyMgr()
{
}

void cKeyMgr::Update()
{
	//m_dwKey = 0;

	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//	m_dwKey |= KEY_UP;
	//if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	//	m_dwKey |= KEY_DOWN;
	//if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	//	m_dwKey |= KEY_LEFT;
	//if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	//	m_dwKey |= KEY_RIGHT;
	//if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	//	m_dwKey |= KEY_RETURN;
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	//	m_dwKey |= KEY_SPACE;
	//if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	//	m_dwKey |= KEY_LBUTTON;
	//if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	//	m_dwKey |= KEY_RBUTTON;
	//if (GetAsyncKeyState('Z') & 0x8000)
	//	m_dwKey |= KEY_Z;
	//if (GetAsyncKeyState('X') & 0x8000)
	//	m_dwKey |= KEY_X;
	//if (GetAsyncKeyState('C') & 0x8000)
	//	m_dwKey |= KEY_C;
	////////////////////////////////////////////////////
	//if (GetAsyncKeyState('A') & 0x8000)
	//	m_dwKey |= KEY_A;
	//if (GetAsyncKeyState('D') & 0x8000)
	//	m_dwKey |= KEY_D;
	//if (GetAsyncKeyState('Q') & 0x8000)
	//	m_dwKey |= KEY_Q;
	//if (GetAsyncKeyState('S') & 0x8000)
	//	m_dwKey |= KEY_S;

	for (int i = 0; i < KEY_END; ++i)
	{
		if (!m_bIsKey[i] && (GetAsyncKeyState(i) & 0x8000))
		{
			m_bIsKey[i] = true;
		}

		if (m_bIsKey[i] && !(GetAsyncKeyState(i) & 0x8000))
		{
			m_bIsKey[i] = false;
		}
	}

}

bool cKeyMgr::KeyPressing(int _iKey)
{
	return (GetAsyncKeyState(_iKey) & 0x8000);
}

bool cKeyMgr::KeyDown(int _iKey)
{
	if (!m_bIsKey[_iKey] && (GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bIsKey[_iKey] = true;
		return true;
	}
	return false;

}

bool cKeyMgr::KeyUp(int _iKey)
{
	if (m_bIsKey[_iKey] && !(GetAsyncKeyState(_iKey) & 0x8000))
	{
		m_bIsKey[_iKey] = false;
		return true;
	}
	return false;
}
