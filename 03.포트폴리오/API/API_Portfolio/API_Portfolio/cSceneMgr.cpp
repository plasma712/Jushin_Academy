#include "stdafx.h"
#include "cSceneMgr.h"
#include "cTitle.h"
#include "cStage01.h"


cSceneMgr* cSceneMgr::m_pInstance = nullptr;

cSceneMgr::cSceneMgr()
	:m_pCurrentScene(nullptr), m_ePreSceneType(SCENE_END),m_eCurSceneType(SCENE_END)
{
}


cSceneMgr::~cSceneMgr()
{
	Release();
}

void cSceneMgr::SceneChange(SCENE_TYPE _eSceneType)
{
	m_eCurSceneType = _eSceneType;

	if (m_ePreSceneType != m_eCurSceneType)
	{
		SafeDelete(m_pCurrentScene);

		switch (m_eCurSceneType)
		{
		case SCENE_TITLE:
			m_pCurrentScene = new cTitle;
			break;
		case SCENE_MENU:
			//m_pCurrentScene =
			break;
		case SCENE_STAGE01:
			m_pCurrentScene = new cStage01;
			break;
		case SCENE_STAGE02:
			break;
		}

		m_pCurrentScene->Init();
		m_ePreSceneType = m_eCurSceneType;
	}


}

void cSceneMgr::Update()
{
	NULL_CHECK(m_pCurrentScene);
	m_pCurrentScene->Update();
}

void cSceneMgr::Draw(HDC hdc)
{
	NULL_CHECK(m_pCurrentScene);
	m_pCurrentScene->Draw(hdc);
}

void cSceneMgr::Release()
{
	SafeDelete(m_pCurrentScene);
}
