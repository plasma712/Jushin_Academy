#include<iostream>
#include<algorithm>
#include<vector>
#include <functional>

using namespace std;

bool IsEven(int n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
};

void SafeDelete(int*& ptr)
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void Print(int n)
{
	cout << n << endl;
}

bool Greater(int a, int b)
{
	return a > b;
}

void main()
{
	// ##1. count_if 알고리즘 함수.
	// 컨테이너가 갖고 있는 원소 중에 조건에 맞는 원소가 몇개 있는지 세어주는 함수.
	//int iArr[5] = { 1,2,3,4,5 };
	//// int count_if(begin, end, 단항조건자)
	//int iCount = count_if(iArr, iArr + 5, IsEven);
	//cout << "짝수의 개수 : " << iCount << "개 입니다." << endl;


	// Vector 대상으로 count_if;
	//vector<int> vec{ 1,2,3,4,5 }; // 유니폼 초기화(c++ 11이상)


	//int iCount = count_if(vec.begin(), vec.end(), IsEven);
	//cout << "짝수의 개수 : " << iCount << "개 입니다." << endl;

	// ##2. for_each 알고리즘 함수. <algorithm>에서 제공

	//vector<int*> vec;

	//vec.push_back(new int);
	//vec.push_back(new int);
	//vec.push_back(new int);
	//
	//// 현재 컨테이너를 순회하면서
	//// 세번째 인자로 전달 받은 함수를 반복 호출하고 있는 형태의 알고리즘


	//for_each(vec.begin(), vec.end(), SafeDelete());
	//vec.clear();

	// ##3. sort 알고리즘 <algorithm>에서 제공
	vector<int> vec{ 5,1,4,3,2 };
	sort(vec.begin(), vec.end()); // 기본 오름차순 제공
	sort(vec.begin(), vec.end(), Print);

	// sort 함수는 이항조건자를 만든다.
	


	// begin과 end는 임의접근 가능야한다.
	for_each(vec.begin(), vec.end(), Greater);

	greater<int> functor;
	sort(vec.begin(), vec.end(), functor);
	sort(vec.begin(), vec.end(), Greater); // 조건자를 이용한 내림차순


	// <functional에서 제공하는 함수객체
	// less<ing> 

	return;
}