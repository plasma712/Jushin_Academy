#pragma once

class cScene;
class cSceneMgr
{
#pragma region SingleTon

private:
	static cSceneMgr*	m_pInstance;

public:
	static cSceneMgr* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cSceneMgr;

		return m_pInstance;
	}
	void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
#pragma endregion

private:
	cScene* m_pCurrentScene;
	SCENE_TYPE m_ePreSceneType;
	SCENE_TYPE m_eCurSceneType;

public:
	cSceneMgr();
	~cSceneMgr();

public:
	void SceneChange(SCENE_TYPE _eSceneType);
	void Update();
	void Draw(HDC hdc);
	void Release();

};

