#include "stdafx.h"
#include "cTitle.h"


cTitle::cTitle()
{
}


cTitle::~cTitle()
{
	Release();
}

void cTitle::Init()
{
	cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/05.Menu/MenuBack.bmp", L"Title");
	//cAniMation::GetInstance()->LoadBmp(L"../Resource/Image/BackBuffer.bmp", L"BackBuffer");

}

int cTitle::Update()
{
	if (cKeyMgr::GetInstance()->KeyPressing(VK_SPACE) ==true || cKeyMgr::GetInstance()->KeyPressing('C') == true)
	{
 		cSceneMgr::GetInstance()->SceneChange(SCENE_STAGE01); // 테스트용
		return 0;
	}
	return 0;
}

void cTitle::Draw(HDC hdc)
{
	HDC hMemDC = cAniMation::GetInstance()->GetMemDC(L"Title");
	NULL_CHECK(hMemDC);

	BitBlt(hdc, 0, 0, WINCX, WINCY, hMemDC, 0, 0, SRCCOPY);

}

void cTitle::Release()
{
}
