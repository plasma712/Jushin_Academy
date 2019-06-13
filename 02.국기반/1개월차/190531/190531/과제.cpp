/*
	과제 5명의 학생 성적표를 관리하는 프로그램 작성.
	(이름 국 영 수 총점 평균)

	1. 입력 가능
	- 5명분 초과되면 입력 불가.
	- 평균 점수 기준으로 내림차순 정렬.

	2. 출력 가능
	- 5명분 성적표 출력.

	3. 검색기능
	- 이름으로 검색하면 해당 학생의 성적표만 출력.

	4. 삭제기능
	- 이름으로 검색한 뒤 해당 학생의 성적표 삭제.
	- 삭제된 공간은 매꿔주기 [1,2,3,4,5] 4번 삭제
							 [1,2,3,5,\0] 이런식으로 땡겨지게 memmove쓰면될듯


	전체관리 메인함수.

	입력, 출력, 검색, 삭제 함수

	가장 쉬운방법은 전역변수로 입력받을꺼 박아둔다음에 그냥 사용하기.

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
		cout << "여유공간이 없습니다." << endl;
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
//출력 부분

//성적표 출력레이아웃
void GradeCardLayOut(char* _cName, int* _iKor, int* _iEng, int* _iMath, int* _iTotal,float* _fAverage)
{
	cout << "학생 이름 :" << _cName << endl;
	cout << _cName << "의 국어 점수 :" << *_iKor << endl;
	cout << _cName << "의 영어 점수 :" << *_iEng << endl;
	cout << _cName << "의 수학 점수 :" << *_iMath << endl;
	cout << _cName << "의 총합 점수 :" << *_iTotal << endl;
	cout << _cName << "의 평균 점수 :" << *_fAverage << endl;
	cout << endl;
}
//이름으로 검색하기
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
		cout << "검색결과가 없습니다" << endl;
	}
}

//출력
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
		cout << "출력할 것 이 없습니다. " << endl;
	}
}

void MenuSelcetLayout()
{
	cout << "--------------성적표 관리 프로그램--------------" << endl;
	cout << "1 : 학생 성적 입력            2: 학생 성적 출력 " << endl;
	cout << "3 : 학생 검색 하기            4: 학생 성적 삭제 " << endl;
	cout << "------------------------------------------------" << endl;
}

bool CheckInput()
{
	if (Student_1::cName[0] != *"\0"&&Student_2::cName[0] != *"\0"&&Student_3::cName[0] != *"\0"&&Student_4::cName[0] != *"\0"&&Student_5::cName[0] != *"\0")
	{
		cout << "여유공간이 없습니다." << endl;
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
		cout << "삭제 할 것이 없습니다." << endl;
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
		cout << "검색 할 것이 없습니다." << endl;
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
		cout << "삭제할 것이 없습니다" << endl;
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


	while (true)//기본 루프
	{
		char cInputName[50] = "";
		system("cls");
		MenuSelcetLayout();

		cout << "메뉴 선택 : ";
		cin >> iTempInputNum;
		system("cls");

		switch (iTempInputNum)
		{
		case 1:		//입력
			if (CheckInput() == false)
				break;
			cout << "학생 이름 :";
			cin >> cInputName;
			cout << cInputName << " 국어 성적 : ";
			cin >> iKor;
			cout << cInputName << " 영어 성적 : ";
			cin >> iEng;
			cout << cInputName << " 수학 성적 : ";
			cin >> iMath;
			EmptyPlaceCheck_Input(cInputName, &iKor, &iEng, &iMath);
			break;
		case 2:		//출력
			GradeCard_Cout();
			system("pause");
			break;
		case 3:		//검색
			if (CheckSearch() == false)
				break;
			cout << "검색하실 학생 이름을 입력해주세요 : ";
			cin >> cInputName;
			system("cls");
			cout << "---------검색 결과---------"<< endl;
			NameSearch(cInputName);
			system("pause");
			break;
		case 4:		//삭제
			if (CheckDelete() == false)
				break;
			cout << "삭제하실 학생 이름을 입력해주세요 : ";
			cin >> cInputName;
			DeleteStudent(cInputName);
			system("cls");
			cout << "---------삭제처리 되었습니다.---------" << endl;
			system("pause");
			break;
		default:
			break;
		}


	}



	return;
}