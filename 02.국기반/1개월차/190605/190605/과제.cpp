/*
	�ؽ�Ʈ RPG �����


	������ �� 3����

	���� ���� ������

	����ü�� ����ٸ�.

	�ɷ�ġ�� ���°� �̿ܿ� �޶����� ����.(�ѹ��� �ϳ��� ĳ����)

	����ü�� ����ٸ�, ���������� �ƿ� 3������ ����ü�� ����°� �ո���.(����⵵ �� ����)

	���� . ���ݷ� . ü�� . �� �⺻ ����.



*/

/*
	���� �� �ҷ��� ������ ����.

	�÷��̾� �������ͽ�

	�÷��̾� ���� ���൵.



	/////////////////////////

	���� LV , EXP , Atk, ��ġ�� �÷��̾��� ���൵�� ���� ����.

	���� �̸��� 3������ ����. (���� ���� ������ �� ����)





*/

#include <iostream>

using namespace std;

#pragma region �Ⱦ��� �Լ�(����or����X)
// void Produce(char* _cName,float* _fAtk,float* _fHp,int _iSelectNumber)
// {
// 	switch (_iSelectNumber)
// 	{
// 	case 1:
// 		memcpy(_cName, "����", sizeof("����")+1);
// 		*_fAtk = 5.f;
// 		*_fHp = 100.f;
// 		break;
// 	case 2:
// 		memcpy(_cName, "����", sizeof("����") + 1);
// 		*_fAtk = 8.f;
// 		*_fHp = 62.5f;
// 		break;
// 	case 3:
// 		memcpy(_cName, "������", sizeof("������") + 1);
// 		*_fAtk = 12.5f;
// 		*_fHp = 40.f;
// 		break;
// 	default:
// 		break;
// 	}
// }

#pragma endregion

#pragma region �������� �� Enum;
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

#pragma region ����ü

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

#pragma region �Լ�����
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

#pragma region ĳ����,���� ���ݼ���
void PlayerProduce(tagPlayer* _tPlayer, int _iSelectNumber)
{
	switch (_iSelectNumber)
	{
	case 1:
		memcpy(_tPlayer->cName, "����", sizeof("����") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
		_tPlayer->fMaxHp = 100.f;
		_tPlayer->fExp = 0.0f;
		_tPlayer->iLv = 1;
		break;
	case 2:
		memcpy(_tPlayer->cName, "����", sizeof("����") + 1);
		_tPlayer->fAtk = 7.f;
		_tPlayer->fHp = 80.f;
		_tPlayer->fMaxHp = 80.f;
		_tPlayer->fExp = 0.0f;
		_tPlayer->iLv = 1;
		break;
	case 3:
		memcpy(_tPlayer->cName, "������", sizeof("������") + 1);
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
			memcpy(_tMonster[i].cName, "����������", sizeof("����������") + 1);
			*_tMonster[i].fAtk = 4.f;
			*_tMonster[i].fHp = 10.f;
			*_tMonster[i].fExp = 10.f;
			break;
		case 2:
			memcpy(_tMonster[i].cName, "������", sizeof("������") + 1);
			*_tMonster[i].fAtk = 8.f;
			*_tMonster[i].fHp = 20.f;
			*_tMonster[i].fExp = 15.f;
			break;
		case 3:
			memcpy(_tMonster[i].cName, "��Ȳ����", sizeof("��Ȳ����") + 1);
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
		memcpy(_tMonster[_iStageNumber - 1].cName, "����������", sizeof("����������") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 4.f;
		*_tMonster[_iStageNumber - 1].fHp = 10.f;
	}
	else if (_iStageNumber == 2)
	{
		memcpy(_tMonster[_iStageNumber - 1].cName, "������", sizeof("������") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 8.f;
		*_tMonster[_iStageNumber - 1].fHp = 20.f;
	}
	else if (_iStageNumber == 2)
	{
		memcpy(_tMonster[_iStageNumber - 1].cName, "��Ȳ����", sizeof("��Ȳ����") + 1);
		*_tMonster[_iStageNumber - 1].fAtk = 16.f;
		*_tMonster[_iStageNumber - 1].fHp = 40.f;
	}
	else
	{
		return;
	}

}

#pragma endregion

#pragma region �ൿ

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
				MonsterAttack(_tMonster, _tPlayer, _StageIndex - 1); // ���ͺ��� �ϴ������� ���������� ���� HP������� ���̴°� ���������Ƽ�.
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
	while (true) // �������� ����
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

	AttackFunction(_tPlayer, _tMonster, _iStageIndex, iSelectNumber); // ����
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

#pragma region ���������

void PlayerStatsSave(tagPlayer* _tPlayer)
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "../Data/PlayerData.txt", "wb");

	if (err == 0)
	{
		// fwrite(&_tPlayer, sizeof(tagPlayer), 1, fp); �� ������� ����
		fwrite(_tPlayer, sizeof(tagPlayer), 1, fp);
		fclose(fp);
	}
	else
		cout << "���� ���� ����" << endl;
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
		cout << "���� �ҷ����� ���� " << endl;
		_CharLoadErrorChecking = true;
	}
}

#pragma endregion

#pragma region �ؽ�Ʈ �ѷ��ִ� �Լ���.

void Title()
{
	cout << "==========================================" << endl;
	cout << "|     ��    ��    Ʈ     R    P    G     |" << endl;
	cout << "==========================================" << endl;
	cout << "|  1. ���ο� ����.      2.�̾ �ϱ�    |" << endl;
	cout << "==========================================" << endl;

}

void PlayerSelect()
{
	cout << "==========================================" << endl;
	cout << "|   1. ����     2. ����     3. ������	 |" << endl;
	cout << "==========================================" << endl;
	cout << "���� : ";
}

void PlayerStats(tagPlayer* tPlayer)
{
	cout << "==========================================" << endl;
	cout << "| ��  �� : " << tPlayer->cName << "    		 	 |" << endl;
	cout << "|     Lv : " << tPlayer->iLv << "    		 	 |" << endl;
	cout << "|    Atk : " << tPlayer->fAtk << "    		 	 |" << endl;
	cout << "|     Hp : " << tPlayer->fHp << "    		 	 |" << endl;
	cout << "|    EXP : " << tPlayer->fExp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
}

void PlayerMostion()
{
	cout << "1. �����Ѵ�.  2. ��������." << endl;
	cout << "���� : ";
}

void PlayerDie()
{
	cout << "==========================================" << endl;
	cout << "|    ��    ��    ��    ��    ��    ��    |" << endl;
	cout << "==========================================" << endl;
}

void PlayerRun()
{
	cout << "==========================================" << endl;
	cout << "|    ��   ��   ��   ��   ��   ��   ��    |" << endl;
	cout << "==========================================" << endl;
}

void HuntingSuccess()
{
	cout << "==========================================" << endl;
	cout << "|      ��       ��       ��       ��     |" << endl;
	cout << "==========================================" << endl;
}

void MonsterStats(tagMonster _tMonster[], int _StageIndex)
{
	cout << "==========================================" << endl;
	cout << "| ��  �� : " << *_tMonster[_StageIndex].cName << "\t\t\t |" << endl;
	cout << "| ���ݷ� : " << *_tMonster[_StageIndex].fAtk << "    		 	 |" << endl;
	cout << "| ü  �� : " << *_tMonster[_StageIndex].fHp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
}

void SelectMenu()
{
	cout << "==========================================" << endl;
	cout << "|     ��    ��    Ʈ     R    P    G     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|    1. ����ϱ�        2. ĳ���� ����   |" << endl;
	cout << "|    3. ��    ��        4. ��    ��      |" << endl;
	cout << "|    5. ��    ��                         |" << endl;
	cout << "==========================================" << endl;
	cout << "���� : ";
}

void StageSelect()
{
	cout << "==========================================" << endl;
	cout << "|     ��     ��     ��     ��     ��     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|      1.�ϱ�     2.�߱�     3.���      |" << endl;
	cout << "==========================================" << endl;
	cout << "���� : ";
}

void Preparing()
{
	cout << "==========================================" << endl;
	cout << "|       ��          ��          ��       |" << endl;
	cout << "==========================================" << endl;
}

void SaveSuccess()
{
	cout << "==========================================" << endl;
	cout << "|      ��       ��       ��       ��     |" << endl;
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

TitlePage:			// ������   (Goto��)
NewGame:			// �÷��̾� ��� or ���� ������ ���°�� ���ο� ����
	while (true)	// �����ϱ� �ҷ�����
	{
	RELOAD:
		system("cls");
		Title();
		//system("pause");
		cout << "���� : ";
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
						while (true)	// ��������
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

#pragma region �����ϱ�

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
	// 		cout << "������?" << endl;
	// 		system("pause");
	// 		memset(&iSelectNumber, 0, sizeof(iSelectNumber));
	// 		cout << iSelectNumber << endl;
	// 		goto PlayerSelectReturn;
	// 	}
	// }
#pragma endregion

JumpSelectChar:			// �ҷ����� (Goto��)  
SelectcharSuccess:		// �������� (Goto��)
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
						HuntManage(&tPlayer, tMonster, iStageIndex, iSelectNumber);	//�����
						break;
					case 2:
						system("cls");
						PlayerStats(&tPlayer);
						system("pause");
						break;
					case 3:
						system("cls");
						Preparing();	// ����
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
			cout << "���ο� ������ ���� ���ּ���." << endl;
			system("pause");
			system("cls");
			goto NewGame;
		}
	}

	return;
}
