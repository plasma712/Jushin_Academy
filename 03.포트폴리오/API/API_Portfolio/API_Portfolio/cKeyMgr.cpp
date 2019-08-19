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
