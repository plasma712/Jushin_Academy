#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// �� ��ȯ (Swap)

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
			iScr�� ���� 4��� �����ϰ�
			iDst�� ���� 17�̶�� ������ ��,

			Swap�� ���ؼ� �迭 4���� 17���� ��� ���� ���׹��׵�.

			�� 
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