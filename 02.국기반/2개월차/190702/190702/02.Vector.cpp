#include<iostream>
#include<vector>

using namespace std;

// ##1. 반복자 (iterator)
// 컨테이너마다(자료구조마다) 원소를 저장하고 접근하는 방식이 모두 다르다.
// 원소에 접근하기 위한 방법을 통일 시켜놓은 것이 바로 반복자이다.
// 컨테이너마다 내부에 반복자 타입이 정의되어 있음.

// 반복자의 기본역할.
// 1. 원소의 위치를 가리킨다. (이를 통해 원소에 접근할 수 있음.)
// 2. 반복자를 통해서 컨테이너를 순회할 수 있다.

void main()
{
	//// ##2. vector의 반복자 선언

	//vector <int> vec;

	////반복자 선언
	//vector<int>::iterator	iter;

	//// ##3. 반복자를 통한 vecotr의 원소접근
	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	//// begin함수 : 가장 첫번째 원소의 위치를 가리키는 반복자를 리턴.
	//vector<int>::iterator iter_begin = vec.begin();

	//// 반복자에게는 *역참조 연산자가 오버로딩.
	//// cout << *iter_begin << endl; // 현재 가리키고 있는 위치의 값.
	//// cout << iter_begin << endl; // 포인터가 아니다!!!!!!!!!!!


	//// end함수 : 가장 마지막 원소 "다음" 위치를 가리키는 반복자를 리턴.
	//vector<int>::iterator iter_end = vec.end();


	//// 반복자를 이용한 원소순회
	//// 반복자에게는 비교 연산자, 증감 연산자가 오버로딩
	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	// ##4. 비어있는 컨테이너의 begin과 end는 같은 위치이다.

	//vector<int> vec;
	//if (vec.begin() == vec.end())
	//{
	//	cout << "비어있음" << endl;
	//}


	// ##5. vector는 임의접근 반복자를 제공한다.
	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	////vector<int>::iterator iter_begin = vec.begin();

	////cout << iter_begin[2] << endl;
	////cout << *(iter_begin + 2) << endl;	// 순방향 임의접근 ok

	//vector<int>::iterator iter_end = vec.end();

	//cout << *(iter_end - 2) << endl;		// 역방향 임의접근 ok

	// ##6. vector의 중간 삽입

	//vector<int> vec;

	//vec.push_back(10);
	//vec.push_back(30);

	//// insert (where , value)
	////vec.insert(vec.begin() + 1, 20);

	////for (size_t i = 0; i < vec.size(); i++)
	////	cout << vec[i] << endl;


	//vector<int>::iterator iter_begin = vec.begin();
	//vector<int>::iterator iter_end = vec.end();
	//cout << &iter_begin << endl;
	//cout << &iter_end << endl;

	//// insert(where, value)
	//vec.insert(iter_begin + 1, 20);

	//// 중간 삽입 이후에 재할당 복사가 발생한다면
	//// 현재 반복자의 무효화도 같이 진행된다.
	//// 따라서 반복자를 새로 다시 받아와야 한다.
	//// 만약, 재할당 복사가 발생하지 않았다면
	//// begin은 그대로 사용 가능하지만 end는 항상 새로 받아와야한다.

	//iter_begin = vec.begin();
	//iter_end = vec.end();

	//cout << &iter_begin << endl;
	//cout << &iter_end << endl;

	// for (; iter_begin != iter_end; iter_begin++)
	// 	cout << *iter_begin << endl;


	// ##7. vector의 중간 삭제

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);


	vector<int>::iterator iter_begin = vec.begin();
	vector<int>::iterator iter_end = vec.end();
	vector<int>::iterator iter_next;

	// erase(where)
	iter_next = vec.erase(iter_begin + 1);

	// erase는 삭제한 다음 위치를 반환한다.
	cout << *iter_next << endl;

	//vec.erase(iter_begin + 1);
	cout << "-------------------------------" << endl;
	// 원소 삭제 이후 begin은 상관 없지만 end는 항상 갱신.

	iter_end = vec.end();

	for (; iter_begin != iter_end; iter_begin++)
		cout << *iter_begin << endl;


	return;
}