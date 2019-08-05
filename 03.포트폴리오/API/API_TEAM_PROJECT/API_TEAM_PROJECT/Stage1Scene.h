#pragma once
#include "Scene.h"

class CStage1Scene:public CScene
{
public:
	CStage1Scene();
	~CStage1Scene();

	// CScene��(��) ���� ��ӵ�
public:
	virtual void	Initialize();
	virtual void	Update() override;
	virtual void	Render() override;

private:
	virtual void	Release() override;

private:
	int	m_iProgress;
	
	int m_iSceneScrollSpeed = 5;
	int m_iSceneScrolling1;	// ����ũ��
	int m_iSceneScrolling2;	// ����ũ��

	int m_iSceneChangeKeyValue = 0;

	//OBJLIST	m_ObjLst[OBJECT_END];
	OBJLIST m_TmpLst;
	// CScene��(��) ���� ��ӵ�
	virtual void LoadMonster() override;

	void BackGroundRenderCheck(int _KeyValue);

public:
	int GetSceneChangeKeyValue();
	void SetSceneChangeKeyValue(int _KeyValue);
	void CheckAniRoop(OBJLIST& dstLst);

	//CUIMgr* UImgr;
///////////////////
	
};

