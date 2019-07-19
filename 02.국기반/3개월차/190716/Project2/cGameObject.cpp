#include "stdafx.h"
#include "cGameObject.h"
#include "cBullet.h"
#include "cPlayer.h"


cGameObject::cGameObject()
{
}

cGameObject::cGameObject(LONG _Left, LONG _Top, LONG _Right, LONG _Down)
	:rc{ _Left,_Top,_Right,_Down }
{
}

cGameObject::cGameObject(cGameObject * _GameObject)
{
	rc.top = _GameObject->rc.top;
	rc.bottom = _GameObject->rc.bottom;
	rc.left = _GameObject->rc.left;
	rc.right = _GameObject->rc.right;
}


cGameObject::~cGameObject()
{
}

LONG cGameObject::GetPosTop()
{
	return rc.top;
}

LONG cGameObject::GetPosBottom()
{
	return rc.bottom;
}

LONG cGameObject::GetPosLeft()
{
	return rc.left;
}

LONG cGameObject::GetPosRight()
{
	return rc.right;
}

void cGameObject::SetPosTop(LONG _Top)
{
	rc.top += _Top;
}

void cGameObject::SetPosBottom(LONG _Bottom)
{
	rc.bottom += _Bottom;
}

void cGameObject::SetPosLeft(LONG _Left)
{
	rc.left += _Left;
}

void cGameObject::SetPosRight(LONG _Right)
{
	rc.right += _Right;
}

void cGameObject::SetPos(LONG _Top, LONG _Bottom, LONG _Left, LONG _Right)
{
	rc.top = _Top;
	rc.bottom = _Bottom;
	rc.left = _Left;
	rc.right = _Right;
}

void cGameObject::SetPosObject(cGameObject * _GameObject)
{
	rc.top = _GameObject->rc.top;
	rc.bottom = _GameObject->rc.bottom;
	rc.left = _GameObject->rc.left;
	rc.right = _GameObject->rc.right;
}

void cGameObject::bulletCreate()
{
	Bullet = new cBullet;
}

