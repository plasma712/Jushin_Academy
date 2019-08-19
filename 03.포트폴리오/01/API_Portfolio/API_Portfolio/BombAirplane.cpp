#include "stdafx.h"
#include "BombAirplane.h"
#include "MainGame.h"
#include "Scene.h"
#include "Bomb.h"

#include "function.h"

int CBombAirplane::m_ibombCount = 0;

CBombAirplane::CBombAirplane()
{
	
}


CBombAirplane::~CBombAirplane()
{
}

void CBombAirplane::Initialize()
{
	++m_ibombCount;
	m_Image = CMainGame::GetInstance()->GetResource()->Get(L"BombAirplane");
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(L"BombAirplane");

	m_fSpeed = 20.f;
	m_fDirection = 270.f;
	m_iAniCount = 0;
	m_iCount = 0;

	m_tInfo.fCX = m_AniData.iWarpWidth*2;
	m_tInfo.fCY = m_AniData.iHeight*2;
}

int CBombAirplane::Update()
{

	++m_iCount;
	m_tInfo.fY -= m_fSpeed;
	CGameObject* pBombPlane;

	if (m_iCount % 10 == 0)
	{
		pBombPlane = CAbstractFactory<CBomb>::CreateObject(m_tInfo.fX, m_tInfo.fY);
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
		pBombPlane = CAbstractFactory<CBomb>::CreateObject(m_tInfo.fX + 75, m_tInfo.fY + 100);
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
		pBombPlane = CAbstractFactory<CBomb>::CreateObject(m_tInfo.fX, m_tInfo.fY + 200);
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);
		pBombPlane = CAbstractFactory<CBomb>::CreateObject(m_tInfo.fX + 75, m_tInfo.fY + 300);
		CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_EFFECT].push_back(pBombPlane);

	}

	if (m_tInfo.fY < -600)
	{
		OBJLIST* pObjLst = CMainGame::GetInstance()->GetScene()->GetOBJLST();

		for_each(pObjLst[OBJECT_MONSTER_BULLET].begin(), pObjLst[OBJECT_MONSTER_BULLET].end(), SetObjectDead);
		for_each(pObjLst[OBJECT_MONSTER].begin(), pObjLst[OBJECT_MONSTER].end(), SetObjectDead);
		--m_ibombCount;;
		return DEAD_OBJ;
	}
		

	if(m_iCount!=0 && m_iCount%100)


	return 0;
}

void CBombAirplane::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	//Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//TransparentBlt(hDC, m_tRect.left, m_tRect.top,m_tInfo.fCX, m_tInfo.fCY, m_Image, 0, 0, m_tInfo.fCX, m_tInfo.fCY, RGB(255, 255, 255));

	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
		m_Image, m_iAniCount*m_AniData.iWarpWidth, 0, m_AniData.iWarpWidth, m_AniData.iHeight,
		RGB(0, 248, 0));
}

void CBombAirplane::Release()
{
	
}
