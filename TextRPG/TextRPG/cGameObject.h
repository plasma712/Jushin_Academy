#pragma once
#include "tagStats.h"

class cGameObject
{
private:
	tagStats Stats;
public:
	cGameObject();
	cGameObject(
		int  _InherentNumber,
		const char* _cName,
		int  _iAtk,
		int  _iDef,
		int  _iHp,
		int  _iMaxHp,
		int  _iLv,
		int  _iExp,
		int  _iGold
	);
	virtual ~cGameObject();
public: // 기본 구조
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	virtual void Release();
public: // 공통 행위
	//void Attack(cGameObject* SetObject, cGameObject* GetObject);


public: //Get 함수
	int  GetInherentNumber();
	char* GetcName();
	int  GetiAtk();
	int  GetiDef();
	int  GetiHp();
	int  GetiMaxHp();
	int  GetiLv();
	int  GetiExp();
	int  GetiGold();
	int  GettagStatsSizeof();
public: // Set 함수 (변수값으로 초기화?)
	void SetInherentNumber(int _InherentNumber);
	void SetcName(char* _cName);
	void SetiAtk(int _iAtk);
	void SetiDef(int _iDef);
	void SetiHp(int _iHp);
	void SetiMaxHp(int _iMaxHp);
	void SetiLv(int _iLv);
	void SetiExp(int _iExp);
	void SetiGold(int _iGold);

};

