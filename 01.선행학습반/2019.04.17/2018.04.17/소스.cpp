#include <iostream>

using namespace std;

void main()
{
	//	//goto문
	//GA:
	//	cout << "가" << endl;
	//	goto SA;
	//	cout << "나" << endl;
	//	goto BA;
	//	cout << "다" << endl;
	//RA:
	//	cout << "라" << endl;
	//	cout << "마" << endl;
	//BA:
	//	goto GA;
	//	cout << "바" << endl;
	//SA:
	//	cout << "사" << endl;
	//	goto RA;

		// if 문

//if (true)
//{
//	cout << "여기 있는 이 글자가 출력이 될 것이다." << endl;
//}
//
//int iResult = 0;
//cout << "값 입력 : ";
//cin >> iResult;
//
//if (iResult >= 20)
//{
//	cout << "성인 입니다. " << endl;
//}
//
//// 모든 경우를 다 검사한다.
//if (true)
//{
//	cout << "박태호 " << endl;
//}
//if (true)
//{
//	cout << "박태호1 " << endl;
//}
//if (true)
//{
//	cout << "박태호2 " << endl;
//}
//if (true)
//{
//	cout << "박태호3 " << endl;
//}
//
//// 삼항 연산자 - (조건식 ) ? 참 일 경우 : 거짓 일 경우
//
//int iMax = (10 > 20) ? 10 : 20;
//cout << iMax << endl;
//
//int iResult = 0;
//cout << "값을 입력 : ";
//cin >> iResult;
//
//iMax = (iResult >= 0) ? iResult : -iResult; //절대값 구하기
//
//if (iResult < 20)
//{
//	cout << "미성년자 ㅉㅉ." << endl;
//}
//
//if (true)
//{
//	int 박태호 = 0;
//
//	cout << "과연..." << endl;
//}
//
//// 지역변수인 '박태호'는 밖에서 사용 불가능
//
//// if , else if , else 를 하면 한몸으로 치기에 윗쪽에서 맞으면 나머지를 검사하지 않는다.
//if (true)
//{
//	cout << "박태호 " << endl;
//}
//else if (true)
//{
//	cout << "박태호1 " << endl;
//}
//else if (true)
//{
//	cout << "박태호2 " << endl;
//}
//else
//{
//	cout << "박태호3 " << endl;
//}
//
	// switch - 정수 분기문 혹은 상수 분기문이라고도 불린다.

	//switch (/*정수*/)
	//{
	// 분기 상수로만 가능. 단 변수는 변수이나 상수화된 변수는 올 수 없다.
	// 반드시 무조건 정수만 가능하다. 실수는 오차가 발생하기 때문에 불가능하다.
	//case 1:
	//case 2:
	//case 3:
	//
	//default:
	//	break;
	//}

switch (1)
{
case 1:
	cout << "콜라" << endl;
	return;
case 2:
	cout << "사이다" << endl;
	return;
case 3:
	cout << "솔의눈" << endl;
	return;
default:
	break;
}

}