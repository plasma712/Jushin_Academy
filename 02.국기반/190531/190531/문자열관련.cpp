#include <iostream>

using namespace std;

void main()
{
	// ##1. 문자열 길이 구하는 표준 함수. <string.h> 에서 제공
	// null문자를 제외한 순수 문자열 길이를 구한다.
	// size_t strlen(const char* ) => const char*는 간접참조로 char* 뒤에 있는 값을 변경하지 않도록 하는 보호용

	// char szName[6] = "world";
	// 
	// cout << "길이 : " << strlen(szName) << endl;
	// cout << "메모리 크기 : " << sizeof(szName) << endl;
	// 
	// cout << "길이 : " << strlen("HelloWorld") << endl;
	// cout << "메모리 크기 : " << sizeof("HelloWorld") << endl;


	// ##2. 문자열 비교하는 표준 함수. <string.h>에서 비교
	// int strcmp(const char* , const char*)
	// 비교하는 두 문자열이 같으면 0을 반환. 다르면 0이 아닌값 반환

	// char szName_1[32] = "Hello";
	// char szName_2[32] = "Hello";

	// 문자열을 비교하는것이 아니라 주소값을 비교하기에 다르다고 나온다.
	// if (szName_1 == szName_2)
	// 	cout << "두 문자열은 같습니다." << endl;
	// else
	// 	cout << "두 문자열은 다릅니다." << endl; 

	// if(!strcmp(szName_1,szName_2)) 문자열 비교 함수
	//  	cout << "두 문자열은 같습니다." << endl;
	//  else
	//  	cout << "두 문자열은 다릅니다." << endl; 

	// ##3. 문자열 복사하는 표준함수. <string.h>에서 제공
	// strcpy_s()

	// char szName_1[32] = "";
	// char szName_2[32] = "Hello";

	// 배열의 이름은 상수포인터다.
	// szName_1 = szName_2; // error
	 
	// strcpy_s(szName_1, szName_2);			// strcpy의 확장버전.
	// cout << "szName_1 : " << szName_1 << endl;
	// cout << "szName_2 : " << szName_2 << endl;

	// char* ptr = szName_1;

	// 첫 인자가 배열의 이름이 아닌 단순 char*면 가운데 복사할 크기를 꼭 명시해줘야 한다.
	// 가운데 인자는 복사할 크기보다 같거나 커야한다.
	// strcpy_s(ptr, 6, szName_2);


	// ##4. 문자열 이어붙이는 표준함수. <string.h>에서 제공
	// strcat_s()

	// char szName_1[32] = "Hello";
	// char szName_2[32] = "World";

	// szName_1이 가지고 있는 null문자 자리에 szName_2를 이어 붙인다.
	// szName_1의 배열 크기는 둘이 합한 크기보다 넉넉해야한다.
	// strcat_s(szName_1, szName_2);
	// cout << szName_1 << endl;

	// 첫인자가 배열의 이름이 아닌 char* 이면 가운데 크기를 꼭 명시해줘야한다.
	// 가운데 인자는 결합한 무자열의 크기보다 작아선 안된다.
	
	return;
}