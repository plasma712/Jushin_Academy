#include "cPlayer.h"
#include "include.h"

cPlayer::cPlayer()
{
}

cPlayer::cPlayer(int _InherentNumber, const char * _cName, int _iAtk, int _iDef, int _iHp, int _iMaxHp, int _iLv, int _iExp, int _iGold)
	:cGameObject(_InherentNumber, _cName, _iAtk, _iDef, _iHp, _iMaxHp, _iLv, _iExp, _iGold)
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::Init()
{
	cout << "==========================================" << endl;
	cout << "| 직  업 : " << GetcName() << "    		 	 |" << endl;
	cout << "|     Lv : " << GetiLv() << "    		 	 |" << endl;
	cout << "|    Atk : " << GetiAtk() << "    		 	 |" << endl;
	cout << "|    Def : " << GetiDef() << "    		 	 |" << endl;
	cout << "|     Hp : " << GetiHp() << " / " << GetiMaxHp()<< "                       |" << endl;
	cout << "|    EXP : " << GetiExp() << "    		 	 |" << endl;
	cout << "| 소지금 : " << GetiGold() << "    		 	 |" << endl;
	cout << "==========================================" << endl;
}

void cPlayer::Draw()
{
	cout << "재정의" << endl;
}

void cPlayer::Update()
{
	Init();
	//CoreStats();
}

void cPlayer::Release()
{
	cout << "재정의" << endl;
}

void cPlayer::CoreStats()
{
	GetiAtk();
	GetiDef();
	GetiHp();
	GetiMaxHp();
	GetiLv();
	GetiExp();
	GetiGold();
}

void cPlayer::LevelUp()
{
	//Stats.iMaxExp = pow(Stats.iLv, Stats.iLv)*10;
	LevelDesignCheck(Stats.iLv);
	if (Stats.iExp >= Stats.iMaxExp)
	{
		Stats.iExp -= Stats.iMaxExp;
		Stats.iLv++;
		Stats.iAtk += 5;
		Stats.iDef++;
		Stats.iMaxHp += 20;
		Stats.iHp = Stats.iMaxHp;
		PlayerStatsSave();
	}
	else
		return;

	LevelUp();

}

void cPlayer::LevelDesignCheck(int _PlayerLv)
{
	switch (_PlayerLv)
	{
	case 1:
		Stats.iMaxExp = Design_Lv_1;
		break;
	case 2:
		Stats.iMaxExp = Design_Lv_2;
		break;
	case 3:
		Stats.iMaxExp = Design_Lv_3;
		break;
	case 4:
		Stats.iMaxExp = Design_Lv_4;
		break;
	case 5:
		Stats.iMaxExp = Design_Lv_5;
		break;
	case 6:
		Stats.iMaxExp = Design_Lv_6;
		break;
	case 7:
		Stats.iMaxExp = Design_Lv_7;
		break;
	case 8:
		Stats.iMaxExp = Design_Lv_8;
		break;
	default:
		break;
	}
}

void cPlayer::PlayerStatsSave()
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "wb");

	if (err == 0)
	{
		// fwrite(&_tPlayer, sizeof(tagPlayer), 1, fp); 이 방식으론 ㄴㄴ
		fwrite(&Stats, sizeof(cPlayer), 1, fp);
		fclose(fp);
	}
	else
		cout << "파일 저장 실패" << endl;
}

void cPlayer::PlayerStatsLoad()
{
	FILE* fp = nullptr;

	//cPlayer Player;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "rb");

	if (err == 0)
	{
		fread(&Stats, sizeof(cPlayer), 1, fp);

		//_Player->SetcName(Player.GetcName());
		//_Player->SetiAtk(Player.GetiAtk());
		//_Player->SetiHp(Player.GetiHp());
		//_Player->SetiMaxHp(Player.GetiMaxHp());
		//_Player->SetiLv(Player.GetiLv());
		//_Player->SetiExp(Player.GetiExp());
		//_Player->SetiDef(Player.GetiDef());
		//_Player->SetiGold(Player.GetiGold());
		//_Player->SetInherentNumber(Player.GetInherentNumber());

		//system("pause");
		fclose(fp);
	}
	else
	{
		cout << "파일 불러오기 실패 " << endl;
		//_CharLoadErrorChecking = true;
	}

}
