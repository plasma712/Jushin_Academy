#include <iostream>
#include <list>

using namespace std;

// ##1. STL list
// ����� ���� ����Ʈ ����̴�. (���� ��ũ�� ����Ʈ)
// ǥ�� ������ �����̳��̴�.    (���ҹ�ġ�� �������̴�.)
// ����� �����̳��̴�.		(�񿬼����� �޸𸮸� ����Ѵ�.)
// ���������� �Ұ����ϰ� ������ �������ٸ� ����Ѵ�. -> Ž���� �Ҹ�.
// ���Ϳ� �޸� ������ �޸𸮰� �ƴϱ⿡ ����� ����, ������ �����ϴ�.



void main()
{
	// ##2. List ����
	// list<int>		MyLst1;
	// list<double>		MyLst2;
	// list<Ŭ������>	MyLst3;
	// list<����ü��>	MyLst4;

	// ##3. List ���� ����.

	//list<int>	MyLst;

	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);

	//// ���� ��� for������ ��ȸ ����.
	//for (int element : MyLst)
	//	cout << element << endl;

	//cout << "Size: " << MyLst.size() << endl;				// ���� ����
	//cout << "--------------------------------------" << endl;

	//MyLst.push_front(20);
	//MyLst.push_front(10);

	//for (int element : MyLst)
	//	cout << element << endl;

	//cout << "Size: " << MyLst.size() << endl;				// ���� ����
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

	//MyLst.pop_back();	// ���� ������ ���� ����

	//for (int element : MyLst)
	//	cout << element << endl;
	//cout << "--------------------------------------" << endl;


	//MyLst.pop_front();	// ���� ù ���� ����


	//list<int>	MyLst;

	//MyLst.push_back(30);
	//MyLst.push_back(40);
	//MyLst.push_back(50);


	//// front�� back���� ���� ù���ҿ� ������������ ������ ��ȯ
	//cout << "front : " << MyLst.front() << endl;
	//cout << "back : " << MyLst.back() << endl;

	//MyLst.push_front(20);
	//cout << "front : " << MyLst.front() << endl;

	//// cout << MyLst[2] << endl; // error  �������� �Ұ�


	// ##5. vector�� �����ϰ� front, back, empty, clear, swap, size ���� �Լ��� �������ش�.
	list<int> MyList;

	return;
}