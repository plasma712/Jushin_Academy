#include <iostream>

using namespace std;

// 지역 변수
// { } 안에 선언된 변수를 말하며 선언된 { } 안에서만 접근할 수 있다.

void MyFunc()
{
	int iA = 10, iB = 20;
	int iC = 100;
}


void main()
{
	// iA와 iB는 MyFunc함수의 지역에 선언되어 있으므로 접근 불가!
	// cout << iA << " , " << iB << endl;


	// 이름은 같을지라도 지역이 다르면 전혀 다른 변수이다.
	// int iC = 1000;
	// cout << iC << endl;

	// for (int i = 0; i < 10; i++)
	// {
	// 	int iA = 0;
	// 	iA += i;
	// }

	// cout << i << endl;	 // error 
	// cout << iA << endl;	 // error 

	// if (true)
	// {
	// 	int iA = 100;
	// } 해당 지역을 벗어나는 순간 iA는 Stack에서 소멸.
	//  
	// cout << iA << endl; // error

	return;
}