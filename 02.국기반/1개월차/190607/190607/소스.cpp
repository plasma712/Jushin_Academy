#include <iostream>

using namespace std;

typedef struct
{
	int x, y;
}MY_POINT;


void main()
{
	// ##1. 바이너리모드 파일 출력.
	// int iArray[5] = { 10,20,30,40,50 };
	// 
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test3.txt", "wb");
	// 
	// if (err == 0)
	// {
	// 	// 바이너리모드 출력 함수.
	// 	// fwrite(메모리 첫주소, 원소크기, 원소 개수, 출력스트림)
	// 	//fwrite(iArray,sizeof(int),5,fp);
	// 	fwrite(iArray, sizeof(iArray), 1, fp);
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "파일 개방 실패" << endl;
	
	// ##2. 바이너리모드 파일 입력.
	// int iArray[5] = {};
	// 
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test3.txt", "rb");
	// 
	// if (err == 0)
	// {
	// 	// 바이너리모드 입력함수
	// 	// fread(입력받을 메모리 첫 주소, 원소크기, 원소개수, 입력 스트림)
	// 	fread(iArray, sizeof(int), 5, fp);
	// 
	// 	for (int i = 0; i < 5; i++)
	// 		cout << iArray[i] << endl;
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "파일 개방 실패" << endl;

	MY_POINT tPostion = { 100,200 };

	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/test4.txt", "wb");



	return;
}