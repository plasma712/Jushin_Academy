#pragma once
class cGameObject;

class cField
{
public:
	cGameObject* Player;
	cGameObject* Monster;
	int iSelect;
public:
	void Init();
	void Draw();
	void Update();
	void Release();
public:
	cField();
	~cField();
public:
	void Receive(cGameObject* _Player);
	cGameObject* ExtractPlayer();	// 플레이어 주소 추출

public:
	void Battle();
	void AttackFormula(cGameObject * _To, cGameObject * _From);
	bool CheckingDie(cGameObject* _Player, cGameObject* _Monster);
public:
	void SelectFieldLevel();
	void Reward(cGameObject* _Player, cGameObject* _Monster);

};

