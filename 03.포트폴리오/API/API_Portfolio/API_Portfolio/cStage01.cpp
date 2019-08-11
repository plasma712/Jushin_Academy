#include "stdafx.h"
#include "cStage01.h"
#include "cPlayer.h"
#include "cBackGround.h"
#include "cBullet.h"

cStage01::cStage01()
{
}


cStage01::~cStage01()
{
	Release();
}

void cStage01::Init()
{
	//cLineEditer::GetInstance()->Initialize();
	//cLineEditer::GetInstance()->ReadData();

	cGameObject* pGameObject = nullptr;
	
	pGameObject = cAbstractFactory<cBackGround>::CreateObject();
	cObjectMgr::GetInstance()->AddObject(OBJECT_BACKGROUND, pGameObject);
	
	


	pGameObject = cAbstractFactory<cPlayer>::CreateObject();
	cObjectMgr::GetInstance()->AddObject(OBJECT_PLAYER, pGameObject);


}

int cStage01::Update()
{
	cObjectMgr::GetInstance()->Update();
	
	//cLineEditer::GetInstance()->Update();

	return 0;
}

void cStage01::Draw(HDC hdc)
{
	cObjectMgr::GetInstance()->Draw(hdc);
	
	//cLineEditer::GetInstance()->Draw(hdc);
}

void cStage01::Release()
{
}
