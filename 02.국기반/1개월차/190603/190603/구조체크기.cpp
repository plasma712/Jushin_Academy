#include <iostream>
using namespace std;

struct tagTest1
{
	short a; 
	int b;
	char c;
	double d;
};

struct tagTest2
{
	short a;
	char b;
	int c;
	double d;
};

struct tagTest3
{
	int a;
	char b;
	int c;
	tagTest2 d;
};

struct tagTest4
{
	int a;
	char b;
	int c;
	//tagTest4 d;
	tagTest4* d;	// 자기자신을 멤버로 갖을 때에는 크기가 정해져있는 포인터를 이용해야한다.
};

void main()
{
	// ##1. 구조체의 크기.
	// 멤버(기본자료형) 중 가장 큰 메모리를 기준으로 잡아나간다.
	// 32비트 환경에서는 4바이트씩 끊어서 처리, 64비트 환경에서는 8바이트씩 끊어서 처리
	cout << sizeof(tagTest1) << endl;
	cout << sizeof(tagTest2) << endl;
	cout << sizeof(tagTest3) << endl;

	return;
}