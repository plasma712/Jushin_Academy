#pragma once

class CScene;
class CSceneMgr
{
	DECLARE_SINGLETON(CSceneMgr)

private:
	CSceneMgr();
	~CSceneMgr();

public:
	void SceneChange(SCENE_TYPE eSceneType);
	void Update();
	void Render(HDC hDC);

private:
	void Release();

private:
	CScene*		m_pCurrentScene;
	SCENE_TYPE	m_ePreSceneType;
	SCENE_TYPE	m_eCurSceneType;
};

