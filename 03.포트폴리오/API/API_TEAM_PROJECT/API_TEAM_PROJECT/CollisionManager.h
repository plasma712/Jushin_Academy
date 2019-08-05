#pragma once
class CCollisionManager
{
public:
	CCollisionManager();
	~CCollisionManager();
public:
	static void CollisionRect(const OBJLIST& dstLst, const OBJLIST& srcLst);
	static void CollisionSphere(const OBJLIST& dstLst, const OBJLIST& srcLst);
	static void CollisionSphere_Item(const OBJLIST& dstLst, const OBJLIST& srcLst);
	static void CollisionSphereToMonster(const OBJLIST & dstLst, const OBJLIST & srcLst);

private:
	static bool CheckSphere(const CGameObject* pDest, const CGameObject* pSource);
};

