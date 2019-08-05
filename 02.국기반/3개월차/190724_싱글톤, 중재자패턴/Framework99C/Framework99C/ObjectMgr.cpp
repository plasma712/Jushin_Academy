#include "stdafx.h"
#include "ObjectMgr.h"
#include "GameObject.h"

CObjectMgr* CObjectMgr::m_pInstance = nullptr;

CObjectMgr::CObjectMgr()
{
}


CObjectMgr::~CObjectMgr()
{
	Release();
}

CGameObject* CObjectMgr::GetPlayer() const
{
	if (m_ObjLst[OBJECT_PLAYER].empty())
		return nullptr;

	return m_ObjLst[OBJECT_PLAYER].front();
}

void CObjectMgr::AddObject(OBJECT_TYPE eType, CGameObject* pObject)
{
	NULL_CHECK(pObject);
	m_ObjLst[eType].push_back(pObject);
}

void CObjectMgr::Update()
{	
	for (int i = 0; i < OBJECT_END; ++i)
	{
		OBJLIST::iterator iter_Begin = m_ObjLst[i].begin();
		OBJLIST::iterator iter_End = m_ObjLst[i].end();

		for (; iter_Begin != iter_End; )
		{
			int iEvent = (*iter_Begin)->Update();

			if (DEAD_OBJ == iEvent)
			{
				SafeDelete(*iter_Begin);
				iter_Begin = m_ObjLst[i].erase(iter_Begin);
			}
			else
				++iter_Begin;
		}
	}

	//CCollsionMgr::CollisionRect(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJLECT_BULLET]);
	CCollsionMgr::CollisionRectEX(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_PLAYER]);
	CCollsionMgr::CollisionSphere(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJLECT_BULLET]);
	CCollsionMgr::CollisionSphere(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_SHIELD]);
	CCollsionMgr::CollisionSphere(m_ObjLst[OBJECT_MONSTER], m_ObjLst[OBJECT_MOUSE]);
}

void CObjectMgr::Render(HDC hDC)
{	
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for (auto& pObject : m_ObjLst[i])
			pObject->Render(hDC);
	}
}

void CObjectMgr::Release()
{
	for (int i = 0; i < OBJECT_END; ++i)
	{
		for_each(m_ObjLst[i].begin(), m_ObjLst[i].end(), SafeDelete<CGameObject*>);
		m_ObjLst[i].clear();
	}
}
