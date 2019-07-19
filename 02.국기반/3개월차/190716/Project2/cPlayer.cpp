#include "stdafx.h"
#include "cPlayer.h"


cPlayer::cPlayer()
{
}


cPlayer::~cPlayer()
{
}

cPlayer::cPlayer(LONG _Left, LONG _Top, LONG _Right, LONG _Down)
	:cGameObject(_Left,_Top,_Right,_Down)
{
}

cPlayer::cPlayer(cPlayer * _GameObject)
	:cGameObject(_GameObject)
{
}

void cPlayer::Init(HWND hWnd, HDC hdc, cPlayer * _GameObject)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void cPlayer::Draw(HWND hWnd, HDC hdc, cPlayer * _GameObject, int _WINCX)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void cPlayer::Update(HWND hWnd, cPlayer * _GameObject, int _WINCX)
{

}

void cPlayer::Release()
{
}
