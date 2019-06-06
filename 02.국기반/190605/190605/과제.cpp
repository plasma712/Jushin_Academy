/*
	�ؽ�Ʈ RPG �����


	������ �� 3����

	���� ���� ������

	����ü�� ����ٸ�.

	�ɷ�ġ�� ���°� �̿ܿ� �޶����� ����.(�ѹ��� �ϳ��� ĳ����)

	����ü�� ����ٸ�, ���������� �ƿ� 3������ ����ü�� ����°� �ո���.(����⵵ �� ����)

	���� . ���ݷ� . ü�� . �� �⺻ ����.



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

#pragma region ��������;
const int MonsterCount = 3;
bool AttackMostion = false;
bool PlayerLife = true;

#pragma endregion

#pragma region ����ü

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

#pragma region �Լ�����
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

#pragma region ĳ����,���� ���ݼ���
void PlayerProduce(tagPlayer* _tPlayer, int _iSelectNumber)
{
	switch (_iSelectNumber)
	{
	case 1:
		memcpy(_tPlayer->cName, "����", sizeof("����") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
		break;
	case 2:
		memcpy(_tPlayer->cName, "����", sizeof("����") + 1);
		_tPlayer->fAtk = 5.f;
		_tPlayer->fHp = 100.f;
		break;
	case 3:
		memcpy(_tPlayer->cName, "������", sizeof("������") + 1);
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
			memcpy(_tMonster[i].cName, "����������", sizeof("����������") + 1);
			*_tMonster[i].fAtk = 4.f;
			*_tMonster[i].fHp = 10.f;
			break;
		case 2:
			memcpy(_tMonster[i].cName, "������", sizeof("������") + 1);
			*_tMonster[i].fAtk = 8.f;
			*_tMonster[i].fHp = 20.f;
			break;
		case 3:
			memcpy(_tMonster[i].cName, "��Ȳ����", sizeof("��Ȳ����") + 1);
			*_tMonster[i].fAtk = 16.f;
			*_tMonster[i].fHp = 40.f;
			break;
		default:
			break;
		}
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

#pragma region �ؽ�Ʈ �ѷ��ִ� �Լ���.

void Title()
{
	cout << "==========================================" << endl;
	cout << "|     ��    ��    Ʈ     R    P    G     |" << endl;
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
	cout << "| ���ݷ� : " << tPlayer->fAtk << "    		 	 |" << endl;
	cout << "| ü  �� : " << tPlayer->fHp << "    		 	 |" << endl;
	cout << "==========================================" << endl;
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

void StageSelect()
{
	cout << "==========================================" << endl;
	cout << "|     ��     ��     ��     ��     ��     |" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|      1.�ϱ�     2.�߱�     3.���      |" << endl;
	cout << "==========================================" << endl;
	cout << "���� : ";
}

void PlayerMostion()
{
	cout << "1. �����Ѵ�.  2. ��������." << endl;
	cout << "���� : ";
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

	while (true)	// ��������
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

		while (true) // �������� ����
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
