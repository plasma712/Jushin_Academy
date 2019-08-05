#include "stdafx.h"
#include "CollisionManager.h"
#include "EffectManager.h"
#include "GameObject.h"
#include "Item.h"

CCollisionManager::CCollisionManager()
{
}


CCollisionManager::~CCollisionManager()
{
}

void CCollisionManager::CollisionRect(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// �� �簢���� �浹�� �˻��ϴ� API �Լ�
			if (IntersectRect(&rc, &(pDest->GetRect()), &(pSource->GetRect())))
			{
				pDest->SetDamaged();
				pSource->SetDamaged();
			}
		}
	}
}

void CCollisionManager::CollisionSphere(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			if (CheckSphere(pDest, pSource))
			{
				pDest->SetDamaged();
				pSource->SetDamaged();
			

			}
		}
	}
}

void CCollisionManager::CollisionSphere_Item(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			if (CheckSphere(pDest, pSource))
			{
				pSource->SetDamaged();
			}
		}
	}
}

void CCollisionManager::CollisionSphereToMonster(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			if (CheckSphere(pDest, pSource))
			{
				pDest->SetDamaged();
				pSource->SetDamaged();
				CEffectManager::CreateEffect(pSource->GetInfo().fX, pSource->GetInfo().fY, L"BulletEffect");
			}
		}
	}
}



bool CCollisionManager::CheckSphere(const CGameObject * pDest, const CGameObject * pSource)
{
	// ������ ��
	float fSumRad = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// ���� �� �Ÿ�
	float w = pDest->GetInfo().fX - pSource->GetInfo().fX;
	float h = pDest->GetInfo().fY - pSource->GetInfo().fY;

	// ��Ÿ���	
	float d = sqrtf(w * w + h * h);

	return d <= fSumRad;
	return false;
}
