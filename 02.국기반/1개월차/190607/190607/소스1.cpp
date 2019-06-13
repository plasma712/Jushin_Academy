#include <iostream>

using namespace std;

void main()
{
	// ##1. 파일 지시자.
	// FILE 구조체 내부에는 파일 지시자가 존재한다.
	// 파일 지시자의 역할은 파일의 내용을 읽거나 출력할 때 어디서부터 시작할 것인지
	// 현재 위치를 가리키고 있다
	// 파일 입출력 할 때마다 파일 지시자의 위치는 양의 방향으로 움직이며 갱신.
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");

	// test2.txt에는 "123456789"가 기록되어있는 상태.
	// 처음 파일 지시자는 '1'의 위치를 가리키고 있음.
	// int ch = fgetc(fp); // 


	// ##2. fseek 함수.
	// 파일 지시자의 위치를 제어하는 함수.

	//FILE* fp = nullptr;
	//errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");
	//
	//if (err == 0)
	//{
	//	// SEEK_SET : 처음위치부터
	//	// 3: 1바이트씩 세칸 이동
	//	fseek(fp, 3, SEEK_SET);
	//
	//	int ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	// SEEK_CUR: 현재 지시자의 위치
	//	fseek(fp, 0, SEEK_CUR);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	fseek(fp, -3, SEEK_END);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//	fseek(fp, 0, SEEK_CUR);
	//	ch = fgetc(fp);
	//	putchar(ch);
	//	putchar('\n');
	//	cout << "------------------------------" << endl;
	//
	//
	//	fclose(fp);
	//}


	// ##3. ftell 함수.
	// 현재 파일 지시자의 위치를 알려주는 함수.
	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");
	// 
	// if (err == 0)
	// {
	// 	long index = ftell(fp);
	// 	cout << "현재 지시자의 위치" << endl;
	// 	cout << "---------------------------" << endl;
	// 
	// 	int ch = fgetc(fp);
	// 	putchar(ch);
	// 	putchar('\n');
	// 
	// 	index = ftell(fp);
	// 	cout << "현재 지시자의 위치" << endl;
	// 	cout << "---------------------------" << endl;
	// }


	// ##4. feof함수
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../Data/test2.txt", "rt");

	if (err == 0)
	{
		int ch = 0;
		while (true)
		{
			ch = fgetc(fp);

			// 현재 파일 지시자가 EOF에 도달했는지 검사하는 함수.
			// 도달 했다면 true

			if (feof(fp))
				break;

			putchar(ch);
		}
		fclose(fp);
	}


	return;
}