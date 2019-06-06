/*
	텍스트 RPG 만들기


	직업군 총 3가지

	전사 도적 마법사

	구조체로 만든다면.

	능력치를 묶는거 이외에 달라질게 없음.(한번에 하나의 캐릭터)

	구조체로 만든다면, 직업군으로 아예 3가지의 구조체를 만드는게 합리적.(만들기도 더 쉬움)

	직업 . 공격력 . 체력 . 이 기본 사항.



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

#pragma region 전역변수;
const int MonsterCount = 3;
bool AttackMostion = false;
bool PlayerLife = true;

#pragma endregion

#pragma region 구조체

struct tagPlayer
{
	char cName[32];
	float fAtk;
	float fHp;
	float fDef;
	float fSpeed;
};

struct tagMonster
{
	char cName[MonsterCount][32];
	float fAtk[MonsterCount];
	float fHp[MonsterCount];
	float fDef[MonsterCount];
	float fSpeed[MonsterCount];
};

#pragma endregion

#pragma region 함수선언
void PlayerProduce(tagPlayer* _tPlayer, int _iSelectNumber);
void MonsterProduce(tagMonster _tMonster[]);
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
		break;
	case 2:
		memcpy(_tPlayer->cName, "도적", sizeof("도적") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
		break;
	case 3:
		memcpy(_tPlayer->cName, "마법사", sizeof("마법사") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
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
			break;
		case 2:
			memcpy(_tMonster[i].cName, "슬라임", sizeof("슬라임") + 1);
			*_tMonster[i].fAtk = 8.f;
			*_tMonster[i].fHp = 20.f;
			break;
		case 3:
			memcpy(_tMonster[i].cName, "주황버섯", sizeof("주황버섯") + 1);
			*_tMonster[i].fAtk = 16.f;
			*_tMonster[i].fHp = 40.f;
			break;
		default:
			break;
		}
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
		HuntingSuccess();
		system("pause");
		system("cls");
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
		PlayerLife = false;
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
	while (AttackMostion==false)
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
				PlayerAttack(_tPlayer, _tMonster, _StageIndex - 1);
				MonsterAttack(_tMonster, _tPlayer, _StageIndex - 1);
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

#pragma endregion

#pragma region 텍스트 뿌려주는 함수들.

void Title()
{
	cout << "==========================================" << endl;
	cout << "|     텍    스    트     R    P    G     |" << endl;
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
	cout << "| 공격력 : " << tPlayer->fAtk << "    		 	 |" << endl;
	cout << "| 체  력 : " << tPlayer->fHp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
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

void StageSelect()
{
	cout << "==========================================" << endl;
	cout << "|     던     전     난     이     도     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|      1.하급     2.중급     3.상급      |" << endl;
	cout << "==========================================" << endl;
	cout << "선택 : ";
}

void PlayerMostion()
{
	cout << "1. 공격한다.  2. 도망간다." << endl;
	cout << "선택 : ";
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
	int iStageNumber = 0;

	Title();
	system("pause");
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

	while (true)	// 직업선택
	{
		system("cls");
		PlayerSelect();
		cin >> iSelectNumber;
		system("cls");
		if (iSelectNumber > 0 && iSelectNumber < 4)
		{
			PlayerProduce(&tPlayer, iSelectNumber);
			PlayerStats(&tPlayer);
			system("pause");
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	}

	MonsterProduce(tMonster);

	while (PlayerLife==true)
	{

		while (true) // 스테이지 선택
		{
			system("cls");
			StageSelect();
			cin >> iStageNumber;
			system("cls");
			if (iStageNumber > 0 && iStageNumber < 4)
			{
				MonsterStats(tMonster, iStageNumber - 1);
				PlayerStats(&tPlayer);
				//system("pause");
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(256, '\n');
			}
		}

		AttackFunction(&tPlayer, tMonster, iStageNumber, iSelectNumber);
		MonsterProduce(tMonster);
		AttackMostion = false;
	}
	return;
}
