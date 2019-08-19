#pragma once
#include "Scene.h"
class CEndingScene :
	public CScene
{
public:
	CEndingScene();
	~CEndingScene();

	// CScene을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
	virtual void LoadMonster() override;
};

