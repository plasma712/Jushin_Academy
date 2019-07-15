#include "cGradeLogic.h"
#include "cGradeCard.h"
#include <vector>
#include <list>

cGradeLogic::cGradeLogic()
	:GradeCard(nullptr)
{
}


cGradeLogic::~cGradeLogic()
{
}

void cGradeLogic::ProgramStart()
{
	int iSelectNumber = 0;
	while (true)
	{
		system("cls");
		TextMainFrame();
		cin >> iSelectNumber;
		switch (iSelectNumber)
		{
		case 1:
			system("cls");
			StudentGradeInput();
			break;
		case 2:
			system("cls");
			ShowStudentGradeCard();
			break;
		case 3:
			system("cls");
			StudentSearch();
			break;
		case 4:
			system("cls");
			StudentGradeCardDelete();
			break;
		case 5:
			system("cls");
			StudentGradeSort();
			break;
		default:
			break;
		}
	}
}

void cGradeLogic::StudentGradeInput()
{
	GradeCard = new cGradeCard;
	GradeCard->NewStudent(GradeCard);
	ListGradeCard.push_back(*GradeCard);

	delete GradeCard;
}

void cGradeLogic::ShowStudentGradeCard()
{
	for (cGradeCard element : ListGradeCard)
	{
		//vGradeCard[i].ShowStudentGradeCard(&vGradeCard[i], vGradeCard.size());
		element.ShowStudentGradeCard(&element, ListGradeCard.size());
	}
	system("pause");
}

void cGradeLogic::StudentSearch()
{
	char cName[32];
	cout << "------------------------------------------------" << endl;
	cout << "�л� �˻� : ";
	cin >> cName;
	for (cGradeCard element : ListGradeCard)
	{
		//vGradeCard[i].GradeCardSearch(vGradeCard[i].ExtractStudent(), cName, vGradeCard.size());
		element.GradeCardSearch(element.ExtractStudent(), cName, ListGradeCard.size());
	}
	system("pause");

}

void cGradeLogic::StudentGradeCardDelete()
{
	char cName[32];
	bool bCheck = true;
	list<cGradeCard>::iterator iter_begin = ListGradeCard.begin();

	cout << "------------------------------------------------" << endl;
	cout << "�л� ���� : ";
	cin >> cName;
	//cout << "������ �� : " << vGradeCard.size() << endl;
	for (cGradeCard element : ListGradeCard)
	{
		if (element.DeleteGradeCard(element.ExtractStudent(), cName, ListGradeCard.size()) == false)
		{
			// cout << "false" << endl;
			// cout<<"i �� : " << i << endl;
			ListGradeCard.erase(iter_begin);
			system("pause");
			bCheck = false;
			return;
		}
		iter_begin++;
	}
	if (bCheck == true)
	{
		cout << cName << " �л��� ���� ���� �ʽ��ϴ�." << endl;
		system("pause");
	}
}

void cGradeLogic::StudentGradeSort()
{
	int iSelectNumber = 0;
	cout << "1. ��������  2. ��������  " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "���� : ";
	cin >> iSelectNumber;
	if (iSelectNumber == 1)
		ListGradeCard.sort(tagGreater());
	else if (iSelectNumber == 2)
		ListGradeCard.sort(tagLess());
	else
		return;
	system("cls");
	cout << "���� �Ϸ�" << endl;
	system("pause");
}


void cGradeLogic::TextMainFrame()
{
	cout << "--------------����ǥ ���� ���α׷�--------------" << endl;
	cout << "1 : �л� ���� �Է�            2: �л� ���� ��� " << endl;
	cout << "3 : �л� �˻� �ϱ�            4: �л� ���� ���� " << endl;
	cout << "5 : ���� �ϱ�                                   " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "���� : ";
}


