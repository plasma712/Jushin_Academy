#pragma once	// 마이크로소프트사에서 제공하는 헤더중복 방지

#ifndef __VendingMachine_H__	 // 중복헤더방지용. 호환성을 위해서 이용.
#include <iostream>

using namespace std;

#define CLIENT

void main()
{
	// ##1. ifdef ~ #endif
	// 해당 매크로가 정의되어 있다면 컴파일 수행, 아니라면 컴파일 제외
	// #elif를 사용할 수 없음. 무조건 모 아니면 도

	// #ifdef CLIENT
	// 	cout << "클라이언트 실행" << endl;
	// #else
	// 	cout << "서버 실행" << endl;
	// #endif

	// ##2. #ifdef ~ #endif
	// 해당 매크로가 정의되어 있지 않으면 컴파일 수행. 정의되어 있으면 컴파일 제외.

#ifndef CLIENT
	cout << "서버 이용" << endl;
#else
	cout << "클라이언트 실행" << endl;
#endif


	system("pause");
	return;
}
#define __VendingMachine_H__
#endif // !__VendingMachine_H__