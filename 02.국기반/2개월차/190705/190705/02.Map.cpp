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
	// ##1. map �ݺ���
	//map<int, int> Mymap;

	//Mymap.insert(map<int, int>::value_type(1, 100));
	//Mymap.insert(map<int, int>::value_type(2, 200));
	//Mymap.insert(map<int, int>::value_type(3, 300));

	//map<int, int> ::iterator iter_begin = Mymap.begin();
	//map<int, int> ::iterator iter_end = Mymap.end();

	//// ������ ��ȸ
	//iter_begin++;
	//iter_begin++;

	//// map�� �ݺ��ڴ� -> ������ �����ε�
	//cout << iter_begin->first << " , " << iter_begin->second << endl;
	//cout << "---------------------------------------------------" << endl;
	//

	//// ������ ��ȸ
	//iter_begin--;
	//cout << iter_begin->first << " , " << iter_begin->second << endl;
	//cout << "---------------------------------------------------" << endl;


	//// ##2. find �Լ�

	//map<int, int> Mymap;

	//Mymap.insert(make_pair(1, 100));
	//Mymap.insert(make_pair(3, 300));
	//Mymap.insert(make_pair(2, 200));


	//// find(key) -> ����Ž��
	//// key�� �ش��ϴ� �ݺ��ڸ� ����.

	//map<int, int> ::iterator iter_find = Mymap.find(2);


	//// ã�� ���ϸ� end��ȯ
	//if (Mymap.end() == iter_find)
	//{
	//	cout << "Ž�� ����" << endl;
	//	return;
	//}

	//cout << iter_find->first << " , " << iter_find->second << endl;
	
	// ##3. find_if �Լ� <algorithm> ��������
	map<const char*, int> Mymap;
	// map<string, int> Mymap;
	Mymap.insert(make_pair("BBB", 200));
	Mymap.insert(make_pair("AAA", 100));
	Mymap.insert(make_pair("CCC", 300));

	// char szBuffer[32] = "AAA";
	// map<const char*, int> ::iterator iter_find = Mymap.find("szBuffer");

	// �ܼ� �ּ� Ž�� (�ּ� ��)
	// map<const char*, int> ::iterator iter_find = Mymap.find("AAA");

	// ���� ���ڿ��� ���Ͽ� Ž��.
	// find_if(begin,end,����������) -> ���� Ž��
	// ���� �����ڰ� ��ȯ�� true�� �ش��ϴ� �ݺ��ڸ� ����

	map<const char*,int> ::iterator iter_find = 
		find_if(Mymap.begin(),Mymap.end(),)

	if (Mymap.end)
	{
		cout << "Ž�� ����" << endl;
		return;
	}


	cout << iter_find->first << " , " << iter_find->second << endl;

}