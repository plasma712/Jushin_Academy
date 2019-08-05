#include "stdafx.h"
#include "KeyManager.h"


CKeyManager::CKeyManager() 
	: m_dwKey(0), m_dwKeyDown(0), m_dwKeyUp(0)
{
}


CKeyManager::~CKeyManager()
{
}

void CKeyManager::Update()
{
	m_dwKey = 0;

	if (GetAsyncKeyState(VK_UP) & 0x8000)
		m_dwKey |= KEY_UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_dwKey |= KEY_DOWN;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_dwKey |= KEY_LEFT;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_dwKey |= KEY_RIGHT;
	if (GetAsyncKeyState('A') & 0x8000)
		m_dwKey |= KEY_A;
	if (GetAsyncKeyState('S') & 0x8000)
		m_dwKey |= KEY_S;
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		m_dwKey |= KEY_S;
}

bool CKeyManager::KeyPressing(DWORD dwKey)
{
	if (m_dwKey & dwKey)
		return true;

	return false;
}

bool CKeyManager::KeyDown(DWORD dwKey)
{
	// 이전에 누른적 없고 현재 눌렀을 때 TRUE
	if (!(m_dwKeyDown & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyDown |= dwKey;
		return true;
	}

	// 이전에 누른적 있고 현재 누르지 않으면 FALSE
	if ((m_dwKeyDown & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyDown ^= dwKey;
		return false;
	}

	return false;
}

bool CKeyManager::KeyUp(DWORD dwKey)
{

	// 이전에 누른적 있고 현재 누르지 않았을 때 TRUE
	if ((m_dwKeyUp & dwKey) && !(m_dwKey & dwKey))
	{
		m_dwKeyUp ^= dwKey;
		return true;
	}

	// 이전에 누른적 없고 현재 눌렸을 때 FALSE
	if (!(m_dwKeyUp & dwKey) && (m_dwKey & dwKey))
	{
		m_dwKeyUp |= dwKey;
		return false;
	}

	return false;
}
