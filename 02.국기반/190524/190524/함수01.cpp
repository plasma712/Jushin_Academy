#include<iostream>

using namespace std;

// ##1. 함수 (function)
// 앞으로 프로그램을 설계할 때에는 기능 단위 (함수 단위)로 설계해야한다.
// 함수의 주 목적은 코드 재사용성.

// 함수 선언
int/*반환타입*/Add/*함수이름*/(int a, int b/*매개변수 인자 파라메타*/)
{	/*함수 시작*/

	int iResult = a + b;

	return iResult; /*반환 값*/

}	/*함수 끝*/

// 함수의 4가지 형태
// 1. 반환, 인자 모두 없는 형태
// 2. 반환, 인자 모두 있는 형태
// 3. 반환 있고 인자 없는 형태
// 4. 반환 없고 인자 있는 형태


void/*반환없음*/ main()/*인자없음*/
{
	// ##2. return 키워드
	// cout << "Hello" << endl;
	// return; // 함수 종료 코드
	// 
	// cout << "World" << endl;

	// ##4. 작성된 함수 사용하기(함수 호출)
	// 한버 작성된 함수를 계속 재사용 가능하다.
	int iA = Add(10, 20);

	cout << "덧셈 결과 : " << iA << endl;

	iA = Add(100, 20);

	cout << "덧셈 결과 : " << iA << endl;

	iA = Add(10, 200);

	cout << "덧셈 결과 : " << iA << endl;

}