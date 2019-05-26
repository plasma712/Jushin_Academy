#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// ##1. 난수(random)
	// 무작위 수

	// 난수 뽑는 방법 (rand 함수)

	// time함수 : 현재 시간을 초단위로 얻어오는 함수.
	// 이 시간은 1970 1월 1일부터 현재까지 흘러온 시간을 초단위로 환산한 시간이다.

	// unsigned int iSeed = time(nullptr);
	// 
	// srand(iSeed);	// Seed 값 설정
	// 
	// int iA = rand()%10;
	// int iB = rand()%100;
	// int iC = rand()%1000;
	// 
	// cout << iA << endl;
	// cout << iB << endl;
	// cout << iC << endl;
	// 
	
	// time_t: 64비트 정수

	time_t iSeed = time(nullptr);

	srand((unsigned)iSeed);

	int iRand = 0;
	for (int i = 0; i < 10; i++)
	{
		iRand = rand();
		cout << iRand << endl;
		cout << "-------" << endl;
	}
	return;
}