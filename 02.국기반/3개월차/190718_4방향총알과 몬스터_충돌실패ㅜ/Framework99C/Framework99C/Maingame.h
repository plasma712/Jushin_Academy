#pragma once

class CGameObject;
class CMaingame
{
public:
	CMaingame();
	~CMaingame();

public:
	void Initialize();
	void Update();
	void Render();

private:
	void Release();

private:
	HDC					m_hDC;
	CGameObject*		m_pPlayer;
	//CGameObject*		m_pMonster;
	BULLET_LST			m_BulletLst;
	CGameObject*		m_MonsterCreate;
	MONSTER_LST			m_MonsterLst;

	DWORD dwOldTime = GetTickCount();
	DWORD dwCurTime = 0;

};

