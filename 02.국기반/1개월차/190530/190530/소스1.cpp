#include <iostream> 
using namespace std;

void main()
{

	// ##1. 문자 배열 (문자열)
	// 문자배열을 초기화할 때 null문자('\0')자리까지 고려해야한다.
	// char szName[6] = { 'H','e','l','l','o' };
	// char szName2[6] = "Hello";

	// cout은 char*를 만나면 이 주소로부터 null문자를 만나기 전까지 출력한다.
	// null문자가 없으면 문자열의 끝을 판별 할 수 없다.
	// cout << szName << endl;
	// cout << szName2 << endl;

	// ##2. 문자열 상수
	
	// const char* pName = "Hello";
	// 
	// cout << "Hello" << endl;
	// cout << pName << endl;
	// cout << pName[1] << endl;

	// pName[1] = 'e' // error 상수이므로 값 변경 X

	// ##3. 문자열 입력 받기
	// char szInput[6] = ""; // 모든 원소 0으로 초기화
	// 
	// cout << "입력: ";	// 입력받을 때 배열의 길이 넘어서지 않도록 주의.
	// cin >> szInput;
	// 
	// cout << "출력: " << szInput << endl;

	// 잘못된 문자열 입력_1
	// char* pInput = nullptr;
	// 
	// cin >> pInput;
	// cout << pInput << endl;

	// 잘못된 문자열 입력_2
    // char* pInput = "Hello";
	// cin >> pInput;
	// cout << pInput << endl;


	return;
}