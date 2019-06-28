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
public: // �⺻ ����
	virtual void Init();
	virtual void Draw();
	virtual void Update();
	virtual void Release();
public: // ���� ����
	//void Attack(cGameObject* SetObject, cGameObject* GetObject);


public: //Get �Լ�
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
public: // Set �Լ� (���������� �ʱ�ȭ?)
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

