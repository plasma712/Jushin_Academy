#pragma once
class CResourceManager;
class CScene;
class CUIMgr;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();
public:
	void				Initialize();
	void				Update();
	void				Render();
private:
	void				Release();
	
public:
	void				SetFPS(int FPS);
	static	CMainGame*	GetInstance();
	CScene*				GetScene();
	void				SetSceneIndex(int idx);
	HDC					GetHDC();
	CResourceManager*	GetResource();
private:
	void				RegisterScene();

private:
	static	CMainGame*	m_instance;
	int					m_iSceneIdx;
	HDC					m_hDC;
	HDC					m_BackDC;
	int					m_iFPS;
	CResourceManager*	m_pResourceMgr;
	CScene*				m_pScene[END_SCENE];

	
};

