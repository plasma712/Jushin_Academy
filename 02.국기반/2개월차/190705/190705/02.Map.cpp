#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

class cCompare
{
private:
	const char* m_pString;
public:
	cCompare(const char* pStirng)
		:m_pString(pStirng){}
public:
	bool operator()(map<const char*, int>::value_type MyPair)
	{
		if(!strcmp(m_pString,))
	}
};

void main()
{
	// ##1. map 반복자
	//map<int, int> Mymap;

	//Mymap.insert(map<int, int>::value_type(1, 100));
	//Mymap.insert(map<int, int>::value_type(2, 200));
	//Mymap.insert(map<int, int>::value_type(3, 300));

	//map<int, int> ::iterator iter_begin = Mymap.begin();
	//map<int, int> ::iterator iter_end = Mymap.end();

	//// 순방향 순회
	//iter_begin++;
	//iter_begin++;

	//// map의 반복자는 -> 연산자 오버로딩
	//cout << iter_begin->first << " , " << iter_begin->second << endl;
	//cout << "---------------------------------------------------" << endl;
	//

	//// 역방향 순회
	//iter_begin--;
	//cout << iter_begin->first << " , " << iter_begin->second << endl;
	//cout << "---------------------------------------------------" << endl;


	//// ##2. find 함수

	//map<int, int> Mymap;

	//Mymap.insert(make_pair(1, 100));
	//Mymap.insert(make_pair(3, 300));
	//Mymap.insert(make_pair(2, 200));


	//// find(key) -> 이진탐색
	//// key에 해당하는 반복자를 리턴.

	//map<int, int> ::iterator iter_find = Mymap.find(2);


	//// 찾지 못하면 end반환
	//if (Mymap.end() == iter_find)
	//{
	//	cout << "탐색 실패" << endl;
	//	return;
	//}

	//cout << iter_find->first << " , " << iter_find->second << endl;
	
	// ##3. find_if 함수 <algorithm> 에서제공
	map<const char*, int> Mymap;
	// map<string, int> Mymap;
	Mymap.insert(make_pair("BBB", 200));
	Mymap.insert(make_pair("AAA", 100));
	Mymap.insert(make_pair("CCC", 300));

	// char szBuffer[32] = "AAA";
	// map<const char*, int> ::iterator iter_find = Mymap.find("szBuffer");

	// 단순 주소 탐색 (주소 비교)
	// map<const char*, int> ::iterator iter_find = Mymap.find("AAA");

	// 실제 문자열을 비교하여 탐색.
	// find_if(begin,end,단항조건자) -> 순차 탐색
	// 단항 조건자가 반환한 true에 해당하는 반복자를 리턴

	map<const char*,int> ::iterator iter_find = 
		find_if(Mymap.begin(),Mymap.end(),)

	if (Mymap.end)
	{
		cout << "탐색 실패" << endl;
		return;
	}


	cout << iter_find->first << " , " << iter_find->second << endl;

}