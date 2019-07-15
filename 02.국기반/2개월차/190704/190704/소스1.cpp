#include<iostream>
#include<list>
using namespace std;

void main()
{

	// ##1. list의 반복자
	// list는 양방향 순회를 제공한다.
	//list <int> MyLst;

	//MyLst.push_back(10);
	//MyLst.push_back(20);
	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);

	//list<int>::iterator iter_begin = MyLst.begin();
	//list<int>::iterator iter_end = MyLst.end();

	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	//cout << "--------------------------------------" << endl;


	//iter_begin = MyLst.begin();
	//iter_end = MyLst.end();

	//// 역방향 순회

	//for (; iter_begin != iter_end; )
	//	cout << *(--iter_end) << endl;


	// ##2. reverse함수

	//list <int> MyLst;

	//MyLst.push_back(10);
	//MyLst.push_back(20);
	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);

	//MyLst.reverse();

	//list<int>::iterator iter_begin = MyLst.begin();
	//list<int>::iterator iter_end = MyLst.end();

	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	//// ##3. list 중간삽입
	//list <int> MyLst;

	//MyLst.push_back(10);
	//MyLst.push_back(30);

	//list<int>::iterator iter_begin = MyLst.begin();
	//list<int>::iterator iter_end = MyLst.end();

	//iter_begin++;
	//iter_begin++;
	//iter_begin++;


	// list는 중간 삽입 이후에도 end의 무효화가 일어나지 않는다.
	//MyLst.insert(iter_begin, 20);
	
	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	// ##4. list 중간삭제
	list <int> MyLst;

	MyLst.push_back(10);
	MyLst.push_back(30);

	list<int>::iterator iter_begin = MyLst.begin();
	list<int>::iterator iter_end = MyLst.end();

	iter_begin++;
	MyLst.erase(iter_begin);

	// 중간 삭제 이후 삭제된 위치의 반복자는 무효화가 일어났으므르로
	// 다시 초기화하거나 erase반환으로 다음 위치를 받아주면 된다.
	// list는 중간 삭제 이후에는 end의 무효화가 일어나지 않음.

	for (iter_begin=MyLst.begin(); iter_begin != iter_end; iter_begin++)
		cout << *iter_begin << endl;


	return;
}