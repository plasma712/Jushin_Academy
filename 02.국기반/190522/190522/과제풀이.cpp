#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// 값 교환 (Swap)

	//	int iA = 10, iB = 20, iC = 0;
	//	
	//	iA = iB;
	//	iB = iA;
	//	iB = iC;
	//	
	//	cout << iA << " , " << iB << endl;

	srand((unsigned)time(nullptr));

	int iArray[45] = {};
	int iLotto[6] = {};

	int iScrIndex = 0;
	int iDstIndex = 0;
	int iTemp = 0;

	for (int i = 0; i < 5000; i++)
	{
		/*
			iScr의 값이 4라고 가정하고
			iDst의 값이 17이라고 가정할 때,

			Swap을 통해서 배열 4번과 17번에 담긴 값이 뒤죽박죽됨.

			즉 
		*/

		iScrIndex = rand() % 45;
		iDstIndex = rand() % 45;

		// Swap
		iTemp = iArray[iScrIndex];
		iArray[iScrIndex] = iArray[iDstIndex];
		iArray[iDstIndex] = iTemp;
	}

	return;
}