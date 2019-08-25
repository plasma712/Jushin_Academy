#pragma once
#include "Scene.h"
class cStageBossScene :
	public CScene
{
public:
	cStageBossScene();
    ~cStageBossScene();

	// CScene��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void LoadMonster() override;


	float m_iSceneScrolling;

	int m_iSceneChangeKeyValue = 0;
	int GetSceneChangeKeyValue();
	void SetSceneChangeKeyValue(int _KeyValue);
	void CheckAniRoop(OBJLIST& dstLst);

	void vBossCreate();
	bool bfirst;
};

