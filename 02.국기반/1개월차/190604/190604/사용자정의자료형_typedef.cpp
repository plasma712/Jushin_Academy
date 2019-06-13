#include <iostream>

using namespace std;

// ##1. 사용자 정의 자료형
// typedef : 기존의 자료형을 사용자가 새로운 이름으로 정의하는 자료형.

typedef int MY_INTEGER; // 유지보수 측면에서 많이 쓴다.(int -> short double 과 같게 타입을 변경하기 쉽다.)

typedef struct tagGrade
{

}Grade, *Grade;


void main()
{
	MY_INTEGER a = 100;
	MY_INTEGER b = 200;

	cout << a << endl;
	return;
}