#include <iostream>

using namespace std;

class cTest
{
private:

public:
	cTest()
	{
		cout << "생성자" << endl;
	}
	~cTest()
	{
		cout << "소멸자" << endl;
	}
};



void main()
{
	// ##1. 객체 배열
	
	// 정적 배열
	// cTest Arr[3] = {};

	// 동적 배열
	// cTest 객체를 heap공간에 연속되게 배치.
	cTest* ptr = new cTest[3]; // 생성자
	delete[] ptr;	// 소멸자

	// ##2. 객체 포인터 배열
	// cTest객체를 heap공간에 비연속되게 배치
	cTest* Arr[3] = {new cTest,new cTest, new cTest};
	delete[] Arr[0];
	delete[] Arr[1];
	delete[] Arr[2];


	system("pause");
	return;
}