#include "stdafx.h"
#include "Item.h"
#include "UIMgr.h"
#include "Scene.h"


CItem::CItem()
{
}


CItem::~CItem()
{
	Release();
}

void CItem::Initialize()
{
	int iRandom = rand() % 100;

	if (iRandom < 75)
	{
		m_ItemNumber = 0;
		SetSprite(L"Item_Gold");
		//SetSprite(L"Item_Power");

	}
	else if (iRandom < 95)
	{
		m_ItemNumber = 1;
		SetSprite(L"Item_Power");
	}
	else
	{
		m_ItemNumber = 2;
		SetSprite(L"Item_Bomb");
	}
	SetRect();
	m_fDirection = 0;
	SetSpeed(5);
}

int CItem::Update()
{
	if (m_bIsDead)
		return DEAD_OBJ;

	if(m_iCount%5==0)
		++m_iAniCount;
	++m_iCount;

	IsMoving();
	IsOutRange();

	if (m_iAniCount >= m_AniData.iImageCount)
	{
		m_iAniCount = 0;
	}


	return NO_EVENT;
}

void CItem::Render(HDC hDC)
{
	CGameObject::UpdateRect();

	TransparentBlt(
		hDC, 
		m_tRect.left,					  // Rectangle�� ���� Left��
		m_tRect.top,					  // Rectangle�� ���� Bottom��
		m_tInfo.fCX,					  // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_tInfo.fCY,					  // �ҷ����°�? �̶���ؾ��ϳ� ������ ũ�⿡ �ȸ����� �ðų� �پ����.
		m_Image,						  // �̹��� �ҷ�����
		m_iAniCount*m_AniData.iWarpWidth, // �̹��� ȣ�� ���⼺ X
		0,						          // �̹���ȣ����⼺ Y
		m_AniData.iWarpWidth,  	          // ���������� X
		m_AniData.iHeight,	   	          // ���������� Y
		RGB(255, 255, 255));	          // �������̶� ���� �������.����Ʈ������ ��

}

void CItem::IsOutRange()
{
	CGameObject::UpdateRect();

	if (0 >= m_tRect.left || 0 >= m_tRect.top
		|| WINCX <= m_tRect.right || WINCY <= m_tRect.bottom)
		m_bIsDead = true;

}

void CItem::IsMoving()
{
	m_tInfo.fY +=m_fSpeed;
}

void CItem::SetItemFrame(int _m_iFrame)
{
	m_iFrame = _m_iFrame;
}

void CItem::ItemResult()  // ������ enum�� ���� ��� �ٸ����ϴ� �Լ�.
{

	CGameObject* pUIMgr = CMainGame::GetInstance()->GetScene()->GetOBJLST()[OBJECT_UI].front();
	switch (m_ItemNumber)
	{
	case 0:
		dynamic_cast<CUIMgr*>(pUIMgr)->SetScroe(1000);
		return;
	case 1:
		dynamic_cast<CUIMgr*>(pUIMgr)->SetEnergyBarGague(10);
		return;
	case 2:
		//dynamic_cast<CUIMgr*>(pUIMgr)->SetPlayerBoom(1);
		dynamic_cast<CUIMgr*>(pUIMgr)->SetPlayerBoom(1);
		return;
	default:
		break;
	}
}

void CItem::SetDamaged()
{
	ItemResult();
	SetDead(true);
}


void CItem::Release()
{
	
}
