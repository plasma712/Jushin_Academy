#include <iostream>

using namespace std;

typedef struct
{
	int x, y;
}MY_POINT;


void main()
{
	// ##1. ���̳ʸ���� ���� ���.
	// int iArray[5] = { 10,20,30,40,50 };
	// 
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test3.txt", "wb");
	// 
	// if (err == 0)
	// {
	// 	// ���̳ʸ���� ��� �Լ�.
	// 	// fwrite(�޸� ù�ּ�, ����ũ��, ���� ����, ��½�Ʈ��)
	// 	//fwrite(iArray,sizeof(int),5,fp);
	// 	fwrite(iArray, sizeof(iArray), 1, fp);
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "���� ���� ����" << endl;
	
	// ##2. ���̳ʸ���� ���� �Է�.
	// int iArray[5] = {};
	// 
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test3.txt", "rb");
	// 
	// if (err == 0)
	// {
	// 	// ���̳ʸ���� �Է��Լ�
	// 	// fread(�Է¹��� �޸� ù �ּ�, ����ũ��, ���Ұ���, �Է� ��Ʈ��)
	// 	fread(iArray, sizeof(int), 5, fp);
	// 
	// 	for (int i = 0; i < 5; i++)
	// 		cout << iArray[i] << endl;
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "���� ���� ����" << endl;

	MY_POINT tPostion = { 100,200 };

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/test4.txt", "wb");



	return;
}