#pragma once
//#include "cBullet.h"
//#include "cPlayer.h"
class cBullet;
class cPlayer;

class cGameObject
{

protected:
	RECT rc;
public:
	cBullet* Bullet;
	cPlayer* Player;
	
public:
	cGameObject();
	cGameObject(LONG _Left, LONG _Top, LONG _Right, LONG _Down);
	cGameObject(cGameObject* _GameObject);
	virtual~cGameObject();

public:
	
	virtual LONG GetPosTop();
	virtual LONG GetPosBottom();
	virtual LONG GetPosLeft();
	virtual LONG GetPosRight();

public:
	virtual void SetPosTop(LONG _Top);
	virtual void SetPosBottom(LONG _Bottom);
	virtual void SetPosLeft(LONG _Left);
	virtual void SetPosRight(LONG _Right);

public:
	virtual void SetPos(LONG _Top, LONG _Bottom, LONG _Left, LONG _Right);
	virtual void SetPosObject(cGameObject* _GameObject);


public:
	void bulletCreate();
};

