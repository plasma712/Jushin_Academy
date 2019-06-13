#include <iostream>
using namespace std;

// ##1. 포인터 (pointer)

// 참조 행위 : 메모리에 접근하는 행위.
// 간접 참조 : 주소를 통한 메모리 접근 -> 포인터 
// 직접 참조 : 변수를 통한 메모리 접근 / 레퍼런스를 통한 메모리 접근.
void MyFunc(int _in)
{
	_in++;
}

void MyFunc_Two(int* ptr)
{
	(*ptr)++;
}

void main()
{
	// ##1. call by value와 call by pointer
	// int iA = 10;
	// MyFunc(iA); // call by value
	//
	// MyFunc_Two(&iA); // call by pointer (포인터를 통해 인자의 값을 바꿀 수 있다.)
	// 
	// cout << iA << endl;

	// ##2. & (어드레스 연산자)
	// int iA = 10, iB = 20, iC = 30;
	// 
	// cout << "iA의 값" << iA << endl;
	// cout << "iA의 주소 : " << &iA << endl;
	// cout << "------------------------" << endl;
	// 
	// cout << "iB의 값" << iB << endl;
	// cout << "iB의 주소 : " << &iB << endl;
	// cout << "------------------------" << endl;
	// 

	// cout << "iC의 값" << iC << endl;
	// cout << "iC의 주소 : " << &iC << endl;
	// cout << "------------------------" << endl;

	// ##3. 포인터 선언
	// 포인터란, 주소를 저장하고 있는 변수.
	int iA = 10;

	// 포인터 선언 
	// int *ptr = &iA; // ptr이 iA를 가리킨다. 
	// int * ptr = &iA; 다 같은 의미
	// int* ptr = &iA; 



	// // 간접참조
	// *ptr = 200;
	// 
	// cout << "iA의 값 :" << iA << endl;
	// cout << "iA의 주소 : " << &iA << endl;
	// 
	// cout << "ptr의 값 : " << ptr << endl;

	// ##1. call by value와 call by pointer
	// int iA = 10;
	// MyFunc(iA); // call by value
	//
	// MyFunc_Two(&iA); // call by pointer (포인터를 통해 인자의 값을 바꿀 수 있다.)
	// 
	// cout << iA << endl;

	// ##4. 포인터의 크기
	int*		ptr1 = nullptr;	// 포인터를 0으로 초기화한다.
	double*		ptr2 = nullptr;
	char*		ptr3 = nullptr;

	cout << sizeof(ptr1) << endl; // 포인터는 변수에 상관없이 같은 크기를 갖는다.
	cout << sizeof(ptr2) << endl; // 32비트는 4바이트 , 64비트는 8바이트
	cout << sizeof(ptr3) << endl;


	return;
}