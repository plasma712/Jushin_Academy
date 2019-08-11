#pragma once
class cScene
{
public:
	cScene();
	virtual ~cScene();
public:
	virtual void Init()=0;
	virtual int Update() = 0;
	virtual void Draw(HDC hdc) = 0;
	virtual void Release() = 0;
};

