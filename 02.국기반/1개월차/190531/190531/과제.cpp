/*
	���� 5���� �л� ����ǥ�� �����ϴ� ���α׷� �ۼ�.
	(�̸� �� �� �� ���� ���)

	1. �Է� ����
	- 5��� �ʰ��Ǹ� �Է� �Ұ�.
	- ��� ���� �������� �������� ����.

	2. ��� ����
	- 5��� ����ǥ ���.

	3. �˻����
	- �̸����� �˻��ϸ� �ش� �л��� ����ǥ�� ���.

	4. �������
	- �̸����� �˻��� �� �ش� �л��� ����ǥ ����.
	- ������ ������ �Ų��ֱ� [1,2,3,4,5] 4�� ����
							 [1,2,3,5,\0] �̷������� �������� memmove����ɵ�


	��ü���� �����Լ�.

	�Է�, ���, �˻�, ���� �Լ�

	���� �������� ���������� �Է¹����� �ھƵд����� �׳� ����ϱ�.

*/

#include <iostream>

//#pragma warning(disable:4996)

using namespace std;

//int iAverageArray[5] = {};

void EmptyPlaceCheck_Input(char * _cInputName, int * iKor, int * iEng, int * iMath);

//
void GradeCardInput_Name(char* _cName, char* _InputName);
void GradeCardInput_Kor(int* _iKor, int* _InputKor);
void GradeCardInput_Eng(int* _iEng, int* _InputEng);
void GradeCardInput_Math(int* _iMath, int* _InputMath);
void GradeCardInput_Total(int* _iTotal, int* _InputKor, int* _InputEng, int* _InputMath);
void GradeCardInput_Average(float * _fAverage, int * _iTotal);

void GradeCardLayOut(char * _cName, int * _iKor, int * _iEng, int * _iMath, int * _iTotal, float * _fAverage);


//

namespace Student_1
{
	char cName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;
	float fAverage = 0;
}
namespace Student_2
{
	char cName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;
	float fAverage = 0;
}
namespace Student_3
{
	char cName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;
	float fAverage = 0;
}
namespace Student_4
{
	char cName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;
	float fAverage = 0;
}
namespace Student_5
{
	char cName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;
	float fAverage = 0;
}


void EmptyPlaceCheck_Input(char* _cInputName, int* _iKor, int* _iEng, int* _iMath) //
{
	if (Student_1::cName[0] == *"\0")
	{
		GradeCardInput_Name(Student_1::cName, _cInputName);
		GradeCardInput_Kor(&Student_1::iKor, _iKor);
		GradeCardInput_Eng(&Student_1::iEng, _iEng);
		GradeCardInput_Math(&Student_1::iMath, _iMath);
		GradeCardInput_Total(&Student_1::iTotal, _iKor, _iEng, _iMath);
		GradeCardInput_Average(&Student_1::fAverage, &Student_1::iTotal);
	}
	else if (Student_2::cName[0] == *"\0")
	{
		GradeCardInput_Name(Student_2::cName, _cInputName);
		GradeCardInput_Kor(&Student_2::iKor, _iKor);
		GradeCardInput_Eng(&Student_2::iEng, _iEng);
		GradeCardInput_Math(&Student_2::iMath, _iMath);
		GradeCardInput_Total(&Student_2::iTotal, _iKor, _iEng, _iMath);
		GradeCardInput_Average(&Student_2::fAverage, &Student_2::iTotal);

	}
	else if (Student_3::cName[0] == *"\0")
	{
		GradeCardInput_Name(Student_3::cName, _cInputName);
		GradeCardInput_Kor(&Student_3::iKor, _iKor);
		GradeCardInput_Eng(&Student_3::iEng, _iEng);
		GradeCardInput_Math(&Student_3::iMath, _iMath);
		GradeCardInput_Total(&Student_3::iTotal, _iKor, _iEng, _iMath);
		GradeCardInput_Average(&Student_3::fAverage, &Student_3::iTotal);

	}
	else if (Student_4::cName[0] == *"\0")
	{
		GradeCardInput_Name(Student_4::cName, _cInputName);
		GradeCardInput_Kor(&Student_4::iKor, _iKor);
		GradeCardInput_Eng(&Student_4::iEng, _iEng);
		GradeCardInput_Math(&Student_4::iMath, _iMath);
		GradeCardInput_Total(&Student_4::iTotal, _iKor, _iEng, _iMath);
		GradeCardInput_Average(&Student_4::fAverage, &Student_4::iTotal);

	}
	else if (Student_5::cName[0] == *"\0")
	{
		GradeCardInput_Name(Student_5::cName, _cInputName);
		GradeCardInput_Kor(&Student_5::iKor, _iKor);
		GradeCardInput_Eng(&Student_5::iEng, _iEng);
		GradeCardInput_Math(&Student_5::iMath, _iMath);
		GradeCardInput_Total(&Student_5::iTotal, _iKor, _iEng, _iMath);
		GradeCardInput_Average(&Student_5::fAverage, &Student_5::iTotal);
	}
	else
	{
		cout << "���������� �����ϴ�." << endl;
	}
}

void GradeCardInput_Name(char* _cName, char* _InputName)
{
	strcpy_s(_cName, strlen(_InputName) + 1, _InputName);
}

void GradeCardInput_Kor(int* _iKor, int* _InputKor)
{
	memcpy(_iKor, _InputKor, sizeof(_iKor));
}

void GradeCardInput_Eng(int* _iEng, int* _InputEng)
{
	memcpy(_iEng, _InputEng, sizeof(_iEng));
}

void GradeCardInput_Math(int* _iMath, int* _InputMath)
{
	memcpy(_iMath, _InputMath, sizeof(_iMath));
}

void GradeCardInput_Total(int* _iTotal, int* _InputKor, int* _InputEng, int* _InputMath)
{
	int iInputTotal = 0;
	iInputTotal = (*_InputKor) + (*_InputEng) + (*_InputMath);

	memcpy(_iTotal, &iInputTotal, sizeof(iInputTotal));
}

void GradeCardInput_Average(float* _fAverage,int* _iTotal)
{
	float fAverage = 0;
	fAverage = (float)*_iTotal / 3;

	memcpy(_fAverage, &fAverage, sizeof(fAverage));
}

//void GradeCard_AverageSort()
//{
//	int iAverage[5] = {(int)Student_1::fAverage, (int)Student_2::fAverage, (int)Student_3::fAverage, (int)Student_4::fAverage, (int)Student_5::fAverage};
//
//	int temp = 0;
//
//	for (int i = 0; i < 6; i++)
//	{
//		for (int k = 0; k < 6 - i - 1; k++)
//		{
//			if (iAverage[k] > iAverage[k + 1])
//			{
//				temp = iAverage[k];
//				iAverage[k] = iAverage[k + 1];
//				iAverage[k + 1] = temp;
//			}
//		}
//	}
//
//	memcpy(iAverageArray, iAverage, sizeof(iAverage));
//
//	for (int k = 0; k < 5; k++)
//		cout << iAverageArray[k] << "\t";
//}
//��� �κ�

//����ǥ ��·��̾ƿ�
void GradeCardLayOut(char* _cName, int* _iKor, int* _iEng, int* _iMath, int* _iTotal,float* _fAverage)
{
	cout << "�л� �̸� :" << _cName << endl;
	cout << _cName << "�� ���� ���� :" << *_iKor << endl;
	cout << _cName << "�� ���� ���� :" << *_iEng << endl;
	cout << _cName << "�� ���� ���� :" << *_iMath << endl;
	cout << _cName << "�� ���� ���� :" << *_iTotal << endl;
	cout << _cName << "�� ��� ���� :" << *_fAverage << endl;
	cout << endl;
}
//�̸����� �˻��ϱ�
void NameSearch(char* _cName)
{
	if (!strcmp(Student_1::cName, _cName))
	{
		GradeCardLayOut(Student_1::cName, &Student_1::iKor, &Student_1::iEng, &Student_1::iMath, &Student_1::iTotal,&Student_1::fAverage);
	}
	else if (!strcmp(Student_2::cName, _cName))
	{
		GradeCardLayOut(Student_2::cName, &Student_2::iKor, &Student_2::iEng, &Student_2::iMath, &Student_2::iTotal, &Student_2::fAverage);
	}
	else if (!strcmp(Student_3::cName, _cName))
	{
		GradeCardLayOut(Student_3::cName, &Student_3::iKor, &Student_3::iEng, &Student_3::iMath, &Student_3::iTotal, &Student_3::fAverage);
	}
	else if (!strcmp(Student_4::cName, _cName))
	{
		GradeCardLayOut(Student_4::cName, &Student_4::iKor, &Student_4::iEng, &Student_4::iMath, &Student_4::iTotal, &Student_4::fAverage);
	}
	else if (!strcmp(Student_5::cName, _cName))
	{
		GradeCardLayOut(Student_5::cName, &Student_5::iKor, &Student_5::iEng, &Student_5::iMath, &Student_5::iTotal, &Student_5::fAverage);
	}
	else
	{
		cout << "�˻������ �����ϴ�" << endl;
	}
}

//���
void GradeCard_Cout()
{
	int iCheck = 0;
	if (Student_1::cName[0] != *"\0")
	{
		iCheck++;
		GradeCardLayOut(Student_1::cName, &Student_1::iKor, &Student_1::iEng, &Student_1::iMath, &Student_1::iTotal, &Student_1::fAverage);
	}
	if (Student_2::cName[0] != *"\0")
	{
		iCheck++;
		GradeCardLayOut(Student_2::cName, &Student_2::iKor, &Student_2::iEng, &Student_2::iMath, &Student_2::iTotal, &Student_2::fAverage);
	}
	if (Student_3::cName[0] != *"\0")
	{
		iCheck++;
		GradeCardLayOut(Student_3::cName, &Student_3::iKor, &Student_3::iEng, &Student_3::iMath, &Student_3::iTotal, &Student_3::fAverage);
	}
	if (Student_4::cName[0] != *"\0")
	{
		iCheck++;
		GradeCardLayOut(Student_4::cName, &Student_4::iKor, &Student_4::iEng, &Student_4::iMath, &Student_4::iTotal, &Student_4::fAverage);
	}
	if (Student_5::cName[0] != *"\0")
	{
		iCheck++;
		GradeCardLayOut(Student_5::cName, &Student_5::iKor, &Student_5::iEng, &Student_5::iMath, &Student_5::iTotal, &Student_5::fAverage);
	}
	if(iCheck==0)
	{
		cout << "����� �� �� �����ϴ�. " << endl;
	}
}

void MenuSelcetLayout()
{
	cout << "--------------����ǥ ���� ���α׷�--------------" << endl;
	cout << "1 : �л� ���� �Է�            2: �л� ���� ��� " << endl;
	cout << "3 : �л� �˻� �ϱ�            4: �л� ���� ���� " << endl;
	cout << "------------------------------------------------" << endl;
}

bool CheckInput()
{
	if (Student_1::cName[0] != *"\0"&&Student_2::cName[0] != *"\0"&&Student_3::cName[0] != *"\0"&&Student_4::cName[0] != *"\0"&&Student_5::cName[0] != *"\0")
	{
		cout << "���������� �����ϴ�." << endl;
		system("pause");
		return false;
	}
	else
	{
		return true;
	}
}

bool CheckDelete()
{
	if (Student_1::cName[0] != *"\0" || Student_2::cName[0] != *"\0" || Student_3::cName[0] != *"\0" || Student_4::cName[0] != *"\0" || Student_5::cName[0] != *"\0")
	{
		return true;
	}
	else
	{
		cout << "���� �� ���� �����ϴ�." << endl;
		system("pause");
		return false;
	}
}

bool CheckSearch()
{
	if (Student_1::cName[0] != *"\0" || Student_2::cName[0] != *"\0" || Student_3::cName[0] != *"\0" || Student_4::cName[0] != *"\0" || Student_5::cName[0] != *"\0")
	{
		return true;
	}
	else
	{
		cout << "�˻� �� ���� �����ϴ�." << endl;
		system("pause");
		return false;
	}
}


void DeleteStudent(char* _cName)
{
	if (!strcmp(Student_1::cName, _cName))
	{
		strcpy_s(Student_1::cName, strlen("\0") + 1, "\0");
	}
	else if (!strcmp(Student_2::cName, _cName))
	{
		strcpy_s(Student_2::cName, strlen("\0") + 1, "\0");
	}
	else if (!strcmp(Student_3::cName, _cName))
	{
		strcpy_s(Student_3::cName, strlen("\0") + 1, "\0");
	}
	else if (!strcmp(Student_4::cName, _cName))
	{
		strcpy_s(Student_4::cName, strlen("\0") + 1, "\0");
	}
	else if (!strcmp(Student_5::cName, _cName))
	{
		strcpy_s(Student_5::cName, strlen("\0") + 1, "\0");
	}
	else
	{
		cout << "������ ���� �����ϴ�" << endl;
	}
}

void main()
{
	//char cInputName[50] = "";
	int iKor = 0;
	int iEng = 0;
	int iMath = 0;
	int iTotal = 0;

	int iTempInputNum = 0;
	// cin >> cInputName;
	// //GradeCardInput_Name(Student_1::cName, cInputName);
	// cin >> iKor;
	// cin >> iEng;
	// cin >> iMath;
	// //GradeCardInput_Kor(&Student_1::iKor, &iKor);
	// EmptyPlaceCheck_Input(cInputName, &iKor, &iEng, &iMath,&iTotal);

	//NameSearch(cInputName);
	//cout << *GradeCardInput_Kor << endl;
	//cout << Student_1::cName << endl;
	//GradeCardLayOut(Student_1::cName, &Student_1::iKor, &Student_1::iEng, &Student_1::iMath,&Student_1::iTotal);


	while (true)//�⺻ ����
	{
		char cInputName[50] = "";
		system("cls");
		MenuSelcetLayout();

		cout << "�޴� ���� : ";
		cin >> iTempInputNum;
		system("cls");

		switch (iTempInputNum)
		{
		case 1:		//�Է�
			if (CheckInput() == false)
				break;
			cout << "�л� �̸� :";
			cin >> cInputName;
			cout << cInputName << " ���� ���� : ";
			cin >> iKor;
			cout << cInputName << " ���� ���� : ";
			cin >> iEng;
			cout << cInputName << " ���� ���� : ";
			cin >> iMath;
			EmptyPlaceCheck_Input(cInputName, &iKor, &iEng, &iMath);
			break;
		case 2:		//���
			GradeCard_Cout();
			system("pause");
			break;
		case 3:		//�˻�
			if (CheckSearch() == false)
				break;
			cout << "�˻��Ͻ� �л� �̸��� �Է����ּ��� : ";
			cin >> cInputName;
			system("cls");
			cout << "---------�˻� ���---------"<< endl;
			NameSearch(cInputName);
			system("pause");
			break;
		case 4:		//����
			if (CheckDelete() == false)
				break;
			cout << "�����Ͻ� �л� �̸��� �Է����ּ��� : ";
			cin >> cInputName;
			DeleteStudent(cInputName);
			system("cls");
			cout << "---------����ó�� �Ǿ����ϴ�.---------" << endl;
			system("pause");
			break;
		default:
			break;
		}


	}



	return;
}