#include <iostream>

using namespace std;

// ##1. 구조체 (structure)
// 자료의 집합을 정의한 자료형 (사용자 정의 자료형)

// 구조체 정의
/*(태그는 구조체 선언할 때 대부분 붙임. 일종의 약속)*/

// 자료형 선언 X 명시 -> 코드에 포함.
struct tagGrade
{
	char szName[32];
	int iKorean;
	int iEnglish;
	int iMath;
	int iTotal;
	float fAverage;
};

struct tagPoint
{
	int ix;
	int iy;
};

void main()
{
	// ##2. 구조체 변수 선언
	// tagGrade tGrade1; // 모든 멤버 쓰레기값으로 초기화.
	// tagGrade tGrade2 = {"홍길동",90,80,70,240,80.f}; // 멤버 변수가 나열된 순으로 초기화.
	// tagGrade tGrade3 = { "홍길동",90,80 }; //나머지 멤버 0 초기화
	// tagGrade tGrade4 = {}; // 모든 멤버 0 초기화.

	// ##3. 구조체 멤버 접근
	tagGrade tGrade = { "홍길동",90,80,70,240,80.f };

	// .(dot)연산자를 사용한다.
	// 자료형이기 때문에 스택에 분류

	// cout << "이름 : " << tGrade.szName << endl;
	// cout << "국어 점수 : " << tGrade.iKorean << endl;
	// cout << "영어 점수 : " << tGrade.iEnglish << endl;
	// cout << "수학 점수 : " << tGrade.iMath << endl;
	// cout << "총점 : " << tGrade.iTotal << endl;
	// cout << "평균 : " << tGrade.fAverage << endl;

	return;
}