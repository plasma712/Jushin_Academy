#include <iostream> 

using namespace std;

// ##1. 열거체 (enumeration)
// 상태 표현에 쓰이는 상수에 대해서 자료형화 시키는 사용자 정의 자료형

// 열거체 정의
enum MONSTER_STATE
{
	ATTACK,DEFENCE,MOVE,JUMP
};

enum DRINK_ID
{
	COKE,CIDER,FANTA,HOTSIX,DRINK_MAX
};

void main()
{
	// MONSTER_STATE eState = ATTACK; // 열거체 변수는 열거형 {} 에 나열된 값만 가질 수 있다.
	// MONSTER_STATE eState =2; //error
	
	// switch (eState)	// 열거체 변수는 정수로 인식한다.
	// {
	// case ATTACK:
	// 	cout << "공격 패턴" << endl;
	// 	break;
	// case DEFENCE:
	// 	cout << "방어 패턴" << endl;
	// 	break;
	// case MOVE:
	// 	cout << "이동 패턴" << endl;
	// 	break;
	// default:
	// 	break;
	// }

	// ##3. 열거체 응용
	// int iDrinkArr[DRINK_MAX] = { 100,200,300,400 };
	// 
	// cout << "콜라 : " << iDrinkArr[COKE] << endl;
	// cout << "사이다 : " << iDrinkArr[CIDER] << endl;
	// cout << "환타 : " << iDrinkArr[FANTA] << endl;
	// cout << "핫식스 : " << iDrinkArr[HOTSIX] << endl;


	// ##4. 과거 C시절에는 열거체를 int로 간주했으나 C++은 새로운 자료형으로 인식
	// int a = ATTACK; // ATTACK은 정수형태의 상수이므로 INT 변수에 대입 가능
	// MONSTER_STATE eState = 2; // error, 2는 int 타입이므로 불가능; (C시절에는 가능)

	// 정수로 인식하여 4바이트
	cout << sizeof(MONSTER_STATE) << endl;
	return;
}