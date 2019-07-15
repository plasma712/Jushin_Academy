// 트리
// 비선형구조
// 표준 연관 컨테이너.

// 최상위 노드 = ROOT 노드
// 자식이 없는 노드 = Leaf 노드
// 0개이상의 자식을 갖을 수 있다.(부모노드)


// MAP은 이진(+탐색)트리를 기반으로 이루어져있다.
// 부모노드 = 2개이하의 자식노드를 갖는다.
// 이진트리가 한쪽으로 치우쳐져 있으면 속도가 느려진다. (찾고자하는 값보다 큰 값을 잘라내야하는데 그걸 못함.)
// 이를 자가균형이진탐색트리를 이용하여 트리가 한쪽으로 치워쳐지지 않도록 한다.

// MAP의 특징
// 1. 노드에 있는 [KEY값 , Value값]중 KEY값은 중복이 되면 안된다.
// 2. KEY값은 대소비교만 할 수 있다면 어떠한 값이든 상관이없다.(구조체와 클래스의 경우 둘의 크기를 비교할 수 있는 오버로딩이 필요)

// 컨테이너
// 원소배치
// 표준 시퀀스 컨테이너
// vector, list, deque(배열기반의 컨테이너 재할당이 이루어지지 않는다. [deque1] - [deque2] - [deque3] : 연속된 공간은 아니다.

// 표준 연관 컨테이너
// map, multimap key와value사용 //, set , multiset key값만 사용 (중복가능한 것들이 있으니 확인할것.)

// 배열기반
// vector , deque

// 노드기반
// list, map , multi

// 컨테이너 어댑터
// 스택 , 큐 , 우선순위 큐

// 근사 컨테이너


#include <iostream>
#include <map>
using namespace std;

// ##1. map의 특징 
// 1. 자가균형 이진 탐색 트리를 기반으로 한다. (레드블랙트리)
// 2. 표준 연관 컨테이너
// 3. 노드 기반 컨테이너. list와 같은 노드 기반에 비해 탐색이 월등히 빠르다.
// 4. 원소 하나가 key, value 한쌍을 이룬다.
// 5. 원소를 삽입할 때마다 key를 기준으로 정렬이 일어난다. 삽입속도가 느리다.
// 6. 중복 key를 허용하지 않는다.
// 7. 노드 기반이지만 key를 통해 인덱스 연산할 수 있다. (key 탐색)
// 8. 한번 삽입된 Key는 수정할 수 없다.
//    - 수정하고 싶다면 해당 key의 원소를 삭제하고 새로 삽입해라.
//	  - 단, value는 수정 가능


void main()
{
	// ##2 pair 객체

	//pair<int, int> MyPair(1, 100);

	//pair<int, int> MyPair2;

	//MyPair2.first = 2;		// Key
	//MyPair2.second = 200;	// Value

	// ##3. map의 선언 map<key,value> 변수명
	//map<int, int>			Mymap1;
	//map<float, int>		    Mymap2;
	//map<string, 클래스명>	Mymap3;
	//map<클래스명, int>		Mymap4;
	//map<구조체명, float>	Mymap5;

	//// ##4. map의 데이터 삽입.
	//map<int, int> Mymap;

	//// 삽입 방법 첫번째 (pair 객체 활용)
	//pair<int, int> MyPair(2, 200);
	//Mymap.insert(MyPair); // 삽입 시 pair객체를 전달.

	//// 삽입 방법 두번째 (pair 임시객체 사용)
	//Mymap.insert(pair<int, int>(1, 100)); // 임시 객체 활용

	//// 삽입 방법 세번째 (make_pair함수 사용)
	//pair<int, int> MyPair2 = make_pair(5, 500);
	//Mymap.insert(MyPair2);

	//// make_pair함수 : 전달 된 인자에 맞게 pair객체를 생성하는 함수.
	//Mymap.insert(make_pair(4, 400));

	//// 삽입 방법 네번째 (map<key, value>::value_type 사용) // value 타입 = pair<const key, value>를 구조체화 시킨거기 때문에...
	//													   // 묵시적 형변환이 추가로 일어나지는 않는다. (다른것들은 const key값으로 
	//													   // 묵시적 형변환이 일어난다.
	//map<int, int>::value_type MyPair3(6, 600);

	////MyPair3.first = 7; // error KEY값 수정 불가
	//Mymap.insert(MyPair3);
	//Mymap.insert(map<int, int>::value_type(7, 700));


	//// map은 삽입 할 때 마다 Key를 기준으로 정렬을 수행한다.
	//for (map<int, int>::value_type element : Mymap)// 범위기반 포문
	//{
	//	cout << "Key : " << element.first << endl;
	//	cout << "Value : " << element.second << endl;
	//	cout << "-----------------------------" << endl;
	//}


	// ##5. map의 []->인덱스 연산.
	// key값을 통해 인덱스 연산이 가능하도록 오버로딩 되어있다.
	// 이는 연속된 배열과 같은 인덱스 연산이 아니라, 단순 이진탐색을 의미

	//map<int, int> Mymap;
	//
	//Mymap.insert(pair<int, int>(3, 300));
	//Mymap.insert(make_pair(2, 200));
	//Mymap.insert(map<int, int>::value_type(1, 100));

	//// cout << Mymap.begin() -> first << endl;

	////key 값으로 인덱스 연산을 수행하면 value의 원본을 리턴한다.
	//cout << Mymap[1] << endl;

	//Mymap[1] = 1000; // value수정가능

	//cout << Mymap.begin()->second << endl;

	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;
	//
	//Mymap[5];	//존재하지 않는 key로 인덱스 연산 수행 시 원소를 새로 만들어 버린다.

	//cout << "Mymap[5] : " << Mymap[5] << endl;
	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;

	//Mymap[6] = 600;	// 삽입이 이런식으로 가능하지만 사실은 value를 수정하는 행위

	//cout << "Mymap[6] : " << Mymap[6] << endl;
	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;


	//// ##6. 중복 key insert
	//map<int, int> Mymap;

	//Mymap.insert(make_pair(1, 100)); // 삽입 ok

	//// insert는 pair를 반환하는데 이 때 value는 bool 타입이다.
	//// 반환한 pair의 value가 false를 갖는다면 삽입 실패했다라는 의미

	//if (false == Mymap.insert(make_pair(1, 200)).second); // 삽입 no
	//{
	//	cout << "이미 존재하는 key입니다" << endl;
	//}
	//Mymap.insert(make_pair(1, 300)); // 삽입 no

	//cout << "size : " << Mymap.size() << endl;
	//cout << "value : " << Mymap[1] << endl;

	// ##7. map의 원소 삭제
	map<int, int> Mymap;

	Mymap.insert(make_pair(1, 100)); 
	Mymap.insert(make_pair(2, 200)); 
	Mymap.insert(make_pair(3, 300)); 

	for (map<int, int>::value_type element : Mymap)
		cout << element.first << " , " << element.second << endl;

	cout << "-------------------------------------------------------" << endl;

	Mymap.erase(2);

	for (map<int, int>::value_type element : Mymap)
		cout << element.first << " , " << element.second << endl;

	cout << "-------------------------------------------------------" << endl;


 
	

	return;
}