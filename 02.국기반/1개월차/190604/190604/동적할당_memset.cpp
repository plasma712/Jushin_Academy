#include <iostream>

using namespace std;

// char* InputString()
// {
// 	char* ptr = (char*)calloc(32, sizeof(char));
// 
// 	cout << "문자열 입력:";
// 	cin >> ptr;
// 
// 	return ptr;
// }

void main()
{
	// char* pName = InputString();
	// cout << "출력 : " << pName << endl;
	// 
	// free(pName);
	// pName = nullptr;

	// ******* malloc와 calloc의 차이

	int* ptr_1 = (int*)malloc(3 * sizeof(int)); // 쓰레기값 갖음

	// 메모리 초기화 함수.
	// memset(메모리 시작번지, 초기화값, 초기화할 메모리 전체 크기
	memset(ptr_1, 0, 3 * sizeof(int));	
	for (int i = 0; i < 3; i++)
		cout << ptr_1[i] << endl;
	free(ptr_1);

	// for (int i = 0; i < 3; i++)
	// 	cout << ptr_1[i] << endl;
	// 
	// cout << "-------------------------------------" << endl;
	// 
	// int* ptr_2 = (int*)calloc(3, sizeof(int)); // 0 초기화
	// 
	// for (int i = 0; i < 3; i++)
	// 	cout << ptr_2[i] << endl;
	// 

	
	// free(ptr_1);
	// free(ptr_2);

}