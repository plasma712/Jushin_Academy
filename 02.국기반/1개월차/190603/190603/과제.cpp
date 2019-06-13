#include <iostream>

using namespace std;

const int MonsterCount = 5;
const int iMax_Str = 32;

struct tagGrade
{
	char cName[MonsterCount][iMax_Str];
	int iKorean[MonsterCount];
	int iEnglish[MonsterCount];
	int iMath[MonsterCount];
	int iTotal[MonsterCount];
	float fAverage[MonsterCount];
};

bool Less(float a, float b) // ��������
{
	return a > b;
}

bool Greater(float a, float b) // ��������
{
	return a < b;
}

void InputGrade(tagGrade* tGrade, int* pCur_Index);
void PrintGrade(tagGrade* tGrade, int* pCur_Index);
void SearchGrade(tagGrade* tGrade, int* pCur_Index);
void RemoveGrade(tagGrade* tGrade, int* pCur_Index);
void BubbleSort(tagGrade* tGrade, int* pCur_Index);

void InputGrade(tagGrade* tGrade, int* pCur_Index)
{
	if (MonsterCount == *pCur_Index)
	{
		cout << "�� �̻� �Է��� �� �����ϴ�." << endl;
		system("pause");
		return;
	}

	cout << "�л� �̸� �Է�: ";
	cin >> tGrade->cName[*pCur_Index]; 

	cout << "���� ���� �Է�: ";
	cin >> tGrade->iKorean[*pCur_Index];

	cout << "���� ���� �Է�: ";
	cin >> tGrade->iEnglish[*pCur_Index];

	cout << "���� ���� �Է�: ";
	cin >> tGrade->iMath[*pCur_Index];

	tGrade->iTotal[*pCur_Index] = tGrade->iKorean[*pCur_Index] + tGrade->iEnglish[*pCur_Index] + tGrade->iMath[*pCur_Index];
	tGrade->fAverage[*pCur_Index] = float(tGrade->iTotal[*pCur_Index]) / 3;

	++(*pCur_Index);
}

void PrintGrade(tagGrade* tGrade, int* pCur_Index)
{
	system("cls");

	for (int i = 0; i < *pCur_Index; ++i)
	{
		cout << "�̸�: " << tGrade->cName[i] << endl;
		cout << "����: " << tGrade->iKorean[i] << endl;
		cout << "����: " << tGrade->iEnglish[i] << endl;
		cout << "����: " << tGrade->iMath[i] << endl;
		cout << "����: " << tGrade->iTotal[i] << endl;
		cout << "���: " << tGrade->fAverage[i] << endl;
		cout << "-----------------------------" << endl;
	}

	system("pause");
}

void SearchGrade(tagGrade* tGrade, int* pCur_Index)
{
	system("cls");

	char szSearch[iMax_Str] = "";

	cout << "�˻�: ";
	cin >> szSearch;

	for (int i = 0; i < *pCur_Index; ++i)
	{
		if (!strcmp(szSearch, tGrade->cName[i]))
		{
			cout << "�̸�: " << tGrade->cName[i] << endl;
			cout << "����: " << tGrade->cName[i] << endl;
			cout << "����: " << tGrade->iKorean[i] << endl;
			cout << "����: " << tGrade->iEnglish[i] << endl;
			cout << "����: " << tGrade->iMath[i] << endl;
			cout << "���: " << tGrade->iTotal[i] << endl;
			cout << "-----------tGrade->fAverage[------------------" << endl;
			system("pause");
			return;
		}
	}

	cout << "�˻� ����� �����ϴ�." << endl;
	system("pause");
}

void RemoveGrade(tagGrade* tGrade, int* pCur_Index)
{
	system("cls");

	char szSearch[iMax_Str] = "";

	cout << "�˻�: ";
	cin >> szSearch;

	for (int i = 0; i < *pCur_Index; ++i)
	{
		if (!strcmp(szSearch, tGrade->cName[i]))
		{
			int iRemoveLen = (*pCur_Index) - i - 1;

			memmove(tGrade->cName + i, tGrade->cName + (i + 1), iMax_Str * iRemoveLen);
			memmove(tGrade->iKorean + i, tGrade->iKorean + (i + 1), sizeof(int) * iRemoveLen);
			memmove(tGrade->iEnglish + i, tGrade->iEnglish + (i + 1), sizeof(int) * iRemoveLen);
			memmove(tGrade->iMath + i, tGrade->iMath + (i + 1), sizeof(int) * iRemoveLen);
			memmove(tGrade->iTotal + i, tGrade->iTotal + (i + 1), sizeof(int) * iRemoveLen);
			memmove(tGrade->fAverage + i, tGrade->fAverage + (i + 1), sizeof(float) * iRemoveLen);
			--(*pCur_Index);
			return;
		}
	}

	cout << "�˻� ����� �����ϴ�." << endl;
	system("pause");
}

void BubbleSort(tagGrade* tGrade, int* pCur_Index)
{
	system("cls");

	bool(*pFunc)(float, float) = nullptr;
	int iSelect = 0;

	cout << "1.�������� 2.��������" << endl;
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		pFunc = Less;
		break;
	case 2:
		pFunc = Greater;
		break;
	}

	char szTemp[iMax_Str] = "";
	int	iTemp = 0;
	float fTemp = 0;

	for (int i = 0; i < *pCur_Index; ++i)
	{
		for (int j = 0; j < (*pCur_Index) - 1; ++j)
		{
			if (pFunc(tGrade->fAverage[j], tGrade->fAverage[j + 1]))
			{
				strcpy_s(szTemp, tGrade->cName[j]);
				strcpy_s(tGrade->cName[j], tGrade->cName[j + 1]);
				strcpy_s(tGrade->cName[j + 1], szTemp);

				iTemp = tGrade->iKorean[j];
				tGrade->iKorean[j] = tGrade->iKorean[j + 1];
				tGrade->iKorean[j + 1] = iTemp;

				iTemp = tGrade->iEnglish[j];
				tGrade->iEnglish[j] = tGrade->iEnglish[j + 1];
				tGrade->iEnglish[j + 1] = iTemp;

				iTemp = tGrade->iMath[j];
				tGrade->iMath[j] = tGrade->iMath[j + 1];
				tGrade->iMath[j + 1] = iTemp;

				iTemp = tGrade->iTotal[j];
				tGrade->iTotal[j] = tGrade->iTotal[j + 1];
				tGrade->iTotal[j + 1] = iTemp;

				fTemp = tGrade->fAverage[j];
				tGrade->fAverage[j] = tGrade->fAverage[j + 1];
				tGrade->fAverage[j + 1] = fTemp;
			}
		}
	}
}

void main()
{
	void(*pSelect[5])(tagGrade* tGrade, int*) =
	{ InputGrade,PrintGrade,SearchGrade,RemoveGrade,BubbleSort };

	int iSelect = 0, iCur_Index = 0;

	tagGrade tGrade = {};

	while (true)
	{
		system("cls");

		cout << "1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.����" << endl;
		cout << "����: ";
		cin >> iSelect;

		if (6 == iSelect)
			return;

		pSelect[iSelect - 1](&tGrade, &iCur_Index);
	}
}