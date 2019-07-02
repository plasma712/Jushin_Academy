#pragma once
#include <iostream>
#include <vector>
using namespace std;

class cGradeCard;

class cGradeLogic
{

public:
	cGradeCard* GradeCard;
	vector<cGradeCard> vGradeCard;
	
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
