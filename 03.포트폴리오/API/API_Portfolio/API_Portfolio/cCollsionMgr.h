#pragma once
class cCollsionMgr
{
public:
	cCollsionMgr();
	~cCollsionMgr();

public:
	
	//static void Collision  
	//1. �÷��̾�� ���� �浹.
	//2. �÷��̾�or���Ϳ� �Ѿ��浹
	//3. �÷��̾��� ��������Ʈ���� �浹.

	static void CollisionRectObject(const OBJLIST& dstLst, const OBJLIST& srcLst);//�÷��̾� ,���� : �÷��̾� ������
	static void CollisionRectBullet(const OBJLIST& dstLst, const OBJLIST& srcLst);//�÷��̾� or ���� �� �Ѿ��浹
	static void CollisionPlayerWall(const OBJLIST& dstLst, const OBJLIST& srcLst);//

public:
	static bool CollisionCheckRect( cGameObject* pDest,  cGameObject* pSource, float* _pMoveX, float* _pMoveY);

};

