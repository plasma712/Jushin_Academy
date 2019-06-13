/*
	텍스트 RPG 만들기


	직업군 총 3가지

	전사 도적 마법사

	구조체로 만든다면.

	능력치를 묶는거 이외에 달라질게 없음.(한번에 하나의 캐릭터)

	구조체로 만든다면, 직업군으로 아예 3가지의 구조체를 만드는게 합리적.(만들기도 더 쉬움)

	직업 . 공격력 . 체력 . 이 기본 사항.



*/

/*
	저장 및 불러올 데이터 생각.

	플레이어 스테이터스

	플레이어 현재 진행도.



	/////////////////////////

	몬스터 LV , EXP , Atk, 수치는 플레이어의 진행도에 따라 변경.

	몬스터 이름은 3가지중 랜덤. (따라서 딱히 저장할 건 없음)





*/

#include <iostream>

using namespace std;

#pragma region 안쓰는 함수(변경or쓸모X)
// void Produce(char* _cName,float* _fAtk,float* _fHp,int _iSelectNumber)
// {
// 	switch (_iSelectNumber)
// 	{
// 	case 1:
// 		memcpy(_cName, "전사", sizeof("전사")+1);
// 		*_fAtk = 5.f;
// 		*_fHp = 100.f;
// 		break;
// 	case 2:
// 		memcpy(_cName, "도적", sizeof("도적") + 1);
// 		*_fAtk = 8.f;
// 		*_fHp = 62.5f;
// 		break;
// 	case 3:
// 		memcpy(_cName, "마법사", sizeof("마법사") + 1);
// 		*_fAtk = 12.5f;
// 		*_fHp = 40.f;
// 		break;
// 	default:
// 		break;
// 	}
// }

#pragma endregion

#pragma region 전역변수 및 Enum;
const int MonsterCount = 3;
bool AttackMostion = false;
bool PlayerLife = true;
bool CharLoadErrorChecking = false;

enum LvDesign
{
	Design_Lv_1 = 10, 
	Design_Lv_2 = 16, 
	Design_Lv_3 = 26, 
	Design_Lv_4 = 42, 
	Design_Lv_5 = 68, 
	Design_Lv_6 = 110,
	Design_Lv_7 = 178,
	Design_Lv_8 = 288
};

enum Lv
{
	Lv_1 = 1,
	Lv_2 = 2,
	Lv_3 = 3,
	Lv_4 = 4,
	Lv_5 = 5,
	Lv_6 = 6,
	Lv_7 = 7,
	Lv_8 = 8
};

#pragma endregion

#pragma region 구조체

struct tagPlayer
{
	char cName[32];
	float fAtk;
	float fHp;
	float fMaxHp;
	float fDef;
	float fSpeed;
	float fExp;
	int iLv;
	bool bPlayerLife = true;
};

struct tagMonster
{
	char cName[MonsterCount][32];
	float fAtk[MonsterCount];
	float fHp[MonsterCount];
	float fDef[MonsterCount];
	float fSpeed[MonsterCount];
	float fExp[MonsterCount];
	float iLv[MonsterCount];
};

#pragma endregion

#pragma region 함수선언
void PlayerProduce(tagPlayer* _tPlayer, int _iSelectNumber);
void MonsterProduce(tagMonster _tMonster[]);
void MonsterProduceRegen(tagMonster _tMonster[], int _iStageIndex);
void PlayerAttack(tagPlayer* _tPlayer, tagMonster _tMonster[], int _StageIndex);
void MonsterAttack(tagMonster _tMonster[], tagPlayer* _tPlayer, int _StageIndex);
void Title();
void PlayerSelect();
void PlayerStats(tagPlayer* tPlayer);
void PlayerDie();
void PlayerRun();
void HuntingSuccess();
void MonsterStats(tagMonster _tMonster[], int _StageIndex);
void StageSelect();
void PlayerMostion();
void AttackFunction(tagPlayer* _tPlayer, tagMonster _tMonster[], int _StageIndex, int _iSelectNumber);
void PlayerStatsSave(tagPlayer* _tPlayer);
void PlayerStatsLoad(tagPlayer* _tPlayer, bool _CharLoadErrorChecking);
void LevelUPChecking(tagPlayer* _tPlayer);
#pragma endregion

#pragma region 캐릭터,몬스터 스텟설정
void PlayerProduce(tagPlayer* _tPlayer, int _iSelectNumber)
{
	switch (_iSelectNumber)
	{
	case 1:
		memcpy(_tPlayer->cName, "전사", sizeof("전사") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
		_tPlayer->fMaxHp = 100.f;
		_tPlayer->fExp = 0.0f;
		_tPlayer->iLv = 1;
		break;
	case 2:
		memcpy(_tPlayer->cName, "도적", sizeof("도적") + 1);
		_tPlayer->fAtk = 7.f;
		_tPlayer->fHp = 80.f;
		_tPlayer->fMaxHp = 80.f;
		_tPlayer->fExp = 0.0f;
		_tPlayer->iLv = 1;
		break;
	case 3:
		memcpy(_tPlayer->cName, "마법사", sizeof("마법사") + 1);
		_tPlayer->fAtk = 10.f;
		_tPlayer->fHp = 50.f;
		_tPlayer->fMaxHp = 50.f;
		_tPlayer->fExp = 0.0f;
		_tPlayer->iLv = 1;
		break;
	default:
		break;
	}
}

void MonsterProduce(tagMonster _tMonster[])
{
	for (int i = 0; i < MonsterCount; i++)
	{
		switch (i + 1)
		{
		case 1:
			memcpy(_tMonster[i].cName, "빨간달팽이", sizeof("빨간달팽이") + 1);
			*_tMonster[i].fAtk = 4.f;
			*_tMonster[i].fHp = 10.f;
			*_tMonster[i].fExp = 10.f;
			break;
		case 2:
			memcpy(_tMonster[i].cName, "슬라임", sizeof("슬라임") + 1);
			*_tMonster[i].fAtk = 8.f;
			*_tMonster[i].fHp = 20.f;
			*_tMonster[i].fExp = 15.f;
			break;
		case 3:
			memcpy(_tMonster[i].cName, "주황버섯", sizeof("주황버섯") + 1);
			*_tMonster[i].fAtk = 16.f;
			*_tMonster[i].fHp = 40.f;
			*_tMonster[i].fExp = 20.f;
			break;
		default:
			break;
		}
	}
}

void MonsterProduceRegen(tagMonster _tMonster[], int _iStageNumber)
{
	if (_iStageNumber == 1)
	{
		memcpy(_tMonster[_iStageNumber - 1].cName, "빨간달팽이", sizeof("빨간달팽이") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 4.f;
		*_tMonster[_iStageNumber - 1].fHp = 10.f;
	}
	else if (_iStageNumber == 2)
	{
		memcpy(_tMonster[_iStageNumber - 1].cName, "슬라임", sizeof("슬라임") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 8.f;
		*_tMonster[_iStageNumber - 1].fHp = 20.f;
	}
	else if (_iStageNumber == 2)
	{
		memcpy(_tMonster[_iStageNumber - 1].cName, "주황버섯", sizeof("주황버섯") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 16.f;
		*_tMonster[_iStageNumber - 1].fHp = 40.f;
	}
	else
	{
		return;
	}

}

#pragma endregion

#pragma region 행동

void PlayerAttack(tagPlayer* _tPlayer, tagMonster _tMonster[], int _StageIndex)
{
	*_tMonster[_StageIndex].fHp -= _tPlayer->fAtk;
	if (*_tMonster[_StageIndex].fHp <= 0)
	{
		AttackMostion = true;
		system("cls");
		if (_tPlayer->bPlayerLife==true)
		{
			HuntingSuccess();
			_tPlayer->fExp += *_tMonster[_StageIndex].fExp;
			LevelUPChecking(_tPlayer);
		}
		system("pause");
		//system("cls");
	}
	else
		return;
}

void MonsterAttack(tagMonster _tMonster[], tagPlayer* _tPlayer, int _StageIndex)
{
	_tPlayer->fHp -= (*_tMonster[_StageIndex].fAtk);
	if (_tPlayer->fHp <= 0)
	{
		AttackMostion = true;
		system("cls");
		PlayerDie();
		_tPlayer->bPlayerLife = false;
		PlayerStatsSave(_tPlayer);
		system("pause");
		/////////////////
	}
	else
		return;
}

void AttackFunction(tagPlayer* _tPlayer, tagMonster _tMonster[], int _StageIndex, int _iSelectNumber)
{
	system("cls");
ReMostion:
	while (AttackMostion == false)
	{
		MonsterStats(_tMonster, _StageIndex - 1);
		PlayerStats(_tPlayer);
		PlayerMostion();
		cin >> _iSelectNumber;
		system("cls");
		if (_iSelectNumber > 0 && _iSelectNumber < 3)
		{
			if (_iSelectNumber == 1)
			{
				//MonsterStats(_tMonster, _StageIndex - 1);
				MonsterAttack(_tMonster, _tPlayer, _StageIndex - 1); // 몬스터부터 하는이유는 레벨업으로 인한 HP상승으로 꼬이는거 방지귀찮아서.
				PlayerAttack(_tPlayer, _tMonster, _StageIndex - 1); 
				PlayerStats(_tPlayer);
				system("cls");
				//system("pause");
			}
			if (_iSelectNumber == 2)
			{
				break;
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			system("cls");
			goto ReMostion;
		}
	}
}

void HuntManage(tagPlayer* _tPlayer, tagMonster _tMonster[], int _iStageIndex, int iSelectNumber)
{
	while (true) // 스테이지 선택
	{
		system("cls");
		StageSelect();
		cin >> _iStageIndex;
		system("cls");
		if (_iStageIndex > 0 && _iStageIndex < 4)
		{
			MonsterStats(_tMonster, _iStageIndex - 1);
			PlayerStats(_tPlayer);
			//system("pause");
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	AttackFunction(_tPlayer, _tMonster, _iStageIndex, iSelectNumber); // 전투
	//MonsterProduce(tMonster);
	MonsterProduceRegen(_tMonster, _iStageIndex);
	AttackMostion = false;
	//system("pause");
}


void LevelUPChecking(tagPlayer* _tPlayer)
{
	switch (_tPlayer->iLv)
	{
	case 1:
		if (_tPlayer->fExp >= Design_Lv_1)
		{
			_tPlayer->fExp -= Design_Lv_1;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 2:
		if (_tPlayer->fExp >= Design_Lv_2)
		{
			_tPlayer->fExp -= Design_Lv_2;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 3:
		if (_tPlayer->fExp >= Design_Lv_3)
		{
			_tPlayer->fExp -= Design_Lv_3;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 4:
		if (_tPlayer->fExp >= Design_Lv_4)
		{
			_tPlayer->fExp -= Design_Lv_4;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 5:
		if (_tPlayer->fExp >= Design_Lv_5)
		{
			_tPlayer->fExp -= Design_Lv_5;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 6:
		if (_tPlayer->fExp >= Design_Lv_6)
		{
			_tPlayer->fExp -= Design_Lv_6;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 7:
		if (_tPlayer->fExp >= Design_Lv_7)
		{
			_tPlayer->fExp -= Design_Lv_7;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	case 8:
		if (_tPlayer->fExp >= Design_Lv_8)
		{
			_tPlayer->fExp -= Design_Lv_8;
			_tPlayer->iLv += 1;
			_tPlayer->fHp = _tPlayer->fMaxHp;
			PlayerStatsSave(_tPlayer);
		}
		break;
	}
}

#pragma endregion

#pragma region 파일입출력

void PlayerStatsSave(tagPlayer* _tPlayer)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "wb");

	if (err == 0)
	{
		// fwrite(&_tPlayer, sizeof(tagPlayer), 1, fp); 이 방식으론 ㄴㄴ
		fwrite(_tPlayer, sizeof(tagPlayer), 1, fp);
		fclose(fp);
	}
	else
		cout << "파일 저장 실패" << endl;
}

void PlayerStatsLoad(tagPlayer* _tPlayer, bool _CharLoadErrorChecking)
{
	FILE* fp = nullptr;

	tagPlayer tPlayer;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "rb");

	if (err == 0)
	{
		fread(&tPlayer, sizeof(tagPlayer), 1, fp);

		memcpy(_tPlayer->cName, tPlayer.cName, sizeof(tPlayer.cName));
		_tPlayer->fAtk = tPlayer.fAtk;
		_tPlayer->fHp = tPlayer.fHp;
		_tPlayer->iLv = tPlayer.iLv;
		_tPlayer->fExp = tPlayer.fExp;
		_tPlayer->bPlayerLife = tPlayer.bPlayerLife;

		//system("pause");
		fclose(fp);
	}
	else
	{
		cout << "파일 불러오기 실패 " << endl;
		_CharLoadErrorChecking = true;
	}
}

#pragma endregion

#pragma region 텍스트 뿌려주는 함수들.

void Title()
{
	cout << "==========================================" << endl;
	cout << "|     텍    스    트     R    P    G     |" << endl;
	cout << "==========================================" << endl;
	cout << "|  1. 새로운 모험.      2.이어서 하기    |" << endl;
	cout << "==========================================" << endl;

}

void PlayerSelect()
{
	cout << "==========================================" << endl;
	cout << "|   1. 전사     2. 도적     3. 마법사	 |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

void PlayerStats(tagPlayer* tPlayer)
{
	cout << "==========================================" << endl;
	cout << "| 직  업 : " << tPlayer->cName << "    		 	 |" << endl;
	cout << "|     Lv : " << tPlayer->iLv << "    		 	 |" << endl;
	cout << "|    Atk : " << tPlayer->fAtk << "    		 	 |" << endl;
	cout << "|     Hp : " << tPlayer->fHp << "    		 	 |" << endl;
	cout << "|    EXP : " << tPlayer->fExp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
}

void PlayerMostion()
{
	cout << "1. 공격한다.  2. 도망간다." << endl;
	cout << "선택 : ";
}

void PlayerDie()
{
	cout << "==========================================" << endl;
	cout << "|    플    레    이    어    사    망    |" << endl;
	cout << "==========================================" << endl;
}

void PlayerRun()
{
	cout << "==========================================" << endl;
	cout << "|    무   사   히   도   망   쳤   다    |" << endl;
	cout << "==========================================" << endl;
}

void HuntingSuccess()
{
	cout << "==========================================" << endl;
	cout << "|      사       냥       성       공     |" << endl;
	cout << "==========================================" << endl;
}

void MonsterStats(tagMonster _tMonster[], int _StageIndex)
{
	cout << "==========================================" << endl;
	cout << "| 이  름 : " << *_tMonster[_StageIndex].cName << "\t\t\t |" << endl;
	cout << "| 공격력 : " << *_tMonster[_StageIndex].fAtk << "    		 	 |" << endl;
	cout << "| 체  력 : " << *_tMonster[_StageIndex].fHp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
}

void SelectMenu()
{
	cout << "==========================================" << endl;
	cout << "|     텍    스    트     R    P    G     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|    1. 사냥하기        2. 캐릭터 상태   |" << endl;
	cout << "|    3. 상    점        4. 저    장      |" << endl;
	cout << "|    5. 종    료                         |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

void StageSelect()
{
	cout << "==========================================" << endl;
	cout << "|     던     전     난     이     도     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|      1.하급     2.중급     3.상급      |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

void Preparing()
{
	cout << "==========================================" << endl;
	cout << "|       준          비          중       |" << endl;
	cout << "==========================================" << endl;
}

void SaveSuccess()
{
	cout << "==========================================" << endl;
	cout << "|      저       장       성       공     |" << endl;
	cout << "==========================================" << endl;
}

#pragma endregion

void main()
{
	// PlayerProduce(&tPlayer, 1);
	// PlayerStats(&tPlayer);
	// MonsterProduce(tMonster);
	// MonsterStats(tMonster,0);
	// 
	// PlayerAttack(&tPlayer, tMonster, 0);
	// MonsterStats(tMonster, 0);
	// 
	// MonsterAttack(tMonster, &tPlayer, 0);
	// PlayerStats(&tPlayer);

	tagPlayer tPlayer = {};
	tagMonster tMonster[3] = {};
	int iSelectNumber = 0;
	int iStageIndex = 0;

TitlePage:			// 나가기   (Goto문)
NewGame:			// 플레이어 사망 or 저장 데이터 없는경우 새로운 시작
	while (true)	// 새로하기 불러오기
	{
	RELOAD:
		system("cls");
		Title();
		//system("pause");
		cout << "선택 : ";
		//cin >> iSelectNumber;
		if (cin >> iSelectNumber)
		{
			while (true)
			{
				if (iSelectNumber > 0 && iSelectNumber < 3)
				{
					switch (iSelectNumber)
					{
					case 1:
						while (true)	// 직업선택
						{
							system("cls");
							PlayerSelect();
							if (cin >> iSelectNumber)
							{
								system("cls");
								if (iSelectNumber > 0 && iSelectNumber < 4)
								{
									PlayerProduce(&tPlayer, iSelectNumber);
									PlayerStats(&tPlayer);
									PlayerStatsSave(&tPlayer);
									system("pause");
									goto SelectcharSuccess;
								}
							}
							else
							{
								cin.clear();
								cin.ignore(256, '\n');
							}
						}
						break;
					case 2:
						PlayerStatsLoad(&tPlayer, CharLoadErrorChecking);
						if (CharLoadErrorChecking == true)
						{
							CharLoadErrorChecking = false;
							goto RELOAD;
						}
						goto JumpSelectChar;
					}
				}
				else
				{
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

#pragma region 질문하기

	// PlayerSelectReturn:
	// while (true)
	// {
	// 	PlayerSelect();
	// 	cin >> iSelectNumber;
	// 	if (iSelectNumber > 0 && iSelectNumber < 3)
	// 	{
	// 		PlayerProduce(&tPlayer,iSelectNumber);
	// 		break;
	// 	}
	// 	else
	// 	{
	// 		cout << "들어오나?" << endl;
	// 		system("pause");
	// 		memset(&iSelectNumber, 0, sizeof(iSelectNumber));
	// 		cout << iSelectNumber << endl;
	// 		goto PlayerSelectReturn;
	// 	}
	// }
#pragma endregion

JumpSelectChar:			// 불러오기 (Goto문)  
SelectcharSuccess:		// 직업선택 (Goto문)
	MonsterProduce(tMonster);

	while (true)
	{
		if (tPlayer.bPlayerLife == true)
		{
			system("cls");
			SelectMenu();
			if (cin >> iSelectNumber)
			{
				if (iSelectNumber > 0 && iSelectNumber < 6)
				{
					switch (iSelectNumber)
					{
					case 1:
						HuntManage(&tPlayer, tMonster, iStageIndex, iSelectNumber);	//사냥쪽
						break;
					case 2:
						system("cls");
						PlayerStats(&tPlayer);
						system("pause");
						break;
					case 3:
						system("cls");
						Preparing();	// 상점
						system("pause");
						break;
					case 4:
						system("cls");
						PlayerStatsSave(&tPlayer);
						SaveSuccess();
						system("pause");
						system("cls");
					case 5:
						PlayerStatsSave(&tPlayer);
						goto TitlePage;
						system("cls");
					}
				}
				else
				{
					cin.clear();
					cin.ignore(256, '\n');
				}
			}
			else
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
		}
		else
		{
			system("cls");
			//cout << tPlayer.bPlayerLife << endl;
			cout << "새로운 게임을 선택 해주세요." << endl;
			system("pause");
			system("cls");
			goto NewGame;
		}
	}

	return;
}
