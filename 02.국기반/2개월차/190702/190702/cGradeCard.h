#pragma once
#include "GradeElementStruct.h"

class cGradeCard
{
private:
	tagGradeElement GradeElement;

public:
	cGradeCard();
	cGradeCard(
		const char* _cName,
		int  _iKor,
		int  _iMath,
		int  _iEng,
		int  _iTotal,
		float _fAge
	);
	~cGradeCard();

public:
	void Init();
	void Draw();
	void Update();
	void Release();

public:
	void NewStudent(cGradeCard* _GradeCard);
	void ShowStudentGradeCard(cGradeCard* _GradeCard,int _CheckingNumber);
	void GradeCardSearch(char* _GradeCard, char* _cName,int _CheckingNumber);
	int DeleteGradeCard(char* _GradeCard, char* _cName, int _CheckingNumber);

	char* ExtractStudent();
	int ExtractStudentTotal();
	//void GradeCardSort();
};

