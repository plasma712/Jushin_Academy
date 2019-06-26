#include <iostream> 
using namespace std;

// ##1. 매크로 : #define
// 전처리기의 일종으로 단순치환을 의미한다.

// ##2. 매크로상수
#define PI 3.14f
//#define PI 3.14f; 일경우 ; 도 복사가 되어 바로 끊김.


void main()
{
	// ##2. 매크로상수
	cout << PI << endl;	 // cout << 3.14f << endl;와 같은 의미
	cout << EOF << endl; // cout << -1 << endl; 와 같은 의미.

	cout << sizeof(PI) << endl;  // sizeof(3.14f);
	cout << sizeof(EOF) << endl; // sizeof(-1);
	system("pause");
	return;
}