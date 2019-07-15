#pragma once
#include "cGradeCard.h"
#include <iostream>
#include <list>
using namespace std;

class cGradeCard;

class cGradeLogic
{

public:
	cGradeCard* GradeCard;
	//vector<cGradeCard> vGradeCard;
	list<cGradeCard> ListGradeCard;
	
public:
	cGradeLogic();
	~cGradeLogic();

public:
	void ProgramStart();
	void StudentGradeInput();
	void ShowStudentGradeCard();
	void StudentSearch();
	void StudentGradeCardDelete();
	void StudentGradeSort();
public:
	void TextMainFrame();

};


struct tagGreater
{
	bool operator()(const cGradeCard& a, const cGradeCard& b) const
	{
		return a.ExtractStudentTotal() > b.ExtractStudentTotal();
	}
};

struct tagLess
{
	bool operator()(const cGradeCard& a, const cGradeCard& b) const
	{
		return a.ExtractStudentTotal() < b.ExtractStudentTotal();
	}
};
