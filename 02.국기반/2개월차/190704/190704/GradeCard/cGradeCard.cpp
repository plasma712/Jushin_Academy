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
	cout << "������ ����" << endl;
}


cGradeCard::~cGradeCard()
{
	//cout << "�Ҹ��� ����" << endl;
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
	cout << "����ǥ �Է�" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "�л� �̸� : ";
	cin >> _GradeCard->GradeElement.cName;
	cout << "���� ���� : ";
	cin >> _GradeCard->GradeElement.iKor;
	cout << "���� ���� : ";
	cin >> _GradeCard->GradeElement.iMath;
	cout << "���� ���� : ";
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
		cout << "����ǥ ���" << endl;
		cout << "------------------------------------------------" << endl;
	}
	CheckingNumber++;
	cout << "�л� �̸� : " << _GradeCard->GradeElement.cName << endl;
	cout << "���� ���� : " << _GradeCard->GradeElement.iKor << endl;
	cout << "���� ���� : " << _GradeCard->GradeElement.iEng << endl;
	cout << "���� ���� : " << _GradeCard->GradeElement.iMath << endl;
	cout << "���� ���� : " << _GradeCard->GradeElement.iTotal << endl;
	cout << "��� ���� : " << _GradeCard->GradeElement.fAge << endl;
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
		cout << "��ϵ� �л��Դϴ�." << endl;
		cout << "------------------------------------------------" << endl;
		this->ShowStudentGradeCard(this,1);
		SearchCheckingNumber = 0;
		return;
	}
	if (SearchCheckingNumber == _CheckingNumber)
	{
		system("cls");
		cout << "��ϵ��� ���� �л��Դϴ�." << endl;
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
		cout << "��ϵ� �л��Դϴ�." << endl;
		cout << "------------------------------------------------" << endl;
		//this->ShowStudentGradeCard(this, 1);
		DeleteCheckingNumber = 0;
		cout << "���� ó���߽��ϴ�." << endl;
		return false;
	}
	if (DeleteCheckingNumber == _CheckingNumber)
	{
		system("cls");
		cout << "��ϵ��� ���� �л��Դϴ�." << endl;
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