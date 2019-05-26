#include <iostream>
using namespace std;

void main()
{
//##1. 변수와 자료형
	// 변수 : 값을 저장하기 위한 저장 공간. 재사용하기 위해.
	// - 값이 저장된 공간에 이름을 붙여주는 역할을 한다.

	// 자료형 : 어떤 유형의 값인지, 저장 공간의 크기는 얼마인지를 결정.

	// ##2. 변수 이름 규칙.
	// 1. 숫자가 알파벳보다 먼저 와선 안 된다.
	// ex) int 2Player; -> error
	//     int P2layer; -> ok
	//
	// 2. 특수문자는 안 된다. 단, _언더바는 허용.
	// 3. 변수 이름에 공백을 포함할 수 없다.int player Hp; 불가능 공백땜 -> int player_Hp; 가능
	// 4. 시스템에서 기본으로 제공하는 키워드로 변수 이름을 지을 수 없다. int, namespace 와 같은
	
	// ##3. 자료형의 종류
	// 1. 정수 타입 : int, short, long, longlong
	// 2. 실수 타입 : float, double, long double
	// 3. 단일 문자 : char, wchar_t
	// 4. 논리 자료형 : bool (참, 거짓) -> C++부터 등장하는 자료형.
	
	// ##4. 각 자료형의 크기 (byte 단위)
	// 1byte자료형 = char, bool
	// 2byte자료형 = short
	// 4byte자료형 = int, long, float
	// 8byte자료형 = long long, double, long double

	// ##5. unsigned와 signed
	//unsigned int b; // 양수만 표현한다. 정수타입에만 올 수 있다.
	//int a;			// 양수, 음수 둘다 표현한다. (signed)-> (부호가있다.)
	// OO1O (가장 앞자리가 0이면 양수 = >  2
	// 1010 (가장 앞자리가 1이면 음수 = > -2 

	// 1의 보수 => 비트 반전 ex) 0010 - > 1의보수는 1101 이다.
	// 2의 보수 => 비트반전 후 + 0001 ->  2의보수는 1110 이다.

	// 4bits => 16개 표현가능
	// unsigned 0 ~ 15
	// signed -8 ~ 7

	// ##6. 각 자료형의 표현 범위
	// 1. unsigend char : char는 엄연히 정수 타입이다. 아스키코드
	// 따라서, unsigned 키워드를 사용할 수 있다.
	// char a = 86; // 아스키 코드
	// char b = 'V';
	// cout << a << endl;
	// cout << b << endl;
	// 표현 범위 : 0 ~ 255, 총 256개의 양수를 표현

	// 2. char (signed)
	// 표현 범위 : -128 ~ 127, 총 256개의 음수, 양수를 표현.

	int PlayerHp = 10000;
	int PlayerMp = 5000;
	int PlayerAtt = 500;
	int playerDef = 150;

	cout << "플레이어의 체력 : " << PlayerHp << endl;
	cout << "플레이어의 마나 : " << PlayerMp << endl;
	cout << "플레이어의 공격력 : " << PlayerAtt << endl;
	cout << "플레이어의 방어력 : " << playerDef << endl;
	return;
}