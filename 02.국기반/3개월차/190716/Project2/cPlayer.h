#pragma once
#include "cGameObject.h"

class cGameObject;

class cPlayer :public cGameObject
{
public:
	cPlayer();
	virtual ~cPlayer();
	cPlayer(LONG _Left, LONG _Top, LONG _Right, LONG _Down);
	cPlayer(cPlayer* _GameObject);

public:
	virtual void Init(HWND hWnd, HDC hdc, cPlayer* _GameObject);
	virtual void Draw(HWND hWnd, HDC hdc, cPlayer* _GameObject, int _WINCX);
	virtual void Update(HWND hWnd, cPlayer* _GameObject, int _WINCX);
	virtual void Release();

};

