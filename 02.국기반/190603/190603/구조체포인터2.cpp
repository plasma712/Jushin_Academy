#include <iostream>

using namespace std;

struct tagPoint
{
	int x, y;
};


void Swap(int* _ix,int* _iy)
{
	int iTemp = 0;
	iTemp = *_ix;
	*_ix = *_iy;
	*_iy = iTemp;
}

void Swap(tagPoint* pPos)
{
	int iTemp = pPos->x;
	pPos->x = pPos->y;
	pPos->y = iTemp;
}

void main()
{
	// 문제 1. x, y 값을 Swap함수를 통해 맞교환하기.

	tagPoint tPos = { 100,200 };

	Swap(&tPos.x, &tPos.y);

	cout << tPos.x << endl;
	cout << tPos.y << endl;

	Swap(&tPos);

	cout << tPos.x << endl;
	cout << tPos.y << endl;
	cout << sizeof(&tPos) << endl;

	return;
}