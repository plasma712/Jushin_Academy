#include "stdafx.h"
#include "cBullet.h"




cBullet::cBullet()
{
}


cBullet::~cBullet()
{
}

cBullet::cBullet(cBullet * _GameObject)
	:cGameObject(_GameObject)
{
}

void cBullet::Init(HWND hWnd, HDC hdc, cBullet * _GameObject)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

void cBullet::Draw(HWND hWnd, HDC hdc, cBullet* _GameObject, int _WINCX)
{
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	Update(hWnd, _GameObject, _WINCX);
	//Ellipse(hdc,rc.left, rc.top, rc.right, rc.bottom);
	////SetTimer(hWnd, 0, 1000, nullptr);
}
//TIMERPROC cBullet::Update(HWND hWnd, cGameObject * _GameObject, int _WINCX)
//{
//	_GameObject->SetPosRight(10);
//	_GameObject->SetPosLeft(10);
//}

void cBullet::Update(HWND hWnd, cBullet * _GameObject, int _WINCX)
{
	_GameObject->SetPosRight(30);
	_GameObject->SetPosLeft(30);
}

void cBullet::Release()
{
}

bool cBullet::DestoryCheck(int _WINCX)
{
	if (rc.left >= _WINCX)
		return true;

	return false;
}



