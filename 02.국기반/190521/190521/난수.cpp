#include <iostream>
#include <time.h>
using namespace std;

void main()
{
	// ##1. ����(random)
	// ������ ��

	// ���� �̴� ��� (rand �Լ�)

	// time�Լ� : ���� �ð��� �ʴ����� ������ �Լ�.
	// �� �ð��� 1970 1�� 1�Ϻ��� ������� �귯�� �ð��� �ʴ����� ȯ���� �ð��̴�.

	// unsigned int iSeed = time(nullptr);
	// 
	// srand(iSeed);	// Seed �� ����
	// 
	// int iA = rand()%10;
	// int iB = rand()%100;
	// int iC = rand()%1000;
	// 
	// cout << iA << endl;
	// cout << iB << endl;
	// cout << iC << endl;
	// 
	
	// time_t: 64��Ʈ ����

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