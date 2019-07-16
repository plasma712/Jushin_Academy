#include <iostream>

using namespace std;

void main()
{
	// SBCS (Single Byte Character Set)
	// 단일 문자를 사용할 때 1 바이트를 사용한다.
	// char , 아스키코드

	// MBCS (Multi Bytes Character Set)
	// char를 사용하지만 때에 따라 1바이트 혹은 2바이트 사용한다.


	// char szBuf1[] = "Hello";
	// char szBuf2[] = "한글";
	   
	// cout << sizeof(szBuf1) << endl;
	// cout << sizeof(szBuf2) << endl;
	   
	// cout << strlen(szBuf2) << endl; // 우리에겐 2글자, 컴퓨터에겐 4글자


	// WBCS (Wide Bytes Character Set)
	// 단일 문자를 사용할 때 2바이트를 사용한다.
	// wchar_t 유니코드
	cout << sizeof(wchar_t) << endl;


	// 유니코드 계열의 문자열을 다룰 때 앞에 반드시 L기호를 붙어있어야 한다.
	wchar_t szBuf1[] = L"Hello";
	wchar_t szBuf2[] = L"한글";

	// 유니코드 계열 문자열길이함수

	//wcslen()




}