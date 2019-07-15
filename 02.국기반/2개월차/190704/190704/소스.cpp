#include <iostream>
#include <list>

using namespace std;

// ##1. STL list
// 양방향 연결 리스트 기반이다. (더블 링크드 리스트)
// 표준 시퀀스 컨테이너이다.    (원소배치가 선형적이다.)
// 노드기반 컨테이너이다.		(비연속적인 메모리를 사용한다.)
// 임의접근이 불가능하고 오로지 순차접근만 허용한다. -> 탐색에 불리.
// 벡터와 달리 한정된 메모리가 아니기에 빈번한 삽입, 삭제에 유리하다.



void main()
{
	// ##2. List 선언
	// list<int>		MyLst1;
	// list<double>		MyLst2;
	// list<클래스명>	MyLst3;
	// list<구조체명>	MyLst4;

	// ##3. List 원소 삽입.

	//list<int>	MyLst;

	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);

	//// 범위 기반 for문으로 순회 가능.
	//for (int element : MyLst)
	//	cout << element << endl;

	//cout << "Size: " << MyLst.size() << endl;				// 원소 개수
	//cout << "--------------------------------------" << endl;

	//MyLst.push_front(20);
	//MyLst.push_front(10);

	//for (int element : MyLst)
	//	cout << element << endl;

	//cout << "Size: " << MyLst.size() << endl;				// 원소 개수
	//cout << "--------------------------------------" << endl;


	//list<int>	MyLst;

	//MyLst.push_back(10);
	//MyLst.push_back(20);
	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);

	//for (int element : MyLst)
	//	cout << element << endl;
	//cout << "--------------------------------------" << endl;

	//MyLst.pop_back();	// 가장 마지막 원소 제거

	//for (int element : MyLst)
	//	cout << element << endl;
	//cout << "--------------------------------------" << endl;


	//MyLst.pop_front();	// 가장 첫 원소 제거


	//list<int>	MyLst;

	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);


	//// front와 backㅇ느 가장 첫원소와 마지막원소의 원본을 반환
	//cout << "front : " << MyLst.front() << endl;
	//cout << "back : " << MyLst.back() << endl;

	//MyLst.push_front(20);
	//cout << "front : " << MyLst.front() << endl;

	//// cout << MyLst[2] << endl; // error  임의접근 불가


	// ##5. vector와 동일하게 front, back, empty, clear, swap, size 등의 함수를 제공해준다.
	list<int> MyList;

	return;
}