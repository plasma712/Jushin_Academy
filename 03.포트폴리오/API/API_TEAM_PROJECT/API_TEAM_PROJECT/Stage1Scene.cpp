#include "stdafx.h"
#include "Stage1Scene.h"
#include "ResourceManager.h"
#include "Player.h"
#include "Monster.h"
#include "UIMgr.h"
#include "LinearMonster.h"
#include "ZigzagMonster.h"
#include "RotateMonster.h"
#include "NamedMonster.h"
#include "BossMonster.h"
#include "Item.h"
#include "SoundManager.h"
#include "NamedMonster.h"
CStage1Scene::CStage1Scene()
{

}


CStage1Scene::~CStage1Scene()
{
	Release();
}

void CStage1Scene::Initialize()
{
	
	m_iProgress = 0;
	m_iSceneScrolling1 = 17265;
	m_iSceneScrolling2 = 35330;
	m_hDC = CMainGame::GetInstance()->GetHDC();
	m_pResourceMgr = CMainGame::GetInstance()->GetResource();

	CGameObject* pGameObject = nullptr;

	// Player
	pGameObject = CAbstractFactory<CPlayer>::CreateObject();
	dynamic_cast<CPlayer*>(pGameObject)->SetBulletLst(&m_ObjLst[OBJECT_BULLET]);
	m_ObjLst[OBJECT_PLAYER].push_back(pGameObject);
	LoadMonster();

	pGameObject = CAbstractFactory<CUIMgr>::CreateObject();
	m_ObjLst[OBJECT_UI].push_back(pGameObject);
	CSoundManager::PlayStageBGM();
}

void CStage1Scene::Update()
{
	m_iProgress += 5;
	if (m_iProgress > 17265)
		m_iProgress = 0;

	m_iSceneScrolling1 -= m_iSceneScrollSpeed;
	m_iSceneScrolling2 -= m_iSceneScrollSpeed;

	if (m_iSceneScrolling1 < -WINCY)
	{
		m_iSceneScrolling1 = 35230;
	}

	if (m_iSceneScrolling2 < -WINCY)
	{
		m_iSceneScrolling2 = 35230;
	}


	while (!m_TmpLst.empty() && dynamic_cast<CMonster*>(m_TmpLst.front())->GetProgress() < m_iProgress + 100)
	{
		std::cout << dynamic_cast<CMonster*>(m_TmpLst.front())->GetProgress() << std::endl;
		m_ObjLst[OBJECT_MONSTER].push_back(m_TmpLst.front());
		m_TmpLst.pop_front();
	}

	for (int i = 0; i < OBJECT_END; ++i)
	{
		OBJLIST::iterator iter_Begin = m_ObjLst[i].begin();
		OBJLIST::iterator iter_End = m_ObjLst[i].end();

		for (; iter_Begin != iter_End; )
		{
			int iEvent = (*iter_Begin)->Update();
			INFO in=(*iter_Begin)->GetInfo();
			
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

	CCollisionManager::CollisionSphereToMonster(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_BULLET]);
	CCollisionManager::CollisionSphere(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_MONSTER_BULLET]);
	
	CCollisionManager::CollisionSphere_Item(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_ITEM]);


	if (m_ObjLst[OBJECT_PLAYER].empty())
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
		{
			CGameObject* pGameObject = nullptr;
			pGameObject = CAbstractFactory<CPlayer>::CreateObject();
			dynamic_cast<CPlayer*>(pGameObject)->SetBulletLst(&m_ObjLst[OBJECT_BULLET]);
			m_ObjLst[OBJECT_PLAYER].push_back(pGameObject);
		}
	}

	CheckAniRoop(m_ObjLst[OBJECT_MONSTER_BULLET]);
	//CheckAniRoop(m_ItemLst[ITEM_GOLD]);

}

void CStage1Scene::Render()
{

	//BackGroundRenderCheck(m_iSceneChangeKeyValue);
	//LstBitBlt.begin();
	//LstBitBlt.end();

	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage1"), 0, m_iSceneScrolling1, SRCCOPY);
	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage1"), 0, m_iSceneScrolling2, SRCCOPY);
	
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Render(m_hDC);
	}

	//UImgr->Render(m_hDC);
}

void CStage1Scene::Release()
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

void CStage1Scene::LoadMonster()
{
	FILE* fp;
	_wfopen_s(&fp, L"./stage1monster.csv", L"rt");
	
	// 회전 테스트용
	//_wfopen_s(&fp, L"./stage1monsterTest.csv", L"rt");
	
	if (nullptr == fp)
	{
		MessageBox(g_hWnd, L"fail to read stage1monster.csv", L"error", MB_OK);
	}
	wchar_t buffer[128];
	CGameObject* pGameObject = nullptr;
	

	
	while (!feof(fp))
	{
		fgetws(buffer, sizeof(buffer), fp);

		if (buffer[wcslen(buffer) - 1] == '\n')
		{
			buffer[wcslen(buffer) - 1] = '\0';
		}

		HDC Resource = CreateCompatibleDC(m_hDC);
		
		TCHAR* next;
		TCHAR* progress;
		TCHAR* x;
		TCHAR* y;
		TCHAR* dir;
		TCHAR* type;
		progress = _tcstok_s(buffer, L",", &next);
		x = _tcstok_s(NULL, L",", &next);
		y = _tcstok_s(NULL, L",", &next);
		dir = _tcstok_s(NULL, L",", &next);
		type = _tcstok_s(NULL, L",", &next);
		switch (_wtoi(type))
		{
		case 0:
			pGameObject = CAbstractFactory<CLinearMonster>::CreateObject(_wtoi(x), _wtoi(y));
			break;
		case 1:
			pGameObject = CAbstractFactory<CZigzagMonster>::CreateObject(_wtoi(x), _wtoi(y));
			break;
		case 2:
			pGameObject = CAbstractFactory<CRotateMonster>::CreateObject(_wtoi(x), _wtoi(y));
			dynamic_cast<CRotateMonster*>(pGameObject)->SetDir(_wtoi(dir));
			break;
		case 3:
			pGameObject = CAbstractFactory<CNamedMonster>::CreateObject(_wtoi(x), _wtoi(y));
			break;
		case 4:
			pGameObject = CAbstractFactory<CBossMonster>::CreateObject(_wtoi(x), _wtoi(y));
			break;
		}
		dynamic_cast<CMonster*>(pGameObject)->Initialize();		
		dynamic_cast<CMonster*>(pGameObject)->SetProgress(_wtoi(progress));
		dynamic_cast<CMonster*>(pGameObject)->SetDirection(_wtoi(dir));
		m_TmpLst.push_back(pGameObject);

	}

}


void CStage1Scene::BackGroundRenderCheck(int _KeyValue)
{
	//LstBitBlt.push_back(BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage1"), 0, m_iSceneScrolling1, SRCCOPY));
	//LstBitBlt.push_back(BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage1"), 0, m_iSceneScrolling2, SRCCOPY));



	//if (_KeyValue == 0)
	//{
	//	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage1"), 0, m_iSceneScrolling1, SRCCOPY);
	//	BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage12"), 0, m_iSceneScrolling2, SRCCOPY);
	//}
	//else if (_KeyValue == 1)
	//{
	//	if (m_iSceneScrolling1 > m_iSceneScrolling2)
	//	{
	//		BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage12"), 0, m_iSceneScrolling2, SRCCOPY);
	//		BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage21"), 0, m_iSceneScrolling1, SRCCOPY);
	//	}
	//	else
	//	{
	//		BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage12"), 0, m_iSceneScrolling1, SRCCOPY);
	//		BitBlt(m_hDC, 0, 0, 800, 900, m_pResourceMgr->Get(L"Stage21"), 0, m_iSceneScrolling2, SRCCOPY);
	//	}
	//}

}

int CStage1Scene::GetSceneChangeKeyValue()
{
	return m_iSceneChangeKeyValue;
}

void CStage1Scene::SetSceneChangeKeyValue(int _KeyValue)
{
	m_iSceneChangeKeyValue = _KeyValue;
}

void CStage1Scene::CheckAniRoop(OBJLIST & dstLst)
{
	for (auto& pDest : dstLst)
	{
		if (pDest->GetAniCount() == (pDest->GetAniData().iImageCount - 1))
			pDest->SetAniCount(0);
	}
}
