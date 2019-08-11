#pragma once
class cCollsionMgr
{
public:
	cCollsionMgr();
	~cCollsionMgr();

public:
	
	//static void Collision  
	//1. 플레이어와 몬스터 충돌.
	//2. 플레이어or몬스터와 총알충돌
	//3. 플레이어의 벽오브젝트와의 충돌.

	static void CollisionRectObject(const OBJLIST& dstLst, const OBJLIST& srcLst);//플레이어 ,몬스터 : 플레이어 데미지
	static void CollisionRectBullet(const OBJLIST& dstLst, const OBJLIST& srcLst);//플레이어 or 몬스터 과 총알충돌
	static void CollisionPlayerWall(const OBJLIST& dstLst, const OBJLIST& srcLst);//

public:
	static bool CollisionCheckRect( cGameObject* pDest,  cGameObject* pSource, float* _pMoveX, float* _pMoveY);

};

