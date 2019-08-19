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
			// 두 사각형의 충돌을 검사하는 API 함수
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

void CCollisionManager::CollisionPlayerTerrain(const OBJLIST & _Player, const OBJLIST & _Terrain)
{
}



bool CCollisionManager::CheckSphere(const CGameObject * pDest, const CGameObject * pSource)
{
	// 반지름 합
	float fSumRad = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// 중점 간 거리
	float w = pDest->GetInfo().fX - pSource->GetInfo().fX;
	float h = pDest->GetInfo().fY - pSource->GetInfo().fY;

	// 피타고라스	
	float d = sqrtf(w * w + h * h);

	return d <= fSumRad;
	return false;
}

bool CCollisionManager::CheckRect(const CGameObject* pDest, const CGameObject* pSource,float* pMoveX, float* pMoveY)
{
	// 두 사각형의 X축 가로 반지름 합	
	float fRadiusX = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// 두 사각형의 X축 거리를 절대 값으로 구함.
	// fabs(X): X의 절대 값을 구하는 함수. <math.h>에서 제공.
	float fDistX = fabs(pDest->GetInfo().fX - pSource->GetInfo().fX);

	// 두 사각형의 Y축 세로 반지름 합.
	float fRadiusY = pDest->GetInfo().fCY * 0.5f + pSource->GetInfo().fCY * 0.5f;

	// 두 사각형의 Y축 거리
	float fDistY = fabs(pDest->GetInfo().fY - pSource->GetInfo().fY);

	if (fRadiusX >= fDistX && fRadiusY >= fDistY)
	{
		// 파고든 x, y 깊이
		*pMoveX = fRadiusX - fDistX;
		*pMoveY = fRadiusY - fDistY;

		return true;
	}

	return false;
}
