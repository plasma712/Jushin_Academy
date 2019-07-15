#pragma once
#include <iostream>


struct tagGradeElement
{
	char cName[32];
	int  iKor;
	int  iMath;
	int  iEng;
	int  iTotal;
	float fAge;

	tagGradeElement() = default;
	tagGradeElement
	(
		const char* _cName,
		int  _iKor,
		int  _iMath,
		int  _iEng,
		int  _iTotal,
		float _fAge
	) : iKor(_iKor),iMath(_iMath),iEng(_iEng),iTotal(_iTotal),fAge(_fAge)
	{
		strcpy_s(cName, _cName);
	}
};
