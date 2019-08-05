#include <iostream>
#include <Windows.h>
using namespace std;

const DWORD KEY_UP =    0x00000001;		 // 0000 0000 0000 0000 0000 0000 0000 0001
const DWORD KEY_DOWN =  0x00000002;		 // 0000 0000 0000 0000 0000 0000 0000 0010
const DWORD KEY_LEFT =  0x00000004;		 // 0000 0000 0000 0000 0000 0000 0000 0100
const DWORD KEY_RIGHT = 0x00000008;		 // 0000 0000 0000 0000 0000 0000 0000 1000

const DWORD KEY_RETURN  = 0x000000010;   // 0000 0000 0000 0000 0000 0000 0001 0000
const DWORD KEY_SPACE   = 0x000000020;	 // 0000 0000 0000 0000 0000 0000 0010 0000
const DWORD KEY_LBUTTON = 0x000000040;	 // 0000 0000 0000 0000 0000 0000 0100 0000
const DWORD KEY_RBUTTON = 0x000000080;	 // 0000 0000 0000 0000 0000 0000 1000 0000


class cKeyMgr
{
private:
	DWORD m_dwKey;
	DWORD m_dwKeyDown;
	DWORD m_dwKeyUp;
public:
	cKeyMgr()
		:m_dwKey(0), m_dwKeyDown(0), m_dwKeyUp(0)
	{

	}
	bool KeyPressing(DWORD dwKey)
	{
		if (m_dwKey & dwKey)
			return true;

		return false;
	}

	bool KeyDown(DWORD dwKey)
	{
		// 이전에 누른적 없고         현재 눌렀을 때 TRUE
		if (!(m_dwKeyDown & dwKey) && (m_dwKey & m_dwKey))
		{
			return true;
		}

		// 이전에 누른적 있고       현재 누르지 않으면 FALSE
		if ((m_dwKeyDown & dwKey) && !(m_dwKey & m_dwKey))
		{
			m_dwKeyDown ^= dwKey;
			return false;
		}
		return false;
	}
	bool KeyUP(DWORD dwKey)
	{
		// 이전에 누른적 없고         현재 누르지 않았을 때 TRUE
		if ((m_dwKeyUp & dwKey) && !(m_dwKey & m_dwKey))
		{
			return true;
		}

		// 이전에 누른적 없고         현재 눌렀을 때 FALSE
		if (!(m_dwKeyUp & dwKey) && (m_dwKey & m_dwKey))
		{
			m_dwKeyUp |= dwKey;
			return false;
		}
		return false;
	}



public:
	void Update()
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
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
			m_dwKey |= KEY_RETURN;
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			m_dwKey |= KEY_SPACE;
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			m_dwKey |= KEY_LBUTTON;
		if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
			m_dwKey |= KEY_RBUTTON;

	}
};


void main()
{
	cKeyMgr keyMgr;

	while (true)
	{
		keyMgr.Update();

	}


	return;
}