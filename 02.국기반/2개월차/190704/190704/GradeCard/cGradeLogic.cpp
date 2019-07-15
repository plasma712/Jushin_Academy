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
	cout << "학생 검색 : ";
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
	cout << "학생 삭제 : ";
	cin >> cName;
	//cout << "사이즈 값 : " << vGradeCard.size() << endl;
	for (cGradeCard element : ListGradeCard)
	{
		if (element.DeleteGradeCard(element.ExtractStudent(), cName, ListGradeCard.size()) == false)
		{
			// cout << "false" << endl;
			// cout<<"i 값 : " << i << endl;
			ListGradeCard.erase(iter_begin);
			system("pause");
			bCheck = false;
			return;
		}
		iter_begin++;
	}
	if (bCheck == true)
	{
		cout << cName << " 학생이 존재 하지 않습니다." << endl;
		system("pause");
	}
}

void cGradeLogic::StudentGradeSort()
{
	int iSelectNumber = 0;
	cout << "1. 오름차순  2. 내림차순  " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "선택 : ";
	cin >> iSelectNumber;
	if (iSelectNumber == 1)
		ListGradeCard.sort(tagGreater());
	else if (iSelectNumber == 2)
		ListGradeCard.sort(tagLess());
	else
		return;
	system("cls");
	cout << "정렬 완료" << endl;
	system("pause");
}


void cGradeLogic::TextMainFrame()
{
	cout << "--------------성적표 관리 프로그램--------------" << endl;
	cout << "1 : 학생 성적 입력            2: 학생 성적 출력 " << endl;
	cout << "3 : 학생 검색 하기            4: 학생 성적 삭제 " << endl;
	cout << "5 : 정렬 하기                                   " << endl;
	cout << "------------------------------------------------" << endl;
	cout << "선택 : ";
}


