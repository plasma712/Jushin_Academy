#include "cGradeLogic.h"
#include "cGradeCard.h"
#include <vector>


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
	vGradeCard.push_back(*GradeCard);

	delete GradeCard;
}

void cGradeLogic::ShowStudentGradeCard()
{
	for (size_t i = 0; i < vGradeCard.size(); i++)
	{
		vGradeCard[i].ShowStudentGradeCard(&vGradeCard[i], vGradeCard.size());
	}
	system("pause");
}

void cGradeLogic::StudentSearch()
{
	char cName[32];
	cout << "------------------------------------------------" << endl;
	cout << "학생 검색 : ";
	cin >> cName;
	for (size_t i = 0; i < vGradeCard.size(); i++)
	{
		vGradeCard[i].GradeCardSearch(vGradeCard[i].ExtractStudent(), cName, vGradeCard.size());
	}
	system("pause");

}

void cGradeLogic::StudentGradeCardDelete()
{
	char cName[32];
	bool bCheck = true;
	cout << "------------------------------------------------" << endl;
	cout << "학생 삭제 : ";
	cin >> cName;
	//cout << "사이즈 값 : " << vGradeCard.size() << endl;
	for (size_t i = 0; i < vGradeCard.size(); i++)
	{
		if (vGradeCard[i].DeleteGradeCard(vGradeCard[i].ExtractStudent(), cName, vGradeCard.size()) == false)
		{
			// cout << "false" << endl;
			// cout<<"i 값 : " << i << endl;
			vGradeCard.erase(vGradeCard.begin() + i);
			system("pause");
			bCheck = false;
			return;
		}
	}
	if (bCheck == true)
	{
		cout << cName << " 학생이 존재 하지 않습니다." << endl;
		system("pause");
	}
}

void cGradeLogic::StudentGradeSort()
{

	for (size_t i = 0; i < vGradeCard.size(); i++)
	{
		int temp = 0;
		
		for (size_t i = 0; i < vGradeCard.size(); i++)
		{
			for (size_t k = 0; k < vGradeCard.size() - i - 1; k++)
			{
				if (vGradeCard[i].ExtractStudentTotal() > vGradeCard[i + 1].ExtractStudentTotal())
				{
					swap(vGradeCard[i], vGradeCard[i + 1]);
				}
			}
		}
	}
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
