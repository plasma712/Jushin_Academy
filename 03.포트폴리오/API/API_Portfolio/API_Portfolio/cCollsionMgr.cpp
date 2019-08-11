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
			// 두 사각형의 충돌을 검사하는 API 함수
			if (IntersectRect(&rc, &(pDest->GetRECT()), &(pSource->GetRECT())))
			{
				pDest->SetHpDecrease(10.f); // 단순 충돌이기때문에.
			}
		}
	}
}

void cCollsionMgr::CollisionRectBullet(const OBJLIST & dstLst, const OBJLIST & srcLst) // 객체 , 총알
{
	RECT rc = {};

	for (auto& pDest : dstLst)
	{
		for (auto& pSource : srcLst)
		{
			// BOOL IntersectRect(RECT* pOut, const RECT* pIn1, const RECT* pIn2)
			// 두 사각형의 충돌을 검사하는 API 함수
			if (IntersectRect(&rc, &(pDest->GetRECT()), &(pSource->GetRECT())))
			{
				pDest->SetHpDecrease(pSource->GetAttack()); // 총알공격력을 넣어줌
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

				if (fMoveX > fMoveY) // 파고든 깊이가 짧은 쪽으로 밀어낼 것.
				{
					// Y축 밀어내기
					if (pDest->GetINFO().fY > fY)
					{
						// 위로 밀어낼 것.						
						pSource->SetPos(fX, fY - fMoveY);
					}
					else
						pSource->SetPos(fX, fY + fMoveY);
				}
				else
				{
					// X축 밀어내기
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
