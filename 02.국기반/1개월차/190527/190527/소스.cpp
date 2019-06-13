#include <iostream> 

using namespace std;

static int iMyGlobal;

int MyFunc(int n = 0)
{
	//int iA = 0;
	// static 변수(정적변수) : Data영역에 등록되는 변수다.
	static int iA = 0;  // 최초 한번만 초기화 수행
	iA += n;
	return iA;
}

void main()
{
	static int iMyStatic;

	// 전역변수와 정적(Static)변수는 초기화를 0으로 자동으로 해준다.(초기화 안해줄경우)
	cout << iMyGlobal << endl;
	cout << iMyStatic << endl;



	// for (int i = 0; i < 5; i++)
	// 	MyFunc(10);
	// 
	// cout << MyFunc() << endl;
	// cout << iA << endl; // erorr, 정적변수는 지역적 접근특성을 갖는다.
	// return;
}