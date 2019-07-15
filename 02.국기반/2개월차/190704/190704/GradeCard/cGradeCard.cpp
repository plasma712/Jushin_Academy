#include "cGradeCard.h"
#include <iostream>
#include <list>

using namespace std;

cGradeCard::cGradeCard()
{
}

cGradeCard::cGradeCard(const char * _cName, int _iKor, int _iMath, int _iEng, int _iTotal, float _fAge)
	:GradeElement(_cName, _iKor, _iMath, _iEng, _iTotal, _fAge)
{
	cout << "생성자 들어옴" << endl;
}


cGradeCard::~cGradeCard()
{
	//cout << "소멸자 들어옴" << endl;
}

void cGradeCard::Init()
{
}

void cGradeCard::Draw()
{
}

void cGradeCard::Update()
{
}

void cGradeCard::Release()
{
}

void cGradeCard::NewStudent(cGradeCard* _GradeCard)
{
	cout << "성적표 입력" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "학생 이름 : ";
	cin >> _GradeCard->GradeElement.cName;
	cout << "국어 점수 : ";
	cin >> _GradeCard->GradeElement.iKor;
	cout << "수학 점수 : ";
	cin >> _GradeCard->GradeElement.iMath;
	cout << "영어 점수 : ";
	cin >> _GradeCard->GradeElement.iEng;
	_GradeCard->GradeElement.iTotal =
		(
			_GradeCard->GradeElement.iKor +
			_GradeCard->GradeElement.iMath +
			_GradeCard->GradeElement.iEng
			);
	_GradeCard->GradeElement.fAge = (float)_GradeCard->GradeElement.iTotal / 3;
}

void cGradeCard::ShowStudentGradeCard(cGradeCard* _GradeCard, int _CheckingNumber)
{
	static int CheckingNumber = 0;
	if (CheckingNumber == 0)
	{
		cout << "성적표 출력" << endl;
		cout << "------------------------------------------------" << endl;
	}
	CheckingNumber++;
	cout << "학생 이름 : " << _GradeCard->GradeElement.cName << endl;
	cout << "국어 점수 : " << _GradeCard->GradeElement.iKor << endl;
	cout << "수학 점수 : " << _GradeCard->GradeElement.iEng << endl;
	cout << "영어 점수 : " << _GradeCard->GradeElement.iMath << endl;
	cout << "총합 점수 : " << _GradeCard->GradeElement.iTotal << endl;
	cout << "평균 점수 : " << _GradeCard->GradeElement.fAge << endl;
	cout << "------------------------------------------------" << endl;
	if (CheckingNumber == _CheckingNumber)
	{
		CheckingNumber = 0;
	}
}

void cGradeCard::GradeCardSearch(char* _GradeCard, char* _cName, int _CheckingNumber)
{
	static int SearchCheckingNumber = 0;

	if (strcmp(_GradeCard, _cName) == false)
	{
		system("cls");
		cout << "등록된 학생입니다." << endl;
		cout << "------------------------------------------------" << endl;
		this->ShowStudentGradeCard(this,1);
		SearchCheckingNumber = 0;
		return;
	}
	if (SearchCheckingNumber == _CheckingNumber)
	{
		system("cls");
		cout << "등록되지 않은 학생입니다." << endl;
		cout << "------------------------------------------------" << endl;
		SearchCheckingNumber = 0;
		return;
	}
	++SearchCheckingNumber;

}

int cGradeCard::DeleteGradeCard(char* _GradeCard, char* _cName, int _CheckingNumber)
{
	static int DeleteCheckingNumber = 0;

	if (strcmp(_GradeCard, _cName) == false)
	{
		system("cls");
		cout << "등록된 학생입니다." << endl;
		cout << "------------------------------------------------" << endl;
		//this->ShowStudentGradeCard(this, 1);
		DeleteCheckingNumber = 0;
		cout << "삭제 처리했습니다." << endl;
		return false;
	}
	if (DeleteCheckingNumber == _CheckingNumber)
	{
		system("cls");
		cout << "등록되지 않은 학생입니다." << endl;
		cout << "------------------------------------------------" << endl;
		DeleteCheckingNumber = 0;
		return true;
	}
	++DeleteCheckingNumber;

}

char * cGradeCard::ExtractStudent()
{
	return GradeElement.cName;
}

int cGradeCard::ExtractStudentTotal() const
{
	return GradeElement.iTotal;
}