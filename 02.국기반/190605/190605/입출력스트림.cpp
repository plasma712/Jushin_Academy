#include <iostream> 

using namespace std;

void main()
{
	// ##1. 입출력 스트림 
	// 스티림 : 데이터 통신에 필요한 가상의 연결통로. 단방향 흐름을 갖는다.

	// 표준 입력 스트림 : stdin
	// 표준 출력 스트림 : stdout
	// 입출력 스트림은 os가 알아서 할당 및 소멸 시켜준다.

	// ##2. 입출력 버퍼
	// 데이터 송수신의 효율성 때문에 필요한 임시 공간.

	// ##3. 단일 문자 출력 함수
	// putchar, fputc

	// putchar('A'); // stdout(표준 출력 스트림)을 통해 모니터로 문자 출력.
	// putchar와 달리 스트림을 지정할 수 있다. 출력 대상이 모니터가 아닐 수 도 있다.
	// fputc('A',stdout); 

	// ##4. 단일문자 입력 함수
	// 입력버퍼에서 문자를 하나씩 꺼내오는 함수. (FIFO) /선입선출
	// getchar, fgetc
	// 함수 호출에 실패하거나 더이상 읽어올 문자가 없다면 EOF(-1)를 반환.
	// EOF (End Of File)

	// int ch = getchar(); // stdin(표준 입력 스트림)을 통해 키보드로부터 문자 입력
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);
	// 
	// ch = getchar();
	// putchar(ch);

	// int ch = fgetc(stdin); // 스트림 지정 가능. 입력 대상이 키보드가 아닐 수도 있다.
	// fputc(ch, stdout);

	// ##5. 문자열 출력 함수
	// puts, fputs
	// puts("Hello"); // stdout을 통해 모니터로 문자열 출력. 자동 개행(O)
	// fputs("Hello", stdout); // 스티림 지정 가능. 자동 개행(X)

	// ##6. 문자열 입력 함수
	// 입력버퍼로부터 문자열을 문장 단위(\n)로 읽어오는 함수.
	// gets_s, fgets

	char szName[32] = "";
	
	// gets_s(char배열 주소, 배열 크기)
	// \n이 입력버퍼에 존재하나 읽어들이지 않고 버림.
	// 문자열 입력할 때 배열크기 넘어서지 않도록 주의.
	cout << "입력 : "; gets_s(szName, 32); // stdin을 통해 문자열 입력.
	cout << "출력 : "; puts(szName);

	// fgets(char배열 주소, 읽어올 최대 길이, stream)
	// gets_s와 달리 \n도 읽어온다.
	cout << "입력 : "; fgets(szName, 7, stdin);
	cout << "출력 : "; fputs(szName, stdout);

	return;
}