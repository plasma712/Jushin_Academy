#include "stdafx.h"
#include "cStageBossScene.h"
#include "ResourceManager.h"
#include "Player.h"
#include "Monster.h"
#include "UIMgr.h"
#include "NamedMonster.h"
#include "BossMonster.h"
#include "Item.h"
#include "SoundManager.h"
#include "NamedMonster.h"
#include "cGunman.h"
#include "cRolling.h"
#include "cStage01Boss.h"
#include "cStage01Object.h"


cStageBossScene::cStageBossScene()
{
}


cStageBossScene::~cStageBossScene()
{
}

void cStageBossScene::Initialize()
{
	m_hDC = CMainGame::GetInstance()->GetHDC();
	m_pResourceMgr = CMainGame::GetInstance()->GetResource();

	CGameObject* pGameObject = nullptr;

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	dynamic_cast<CPlayer*>(pGameObject)->SetBulletLst(&m_ObjLst[OBJECT_BULLET]);
	m_ObjLst[OBJECT_PLAYER].push_back(pGameObject);

	//
	// 보스 + 오브젝트
	pGameObject = CAbstractFactory<cStage01Boss>::CreateObject();
	dynamic_cast<cStage01Boss*>(pGameObject)->SetBulletLst(&m_ObjLst[OBJECT_MONSTER_BULLET]);
	m_ObjLst[OBJECT_MONSTER].push_back(pGameObject);


	//

	pGameObject = CAbstractFactory<CUIMgr>::CreateObject();
	m_ObjLst[OBJECT_UI].push_back(pGameObject);

}

void cStageBossScene::Update()
{
	for (int i = 0; i < OBJECT_END; ++i)
	{
		OBJLIST::iterator iter_Begin = m_ObjLst[i].begin();
		OBJLIST::iterator iter_End = m_ObjLst[i].end();

		for (; iter_Begin != iter_End; )
		{
			int iEvent = (*iter_Begin)->Update();
			INFO in = (*iter_Begin)->GetInfo();

			if (DEAD_OBJ == iEvent)
			{
				//SafeDelete(*iter_Begin);
				if (*iter_Begin)
				{
					delete *iter_Begin;
					*iter_Begin = nullptr;
				}
				iter_Begin = m_ObjLst[i].erase(iter_Begin);
			}
			else
				++iter_Begin;
		}
	}

	CCollisionManager::CollisionRect(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_BULLET]);
	CCollisionManager::CollisionPlayerTerrain(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_STAGEOBJECT]);

	CheckAniRoop(m_ObjLst[OBJECT_MONSTER_BULLET]);


}

void cStageBossScene::Render()
{
	m_iSceneScrolling = cScrollMgr::m_fScrollX;



	//BitBlt
	//(
	//	m_hDC,
	//	100,
	//	0,
	//	WINCX * 2,
	//	WINCY * 2,
	//	m_pResourceMgr->Get(L"BossStage"),
	//	m_iSceneScrolling,
	//	0,
	//	SRCCOPY
	//);

	TransparentBlt
	(
		m_hDC,
		-m_iSceneScrolling,
		0,
		2558,
		WINCY,
		m_pResourceMgr->Get(L"BossStage"),		// 이미지 불러오기
		0,
		0,
		780,
		180,
		RGB(255, 255, 255)						//RGB(200,0,255)로 맞출껏
	);


	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Render(m_hDC);
	}


	//TransparentBlt
	//(
	//	m_hDC,
	//	0,
	//	0,
	//	WINCX,
	//	WINCY,
	//	m_pResourceMgr->Get(L"Stage01_1"),		// 이미지 불러오기
	//	m_iSceneScrolling,
	//	0,
	//	WINCX,
	//	WINCY,
	//	RGB(255, 255, 255)						//RGB(200,0,255)로 맞출껏
	//);

}

void cStageBossScene::Release()
{
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto a : m_ObjLst[i])
		{
			delete a;
			a = nullptr;
		}
	}
}


void cStageBossScene::LoadMonster()
{
}

int cStageBossScene::GetSceneChangeKeyValue()
{
	return m_iSceneChangeKeyValue;
}

void cStageBossScene::SetSceneChangeKeyValue(int _KeyValue)
{
	m_iSceneChangeKeyValue = _KeyValue;
}

void cStageBossScene::CheckAniRoop(OBJLIST & dstLst)
{
	for (auto& pDest : dstLst)
	{
		if (pDest->GetAniCount() == (pDest->GetAniData().iImageCount - 1))
			pDest->SetAniCount(0);
	}
}
