#include <iostream>

using namespace std;

void main()
{
	// // ##1. 파일 입출력 (데이터 불러오기, 저장)
	// // 콘솔 입출력시 표준 입출력 스트림을 운영체제가 알아서 할당 및 소멸 해줬었다.
	// // 파일 입출력 시 입출력 스트림을 운영체제에게 할당 및 소멸을 요청.
	// 
	// // ##2. 파일 출력 (데이터 저장)
	// 
	// // 스트림 생성 요청 (파일 개방)
	// FILE* fp = nullptr;
	// 
	// // 파일 개방에 성공하면 0반환. 실패하면 0이 아닌 값 반환.
	// // fopen_s(스트림의 포인터, 파일경로, 출력(w) or 입력(r))
	// //errno_t err = fopen_s(&fp, "C:/Users/Plasma/Desktop/쥬신게임아카데미/02.국기반/190607/Data/test.txt","w");
	// 
	// errno_t err = fopen_s(&fp,/*상대경로*/"../Data/test.txt", "w");
	// 
	// if (err == 0)
	// {
	// 	fputs("Hello world", fp);
	// 	cout << "파일 저장 성공" << endl;
	// 	
	// 
	// 	// 스트림 소멸 요청.
	// 	fclose(fp);
	// }
	// else
	// 	cout << "파일 개방 실패" << endl;

	// ##3. 파일 입력 (데이터 불러오기)

	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test.txt", "r");
	// 
	// if (err == 0)
	// {
	// 	char szInput[32] = "";
	// 
	// 	fgets(szInput, 32, fp);
	// 
	// 	cout << szInput << endl;
	// 	cout << "불러오기 성공" << endl;
	// 
	// 	fclose(fp);
	// }
	// else
	// 	cout << "파일 개방 실패" << endl;

	// ##4. 개방모드
	// w(write) : 출력(덮어쓰기) 기존 파일이 없다면 새로 생성
	// a(apped) : 출력(이어쓰기) 기존 파일이 없다면 새로 생성
	// r(read) : 입력, 기존 파일이 없다면 에러.

	// t(text mode) : 사람이 식별할 수 있는 텍스트 형식으로 파일 입출력.
	// b(binary mode) : 텍스트로 표현할 수 없는 (동영상, 음원, 이미지 등) 형식의 파일 입출력

	// ##5. 파일의 끝은 EOF로 검사해야한다.

	// FILE* fp = nullptr;
	// errno_t err = fopen_s(&fp, "../Data/test.txt", "rt");
	
	// if (err == 0)
	// {
	// 	int ch = 0;
	// 	while (true)
	// 	{
	// 		ch = fgetc(fp);
	// 
	// 		// null문자는 파일에 저장되어있지 않다.
	// 		//if (ch == '\0')
	// 		//	break;
	// 
	// 		// 파일의 끝에는 EOF(-1)이 기록되어 있음.
	// 
	// 		if (ch == EOF)
	// 			break;
	// 
	// 		putchar(ch);
	// 	}
	// }
	// else
	// 	cout << "파일 개방 실패" << endl;


		
	return;
}