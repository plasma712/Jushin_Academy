#include "stdafx.h"
#include "SceneMgr.h"
#include "Title.h"
#include "MyMenu.h"
#include "MyEdit.h"
#include "Stage.h"

IMPLEMENT_SINGLETON(CSceneMgr)

CSceneMgr::CSceneMgr()
	: m_pCurrentScene(nullptr), m_ePreSceneType(SCENE_END), m_eCurSceneType(SCENE_END)
{
}


CSceneMgr::~CSceneMgr()
{
	Release();
}

void CSceneMgr::SceneChange(SCENE_TYPE eSceneType)
{
	m_eCurSceneType = eSceneType;

	if (m_ePreSceneType != m_eCurSceneType)
	{
		SafeDelete(m_pCurrentScene);

		// State 패턴
		// FSM을 상속과 다형성으로 확장한 디자인 패턴.
		switch (m_eCurSceneType)
		{
		case SCENE_TITLE:
			m_pCurrentScene = new CTitle;
			break;
		case SCENE_MENU:
			m_pCurrentScene = new CMyMenu;
			break;
		case SCENE_EDIT:
			m_pCurrentScene = new CMyEdit;
			break;
		case SCENE_STAGE:
			m_pCurrentScene = new CStage;
			break;
		}

		m_pCurrentScene->Initialize();
		m_ePreSceneType = m_eCurSceneType;
	}
}

void CSceneMgr::Update()
{
	NULL_CHECK(m_pCurrentScene);
	m_pCurrentScene->Update();
}

void CSceneMgr::Render(HDC hDC)
{
	NULL_CHECK(m_pCurrentScene);
	m_pCurrentScene->Render(hDC);
}

void CSceneMgr::Release()
{
	SafeDelete(m_pCurrentScene);
}
