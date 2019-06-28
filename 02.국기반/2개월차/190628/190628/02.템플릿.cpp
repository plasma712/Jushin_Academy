#include <iostream>

using namespace std;

template <typename T>
int GetArraySize(T& r) // 템플릿을 이용한 배열 인자 받기
{
	return sizeof(r);
}

// auto 키워드로는 템플릿을 대체할 수 없다. 컴파일 시점에서 함수를 만들어야하는데,
// 아무런 정보가 있지 않기에.

// auto Add(auto a, auto b)
// {
// 	return a + b;
// }

template <typename T>
int GetArray(T& r) // 템플릿을 이용한 배열 인자 받기
{
	// 범위 기반 for문 (c++11 이상부터 지원)
	//	for (auto& element  : r)	//래퍼런스를 집어넣으면 element는 원본값.
	for (auto element  : r)	// auto 키워드 (C ++1 이상부터 지원) (element는 사본값)
		cout << r[] << endl;

	return sizeof(r);
}
template <typename T,int size>
int GetArraySize2(T(&r)[size]) // 템플릿을 이용한 배열 인자 받기
{
	for (int i = 0; i < size; i++)
		cout << r[i], < endl;

	return sizeof(r);
}


void main()
{
	int iArr[5] = { 0,1,2,3,4 };
	//int iArraySize = GetArraySize(iArr);
	//cout << iArraySize << "bytes" << endl;

	// int iArraySize = GetArraySize2(iArr);
	// cout << iArraySize << "bytes" << endl;
    // 

	int iArraySize = GetArray(iArr);
	cout << iArraySize << "bytes" << endl;
	/*
	int iArr[3][3] = {1,2,3,4,5,6,7,8,9};


	// 범위 기반 for문을 이용한 2차원 배열 다루기.
	for (auto& Array : iArr)
	{
		for(auto element : Array)
			cout<< element << '\t';

			cout << endl;
	}
	
	*/

	return;
}