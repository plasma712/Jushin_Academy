#include "stdafx.h"
#include "cObjectMgr.h"
#include "cGameObject.h"

cObjectMgr*cObjectMgr::m_pInstance = nullptr;

cObjectMgr::cObjectMgr()
{
}


cObjectMgr::~cObjectMgr()
{

}

cGameObject * cObjectMgr::GetPlayer()
{
	if (m_ObjLst[OBJECT_PLAYER].empty())
		return nullptr;

	return m_ObjLst[OBJECT_PLAYER].front();
}

cGameObject * cObjectMgr::GetBackGround()
{
	if (m_ObjLst[OBJECT_BACKGROUND].empty())
		return nullptr;

	return m_ObjLst[OBJECT_BACKGROUND].front();
}

cGameObject * cObjectMgr::GetMonster()
{
	return nullptr;
}

cGameObject * cObjectMgr::GetBullet()
{
	return nullptr;
}

void cObjectMgr::AddObject(OBJECT_TYPE _Type, cGameObject * _GameObject)
{
	NULL_CHECK(_GameObject);
	m_ObjLst[_Type].push_back(_GameObject);
}

void cObjectMgr::Update()
{
	m_iEvent = NO_EVENT;

	for (int i = 0; i < OBJECT_END; ++i)
	{
		OBJLIST::iterator iter_Begin = m_ObjLst[i].begin();
		OBJLIST::iterator iter_End = m_ObjLst[i].end();

		for (; iter_Begin != iter_End; )
		{
			m_iEvent = (*iter_Begin)->Update();

			if (DEAD_OBJ == m_iEvent)
			{
				SafeDelete(*iter_Begin);
				iter_Begin = m_ObjLst[i].erase(iter_Begin);
			}
			else if (CHANGE_SCENE == m_iEvent)
				return;
			else
				++iter_Begin;
		}
	}

	// 충돌처리

	cCollsionMgr::CollisionRectObject(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_MONSTER]);
	cCollsionMgr::CollisionRectBullet(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_MONSTER_BULLET]);
	cCollsionMgr::CollisionRectBullet(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_PLAYER_BULLET]);

	cCollsionMgr::CollisionPlayerWall(m_ObjLst[OBJECT_PLAYER], m_ObjLst[OBJECT_WALL]);
}

void cObjectMgr::Draw(HDC hdc)
{
	if (CHANGE_SCENE == m_iEvent)
		return;

	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Draw(hdc);
	}

}

void cObjectMgr::ReleaseGroup(OBJECT_TYPE _Type)
{
	for_each(m_ObjLst[_Type].begin(), m_ObjLst[_Type].end(), SafeDelete<cGameObject*>);
	m_ObjLst[_Type].clear();

}

void cObjectMgr::Relase()
{
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for_each(m_ObjLst[i].begin(), m_ObjLst[i].end(), SafeDelete<cGameObject*>);
		m_ObjLst[i].clear();
	}

}
