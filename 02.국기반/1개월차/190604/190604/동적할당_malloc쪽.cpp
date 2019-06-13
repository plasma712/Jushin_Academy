#include <iostream>

using namespace std;

// ##1. 동적할당 (Dynamic Allocation)

// Heap 영역 : 동적할당된 데이터가 등록되는 공간.
// 할당 시점 : 프로그래머가 원할 때 ("{"시작시)
// 소멸 시점 : 프로그래머가 원할 때 ("}"종료시)

// Stack의 문제점

// char* InputString()
// {
// 	char szInput[32] = "";
// 	cout << "문자열 입력: ";
// 	cin >> szInput;
// 
// 	return szInput; // 지역 변수의 주소를 반환하면 안된다. warnning (주소가 함수가 끝나면서 주소를 삭제해 이용이 불가능)
// }




void main()
{
	// char* pName = InputString();
	// cout << "출력: " << pName << endl;

	// ##1. C언어 기반의 동적할당 (Dynamic Allocation)
	
	// 1. malloc 함수
	// malloc(4); // = void* malloc(size_tSize) 반환값을 신경안쓰고 주소값 우선저장
	
	// int타입 4바이트 메모리를 Heap에 할당
	// ptr을 통해 해당 메모리에 접근 가능.
	// int* ptr = (int*)malloc(4);
	// 
	// *ptr = 100;
	// cout << *ptr << endl;
	// 
	// free(ptr); // 메모리 해제 함수.
	// ptr = nullptr;	//dangling 포인터 방지
	// 
	// if (nullptr != ptr)
	// 	*ptr = 200;

	// 2. calloc 함수

	// int 공간을 3번 연속되게 heap영역에 할당. ->동적 배열.
	// int* ptr = (int*)calloc(3, sizeof(int));
	// 
	// ptr[0] = 100;
	// ptr[1] = 200;
	// ptr[3] = 300;
	// 
	// cout << &ptr[0] << endl;
	// cout << &ptr[1] << endl;
	// cout << &ptr[2] << endl;

	// ##2. 동적 배열
	// 런타임 도중에 배열의 길이를 정할 수 있는 배열이다.
	// int iCount = 0;
	// 
	// cin >> iCount;
	// 
	// int* ptr = (int*)calloc(iCount, sizeof(int));
	// 
	// for (int i = 0; i < iCount; i++)
	// 	cout << (ptr[i] = i + 1) << endl;
	// 
	// free(ptr);
	// ptr = nullptr;

	// ##3. realloc함수
	int iCount = 0;
	
	cin >> iCount;

	int* ptr = (int*)malloc(iCount * sizeof(int));

	for (int i = 0; i < iCount; i++)
		cout << (ptr[i] = i + 1) << endl;

	cout << "------------------------------------------" << endl;

	cout << "배열의길이";
	cin >> iCount;

	int* ptr_2 = (int*)realloc(ptr,iCount * sizeof(int));
	// free(ptr); //ptr은 realloc함수 내부에서 해제되고 있으므로 따로 할당해제를 해줄 필요가 없다.

	for(int i =0;i<iCount;i++)
		cout << (ptr_2[i] = i + 1) << endl;



	return;
}