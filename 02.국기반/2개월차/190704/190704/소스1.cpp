#include<iostream>
#include<list>
using namespace std;

void main()
{

	// ##1. list�� �ݺ���
	// list�� ����� ��ȸ�� �����Ѵ�.
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

	//// ������ ��ȸ

	//for (; iter_begin != iter_end; )
	//	cout << *(--iter_end) << endl;


	// ##2. reverse�Լ�

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

	//// ##3. list �߰�����
	//list <int> MyLst;

	//MyLst.push_back(10);
	//MyLst.push_back(30);

	//list<int>::iterator iter_begin = MyLst.begin();
	//list<int>::iterator iter_end = MyLst.end();

	//iter_begin++;
	//iter_begin++;
	//iter_begin++;


	// list�� �߰� ���� ���Ŀ��� end�� ��ȿȭ�� �Ͼ�� �ʴ´�.
	//MyLst.insert(iter_begin, 20);
	
	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	// ##4. list �߰�����
	list <int> MyLst;

	MyLst.push_back(10);
	MyLst.push_back(30);

	list<int>::iterator iter_begin = MyLst.begin();
	list<int>::iterator iter_end = MyLst.end();

	iter_begin++;
	MyLst.erase(iter_begin);

	// �߰� ���� ���� ������ ��ġ�� �ݺ��ڴ� ��ȿȭ�� �Ͼ���Ǹ���
	// �ٽ� �ʱ�ȭ�ϰų� erase��ȯ���� ���� ��ġ�� �޾��ָ� �ȴ�.
	// list�� �߰� ���� ���Ŀ��� end�� ��ȿȭ�� �Ͼ�� ����.

	for (iter_begin=MyLst.begin(); iter_begin != iter_end; iter_begin++)
		cout << *iter_begin << endl;


	return;
}