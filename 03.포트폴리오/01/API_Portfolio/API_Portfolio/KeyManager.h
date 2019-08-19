#pragma once

const DWORD KEY_UP		= 0x00000001;
const DWORD KEY_DOWN	= 0x00000002;
const DWORD KEY_LEFT	= 0x00000004;
const DWORD KEY_RIGHT	= 0x00000008;	

const DWORD KEY_A		= 0x00000010;
const DWORD KEY_S		= 0x00000020;
const DWORD KEY_RETURN	= 0x00000040;

///////////////////////////////////////////////////////////////
const DWORD KEY_Z		= 0x00000080;
const DWORD KEY_X		= 0x00000100;
const DWORD KEY_C		= 0x00000200;

class CKeyManager
{
public:
	CKeyManager();
	~CKeyManager();

public:
	void Update();
	bool KeyPressing(DWORD dwKey);
	bool KeyDown(DWORD dwKey);
	bool KeyUp(DWORD dwKey);

private:
	DWORD m_dwKey;
	DWORD m_dwKeyDown;
	DWORD m_dwKeyUp;
};

