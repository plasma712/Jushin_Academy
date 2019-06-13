// char* InputString()
// {
// 	char* ptr = new char[32]{};
// 
// 	cout << "���ڿ� �Է� : ";
// 	cin >> ptr;
// 
// 	return ptr;
// }
// 
// void main()
// {
// 	char* pName = InputString();
// 
// 	cout << "��� : " << pName << endl;
// 
// 	delete[] pName;
// 
// 	return;
// }
#include <iostream>

using namespace std;

int iMax_Count = 2;
const int iMax_Str = 32;

struct tagGrade
{
	char cName[iMax_Str];
	int iKorean;
	int iEnglish;
	int iMath;
	int iTotal;
	float fAverage;
};

bool Less(float a, float b) // ��������
{
	return a > b;
}

bool Greater(float a, float b) // ��������
{
	return a < b;
}

void ExpansionGrade(tagGrade** tGrade, int * _iMax_Count);
//void ExpansionGrade(tagGrade tGrade[], int * _iMax_Count);
void InputGrade(tagGrade tGrade[], int* pCur_Index);
void PrintGrade(tagGrade tGrade[], int* pCur_Index);
void SearchGrade(tagGrade tGrade[], int* pCur_Index);
void RemoveGrade(tagGrade tGrade[], int* pCur_Index);
void BubbleSort(tagGrade tGrade[], int* pCur_Index);

void main();

void ExpansionGrade(tagGrade** tGrade, int* _iMax_Count)
{
	//cout << *_iMax_Count << endl;
	tagGrade* tGrade_1 = new tagGrade[*_iMax_Count + 1]{};

	memcpy(tGrade_1, *tGrade, sizeof(tagGrade)*(*_iMax_Count));

	delete[] *tGrade;

	// tGrade = new tagGrade[*_iMax_Count + 1]{};
	// memcpy(tGrade, tGrade_1, sizeof(tagGrade)*(*_iMax_Count));
	*tGrade = tGrade_1;

	++(*_iMax_Count);
	delete[] tGrade_1;
}

//void ExpansionGrade(tagGrade tGrade[], int* _iMax_Count)
//{
//	//cout << "ExpansionGrade ����" << endl;
//	//system("pause");
//	tagGrade* tGrade_1 = new tagGrade[*_iMax_Count + 1];
//
//	for (int i = 0; i < *_iMax_Count; i++)
//	{
//		//tGrade_1[i] = *tGrade[i];
//
//		memcpy(&tGrade_1[i], &tGrade[i], sizeof(tGrade));
//	}
//
//
//	delete[] tGrade;
//
//	tGrade = new tagGrade[*_iMax_Count + 1];
//
//	for (int i = 0; i < *_iMax_Count; i++)
//	{
//		//tGrade[i] = &tGrade_1[i];
//
//		memcpy(&tGrade[i], &tGrade_1[i], sizeof(tGrade_1[i]));
//	}
//
//	++(*_iMax_Count);
//	delete[] tGrade_1;
//
//
//}

void InputGrade(tagGrade tGrade, int* pCur_Index)
{
	if (iMax_Count == *pCur_Index)
	{
		int InputNum = 0;
		// cout << "�� �̻� �Է��� �� �����ϴ�." << endl;
		// system("pause");
		// return;
		cout << "�Է� �� �� �ִ� �л� ���� �ʰ��˴ϴ�. �߰��Ͻðڽ��ϱ�? " << endl;
		cout << "1. �߰�" << " 2. X " << endl;
		cin >> InputNum;

		if (InputNum == 1)
		{
			ExpansionGrade(tGrade, &iMax_Count);
			//ExpansionGrade(tGrade, &iMax_Count);
			//cout << iMax_Count << endl;
			system("pause");

		}
		else
		{
			system("pause");
			return;
		}
	}

	cout << "�л� �̸� �Է�: ";
	cin >> tGrade[*pCur_Index].cName;

	cout << "���� ���� �Է�: ";
	cin >> tGrade[*pCur_Index].iKorean;

	cout << "���� ���� �Է�: ";
	cin >> tGrade[*pCur_Index].iEnglish;

	cout << "���� ���� �Է�: ";
	cin >> tGrade[*pCur_Index].iMath;

	tGrade[*pCur_Index].iTotal = tGrade[*pCur_Index].iKorean + tGrade[*pCur_Index].iEnglish + tGrade[*pCur_Index].iMath;
	tGrade[*pCur_Index].fAverage = float(tGrade[*pCur_Index].iTotal) / 3;

	++(*pCur_Index);
}

void PrintGrade(tagGrade tGrade[], int* pCur_Index)
{
	system("cls");

	for (int i = 0; i < *pCur_Index; ++i)
	{
		cout << "�̸�: " << tGrade[i].cName << endl;
		cout << "����: " << tGrade[i].iKorean << endl;
		cout << "����: " << tGrade[i].iEnglish << endl;
		cout << "����: " << tGrade[i].iMath << endl;
		cout << "����: " << tGrade[i].iTotal << endl;
		cout << "���: " << tGrade[i].fAverage << endl;
		cout << "-----------------------------" << endl;
	}

	system("pause");
}

void SearchGrade(tagGrade tGrade[], int* pCur_Index)
{
	system("cls");

	char szSearch[iMax_Str] = "";

	cout << "�˻�: ";
	cin >> szSearch;

	for (int i = 0; i < *pCur_Index; ++i)
	{
		if (!strcmp(szSearch, tGrade[i].cName))
		{
			cout << "�̸�: " << tGrade[i].cName << endl;
			cout << "����: " << tGrade[i].iKorean << endl;
			cout << "����: " << tGrade[i].iEnglish << endl;
			cout << "����: " << tGrade[i].iMath << endl;
			cout << "����: " << tGrade[i].iTotal << endl;
			cout << "���: " << tGrade[i].fAverage << endl;
			cout << "-----------------------------" << endl;
			system("pause");
			return;
		}
	}

	cout << "�˻� ����� �����ϴ�." << endl;
	system("pause");
}

void RemoveGrade(tagGrade tGrade[], int* pCur_Index)
{
	system("cls");

	char szSearch[iMax_Str] = "";

	cout << "����: ";
	cin >> szSearch;

	for (int i = 0; i < *pCur_Index; ++i)
	{
		if (!strcmp(szSearch, tGrade[i].cName))
		{
			int iDataCount = (*pCur_Index) - i - 1;

			memmove(tGrade + i, tGrade + (i + 1), sizeof(tagGrade) * iDataCount);
			--(*pCur_Index);
			return;
		}
	}

	cout << "�˻� ����� �����ϴ�." << endl;
	system("pause");
}

void BubbleSort(tagGrade tGrade[], int* pCur_Index)
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


	tagGrade tTemp = {};

	for (int i = 0; i < *pCur_Index; ++i)
	{
		for (int j = 0; j < (*pCur_Index) - 1; ++j)
		{
			if (pFunc(tGrade[j].fAverage, tGrade[j + 1].fAverage))
			{
				// ����ü ���� ������ ����ü�� ���� �ִ� ��� �� ��� ���� �����.
				tTemp = tGrade[j];
				tGrade[j] = tGrade[j + 1];
				tGrade[j + 1] = tTemp;
			}
		}
	}

}

void main()
{
	int iSelect = 0, iCur_Index = 0;
	//tagGrade tGrade[iMax_Count] = {};

	tagGrade* tGrade = new tagGrade[iMax_Count];


	void(*pSelect[5])(tagGrade[], int*) =
	{ InputGrade,PrintGrade,SearchGrade,RemoveGrade,BubbleSort };

	while (true)
	{
		system("cls");

		cout << "1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.����" << endl;
		cout << "����: ";
		cin >> iSelect;

		//switch (iSelect)
		//{
		//case 1:
		//	InputGrade(tGrade, &iCur_Index);
		//	break;
		//case 2:
		//	PrintGrade(tGrade, &iCur_Index);
		//	break;
		//case 3:
		//	SearchGrade(tGrade, &iCur_Index);
		//	break;
		//case 4:
		//	RemoveGrade(tGrade, &iCur_Index);
		//	break;
		//case 5:
		//	BubbleSort(tGrade, &iCur_Index);
		//	break;
		//case 6:
		//	return;
		//
		//default:
		//	break;
		//}


		if (6 == iSelect)
			return;

		pSelect[iSelect - 1](tGrade, &iCur_Index);
	}

	delete[] tGrade;
}