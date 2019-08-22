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

void CCollisionManager::CollisionPlayerTerrain(const OBJLIST & _Player, const OBJLIST & _Terrain)
{
	float fMoveX = 0.f, fMoveY = 0.f;

	for (auto& pDest : _Terrain)
	{
		for (auto& pSource : _Player)
		{
			if (CheckRect(pDest, pSource, &fMoveX, &fMoveY))
			{
				float fX = pSource->GetInfo().fX;
				float fY = pSource->GetInfo().fY;

				if (fMoveX > fMoveY) // �İ�� ���̰� ª�� ������ �о ��.
				{
					// Y�� �о��
					if (pDest->GetInfo().fY > fY)
					{
						// ���� �о ��.						
						pSource->SetPos(fX, fY - fMoveY);
					}
					else
						pSource->SetPos(fX, fY + fMoveY);
				}
				else
				{
					//// X�� �о��
					//if (pDest->GetInfo().fX > fX)
					//	pSource->SetPos(fX - fMoveX, fY);
					//else
					//	pSource->SetPos(fX + fMoveX, fY);
				}
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

bool CCollisionManager::CheckRect(const CGameObject* pDest, const CGameObject* pSource,float* pMoveX, float* pMoveY)
{
	// �� �簢���� X�� ���� ������ ��	
	float fRadiusX = pDest->GetInfo().fCX * 0.5f + pSource->GetInfo().fCX * 0.5f;

	// �� �簢���� X�� �Ÿ��� ���� ������ ����.
	// fabs(X): X�� ���� ���� ���ϴ� �Լ�. <math.h>���� ����.
	float fDistX = fabs(pDest->GetInfo().fX - pSource->GetInfo().fX);

	// �� �簢���� Y�� ���� ������ ��.
	float fRadiusY = pDest->GetInfo().fCY * 0.5f + pSource->GetInfo().fCY * 0.5f;

	// �� �簢���� Y�� �Ÿ�
	float fDistY = fabs(pDest->GetInfo().fY - pSource->GetInfo().fY);

	if (fRadiusX >= fDistX && fRadiusY >= fDistY)
	{
		// �İ�� x, y ����
		*pMoveX = fRadiusX - fDistX;
		*pMoveY = fRadiusY - fDistY;

		return true;
	}

	return false;
}
