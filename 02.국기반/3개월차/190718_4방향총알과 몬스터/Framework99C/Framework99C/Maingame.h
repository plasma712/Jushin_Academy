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
	CGameObject*		m_MonsterCreate;
	BULLET_LST			m_BulletLst;
	MONSTER_LST			m_MonsterLst;

	DWORD dwOldTime = GetTickCount();
	DWORD dwCurTime = 0;


	// 이터레이터 패턴 (반복자 패턴)
	// 다형적인 클래스들을 공통된 컨테이너에 담아 반복자로 일괄처리하는 패턴


};

