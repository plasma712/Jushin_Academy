#include "cMonster.h"
#include "include.h"


cMonster::cMonster()
{
}

cMonster::cMonster(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
	:cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{

}
cMonster::~cMonster()
{
}

void cMonster::Init()
{
	cout << "==========================================" << endl;
	cout << "| ��  �� : " << GetcName() << "    		 	 |" << endl;
	cout << "|     Lv : " << GetiLv() << "    		 	 |" << endl;
	cout << "|    Atk : " << GetiAtk() << "    		 	 |" << endl;
	cout << "|    Def : " << GetiDef() << "    		 	 |" << endl;
	cout << "|     Hp : " << GetiHp() << " / " << GetiMaxHp() << "                       |" << endl;
	cout << "==========================================" << endl;

}

void cMonster::Draw()
{
	cout << "������" << endl;
}

void cMonster::Update()
{
	Init();
}

void cMonster::Release()
{
	cout << "������" << endl;
}

void cMonster::SetConstructor(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
{
	cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold);
}

void cMonster::MonsterStatsSave()
{
	FILE* fp = nullptr;


	//errno_t err = fopen_s(&fp, "../Data/MonsterData.txt", "wb"); // wb = ���� : �����
	errno_t err = fopen_s(&fp, "../Data/MonsterData.txt", "ab"); // ab = ���� : �̾�� appead

	if (err == 0)
	{
		fwrite(&Stats, sizeof(cMonster), 1, fp);
		fclose(fp);
	}
	else
	{
		cout << "���� ���� ����" << endl;
	}
}

void cMonster::MonsterStatsLoad(int _iSelect)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/MonsterData.txt", "rb");

	if (err == 0)
	{
		fseek(fp, sizeof(cMonster)*(_iSelect - 1), SEEK_SET);
		fread(&Stats, sizeof(cMonster), 1, fp);
		fclose(fp);
	}
	else
	{
		cout << "���� �ҷ����� ����" << endl;
	}
}

void cMonster::CreateMonster()
{
	static int InherentNumber = 0;

	if (InherentNumber < 100)
	{
		cMonster* Monster = new cMonster(
			InherentNumber,
			"����",
			1 + 3 * (InherentNumber),
			3,
			20 * (InherentNumber + 1),
			20 * (InherentNumber + 1),
			InherentNumber + 1, 10 * (InherentNumber + 1),
			100 * (InherentNumber + 1)
		);
		Monster->MonsterStatsSave();
		InherentNumber++;
		delete Monster;
	}
	else
	{
		cout << "���� ���� �Ϸ� : " << InherentNumber << endl;
		system("pause");
		return;
	}
	CreateMonster();
}

