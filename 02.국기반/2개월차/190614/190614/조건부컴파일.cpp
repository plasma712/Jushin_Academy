#include <iostream>

using namespace std;

// ##1. 조건부_ 컴파일
// #if ~ #endif
// #ifdef ~ #endif
// #ifndef ~ #endif

#define WIN		1
#define MAC		2
#define	LINUX	3
#define CUR_OS	WIN


void main()
{
	// ##2. #if ~ #endif
	// #if 뒤의 값이 참이면 컴파일 대상, 거짓이면 컴파일 대상에서 제외.

#if 1
	cout << "Hello World" << endl;
#endif

	//////////////////////////////


#if (CUR_OR == WIN)
	cout << "WINDOW 전용" << endl;
#elif(CUR_OR == MAC)
	cout << "MAC 전용" << endl;
#end
	cout << "LINUX 전용" << endl;
#endif

	system("pause");
	return;
}