#include <iostream>

using namespace std;

void main()
{
	// ##1. 포인터 0 초기화
	// int* ptr = nullptr;
	// 
	// if (nullptr != ptr)	// null 체크 습관화!
	// 	*ptr = 100;

	// ##2. 포인터와 const
	// int iA = 10, iB = 20;

	//
	// const int* ptr1 = &iA; // const 역참조에 의한 iA의 값을 변경하지 못하게 함.
	// *ptr1 = 200;	// error
	// ptr1 = &iA;		

	// int* const ptr2 = &iA; // ptr2자체에 상수를 통해 ptr2를 변경 불가능
	// *ptr2 = 200;	// ok
	// ptr2 = &iB;		// error

	
	// const int* const ptr3 = &iA; // 둘다 변경 X
	// *ptr3 = 200;  // error
	// ptr3 = &iB;	  // error

	// const int iC = 200; // const 변수에 대한 포인터.
	// 
	// const int* ptr4 = &iC;



	return;
}