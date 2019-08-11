#pragma once

class cGameObject;

class cObjectMgr
{
#pragma region SingleTon

private:
	static cObjectMgr*	m_pInstance;

public:
	static cObjectMgr* GetInstance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new cObjectMgr;

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
	OBJLIST m_ObjLst[OBJECT_END];
	int m_iEvent;

public:
	cObjectMgr();
	~cObjectMgr();

public:
	cGameObject* GetPlayer();
	cGameObject* GetBackGround();
	cGameObject* GetMonster();
	cGameObject* GetBullet();

public:
	void AddObject(OBJECT_TYPE _Type, cGameObject* _GameObject);
	void Update();
	void Draw(HDC hdc);
	void ReleaseGroup(OBJECT_TYPE _Type);
	void Relase();

};

