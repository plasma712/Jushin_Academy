#include <iostream>

using namespace std;


// ** 함수 객체 오버로딩이 갖는 장점.
// 1. 내부정의로 인한 인라인 화가 일어날 수 있다. (함수 포인터에 비해 속도가 빠르다.) // 함수 포인터는 인라인 화가 아예 불가능.
// 2. 클래스로 만들기 때문에 멤버변수를 갖을 수 있다.
// 3. 함수 포인터의 경우 타입이 우연히라도 동일시 하다면, 함수포인터가 호출 될 수 있다.
//    하지만 함수 객체 오버로딩은 자식 클래스가 아닌 이상 받을 수 가 없다.
// 4. 클래스가 가진 4대 속성을 모두 사용 할 수 있다.
class cSortRule
{
public:
	
	virtual bool operator()(int a, int b) = 0;
};

// 내림차순
class cGreater : public cSortRule
{
public:
	virtual bool operator() (int a, int b)
	{
		return a > b; // 정렬 방향. (뒤로 갈수록 작아져야 한다는 의미)
	}
};

// 오름차순
class cLess : public cSortRule
{
public:
	virtual bool operator() (int a, int b)
	{
		return a < b; // 정렬 방향. (뒤로 갈수록 작아져야 한다는 의미)
	}

};

void BubbleSort(int ptr[], int length, cSortRule& functor)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (functor(ptr[j + 1], ptr[j]))
			{
				int itemp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = itemp;
			}
		}
	}
}



void main()
{
	cLess less;
	cGreater greater;


	int iArr[5] = { 5,1,4,3,2 };

	BubbleSort(iArr, 5, less ); // 임시객체 호출 ... 확인해보기

	for (int i = 0; i < 5; i++)
	{
		cout << iArr[i] << endl;
	}

	return;
}