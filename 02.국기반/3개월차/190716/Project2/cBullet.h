#pragma once
#include "cGameObject.h"

class cGameObject;

class cBullet :public cGameObject
{
public:
	bool LifeBullet=false;
public:
	cBullet();
	virtual ~cBullet();
	cBullet(cBullet* _GameObject);
	
public:
	virtual void Init(HWND hWnd, HDC hdc, cBullet* _GameObject);
	virtual void Draw(HWND hWnd,HDC hdc, cBullet* _GameObject,int _WINCX);
	//TIMERPROC Update(HWND hWnd, cGameObject* _GameObject, int _WINCX);
	virtual void Update(HWND hWnd, cBullet* _GameObject, int _WINCX);
	virtual void Release();
	bool DestoryCheck(int _WINCX);

	
};

