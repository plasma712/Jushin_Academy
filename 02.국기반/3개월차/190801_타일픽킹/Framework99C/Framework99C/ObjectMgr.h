#pragma once

// ���� ���� ������Ʈ�� �����ϴ� ������

// ������ ���� (�޵����� ����)
// M : N ���� ��ȣ ���⼺�� M : 1�� ���ߴ� ������ ����. 
// ��� ������Ʈ���� ���θ� ���� �����ڸ� �˸� ��ȣ�ۿ� ó���� �� �ִ�.

class CGameObject;
class CObjectMgr
{
	DECLARE_SINGLETON(CObjectMgr)

private:
	CObjectMgr();
	~CObjectMgr();
	
public:
	CGameObject* GetPlayer() const;
	CGameObject* GetMouse() const;
	CGameObject* GetBackGround() const;
	CGameObject* GetNearTarget(CGameObject* pSrc, OBJECT_TYPE eType);

public:
	void AddObject(OBJECT_TYPE eType, CGameObject* pObject);
	void Update();
	void Render(HDC hDC);
	void ReleaseGroup(OBJECT_TYPE eType);
	
private:
	void Release();

private:
	OBJLIST	m_ObjLst[OBJECT_END];
	int		m_iEvent;
};

