#include "stdafx.h"
#include "cCollsionMgr.h"
#include "cGameObject.h"

cCollsionMgr::cCollsionMgr()
{
}


cCollsionMgr::~cCollsionMgr()
{
}

void cCollsionMgr::CollisionRectObject(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// �� �簢���� �浹�� �˻��ϴ� API �Լ�
			if (IntersectRect(&rc, &(pDest->GetRECT()), &(pSource->GetRECT())))
			{
				pDest->SetHpDecrease(10.f); // �ܼ� �浹�̱⶧����.
			}
		}
	}
}

void cCollsionMgr::CollisionRectBullet(const OBJLIST & dstLst, const OBJLIST & srcLst) // ��ü , �Ѿ�
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// �� �簢���� �浹�� �˻��ϴ� API �Լ�
			if (IntersectRect(&rc, &(pDest->GetRECT()), &(pSource->GetRECT())))
			{
				pDest->SetHpDecrease(pSource->GetAttack()); // �Ѿ˰��ݷ��� �־���
			}
		}
	}

}

void cCollsionMgr::CollisionPlayerWall(const OBJLIST & dstLst, const OBJLIST & srcLst)
{
	float fMoveX = 0.f, fMoveY = 0.f;

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			if (CollisionCheckRect(pDest, pSource, &fMoveX, &fMoveY))
			{
				float fX = pSource->GetINFO().fX;
				float fY = pSource->GetINFO().fY;

				if (fMoveX > fMoveY) // �İ�� ���̰� ª�� ������ �о ��.
				{
					// Y�� �о��
					if (pDest->GetINFO().fY > fY)
					{
						// ���� �о ��.						
						pSource->SetPos(fX, fY - fMoveY);
					}
					else
						pSource->SetPos(fX, fY + fMoveY);
				}
				else
				{
					// X�� �о��
					if (pDest->GetINFO().fX > fX)
					{
						pSource->SetPos(fX - fMoveX, fY);
						
					}
					else
					{
						pSource->SetPos(fX + fMoveX, fY);
					}
				}
			}
		}
	}
}

bool cCollsionMgr::CollisionCheckRect( cGameObject * pDest,  cGameObject * pSource, float * _pMoveX, float * _pMoveY)
{
	float fRadiusX = pDest->GetINFO().fWidthX * 0.5f + pSource->GetINFO().fWidthX * 0.5f;

	float fDistX = fabs(pDest->GetINFO().fX - pSource->GetINFO().fX);

	float fRadiusY = pDest->GetINFO().fHeightY * 0.5f + pSource->GetINFO().fHeightY * 0.5f;

	float fDistY = fabs(pDest->GetINFO().fY - pSource->GetINFO().fY);

	if (fRadiusX >= fDistX && fRadiusY >= fDistY)
	{
		*_pMoveX = fRadiusX - fDistX;
		*_pMoveY = fRadiusY - fDistY;

		return true;
	}

	return false;
}
