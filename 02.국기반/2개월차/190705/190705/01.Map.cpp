// Ʈ��
// ��������
// ǥ�� ���� �����̳�.

// �ֻ��� ��� = ROOT ���
// �ڽ��� ���� ��� = Leaf ���
// 0���̻��� �ڽ��� ���� �� �ִ�.(�θ���)


// MAP�� ����(+Ž��)Ʈ���� ������� �̷�����ִ�.
// �θ��� = 2�������� �ڽĳ�带 ���´�.
// ����Ʈ���� �������� ġ������ ������ �ӵ��� ��������. (ã�����ϴ� ������ ū ���� �߶󳻾��ϴµ� �װ� ����.)
// �̸� �ڰ���������Ž��Ʈ���� �̿��Ͽ� Ʈ���� �������� ġ�������� �ʵ��� �Ѵ�.

// MAP�� Ư¡
// 1. ��忡 �ִ� [KEY�� , Value��]�� KEY���� �ߺ��� �Ǹ� �ȵȴ�.
// 2. KEY���� ��Һ񱳸� �� �� �ִٸ� ��� ���̵� ����̾���.(����ü�� Ŭ������ ��� ���� ũ�⸦ ���� �� �ִ� �����ε��� �ʿ�)

// �����̳�
// ���ҹ�ġ
// ǥ�� ������ �����̳�
// vector, list, deque(�迭����� �����̳� ���Ҵ��� �̷������ �ʴ´�. [deque1] - [deque2] - [deque3] : ���ӵ� ������ �ƴϴ�.

// ǥ�� ���� �����̳�
// map, multimap key��value��� //, set , multiset key���� ��� (�ߺ������� �͵��� ������ Ȯ���Ұ�.)

// �迭���
// vector , deque

// �����
// list, map , multi

// �����̳� �����
// ���� , ť , �켱���� ť

// �ٻ� �����̳�


#include <iostream>
#include <map>
using namespace std;

// ##1. map�� Ư¡ 
// 1. �ڰ����� ���� Ž�� Ʈ���� ������� �Ѵ�. (�����Ʈ��)
// 2. ǥ�� ���� �����̳�
// 3. ��� ��� �����̳�. list�� ���� ��� ��ݿ� ���� Ž���� ������ ������.
// 4. ���� �ϳ��� key, value �ѽ��� �̷��.
// 5. ���Ҹ� ������ ������ key�� �������� ������ �Ͼ��. ���Լӵ��� ������.
// 6. �ߺ� key�� ������� �ʴ´�.
// 7. ��� ��������� key�� ���� �ε��� ������ �� �ִ�. (key Ž��)
// 8. �ѹ� ���Ե� Key�� ������ �� ����.
//    - �����ϰ� �ʹٸ� �ش� key�� ���Ҹ� �����ϰ� ���� �����ض�.
//	  - ��, value�� ���� ����


void main()
{
	// ##2 pair ��ü

	//pair<int, int> MyPair(1, 100);

	//pair<int, int> MyPair2;

	//MyPair2.first = 2;		// Key
	//MyPair2.second = 200;	// Value

	// ##3. map�� ���� map<key,value> ������
	//map<int, int>			Mymap1;
	//map<float, int>		    Mymap2;
	//map<string, Ŭ������>	Mymap3;
	//map<Ŭ������, int>		Mymap4;
	//map<����ü��, float>	Mymap5;

	//// ##4. map�� ������ ����.
	//map<int, int> Mymap;

	//// ���� ��� ù��° (pair ��ü Ȱ��)
	//pair<int, int> MyPair(2, 200);
	//Mymap.insert(MyPair); // ���� �� pair��ü�� ����.

	//// ���� ��� �ι�° (pair �ӽð�ü ���)
	//Mymap.insert(pair<int, int>(1, 100)); // �ӽ� ��ü Ȱ��

	//// ���� ��� ����° (make_pair�Լ� ���)
	//pair<int, int> MyPair2 = make_pair(5, 500);
	//Mymap.insert(MyPair2);

	//// make_pair�Լ� : ���� �� ���ڿ� �°� pair��ü�� �����ϴ� �Լ�.
	//Mymap.insert(make_pair(4, 400));

	//// ���� ��� �׹�° (map<key, value>::value_type ���) // value Ÿ�� = pair<const key, value>�� ����üȭ ��Ų�ű� ������...
	//													   // ������ ����ȯ�� �߰��� �Ͼ���� �ʴ´�. (�ٸ��͵��� const key������ 
	//													   // ������ ����ȯ�� �Ͼ��.
	//map<int, int>::value_type MyPair3(6, 600);

	////MyPair3.first = 7; // error KEY�� ���� �Ұ�
	//Mymap.insert(MyPair3);
	//Mymap.insert(map<int, int>::value_type(7, 700));


	//// map�� ���� �� �� ���� Key�� �������� ������ �����Ѵ�.
	//for (map<int, int>::value_type element : Mymap)// ������� ����
	//{
	//	cout << "Key : " << element.first << endl;
	//	cout << "Value : " << element.second << endl;
	//	cout << "-----------------------------" << endl;
	//}


	// ##5. map�� []->�ε��� ����.
	// key���� ���� �ε��� ������ �����ϵ��� �����ε� �Ǿ��ִ�.
	// �̴� ���ӵ� �迭�� ���� �ε��� ������ �ƴ϶�, �ܼ� ����Ž���� �ǹ�

	//map<int, int> Mymap;
	//
	//Mymap.insert(pair<int, int>(3, 300));
	//Mymap.insert(make_pair(2, 200));
	//Mymap.insert(map<int, int>::value_type(1, 100));

	//// cout << Mymap.begin() -> first << endl;

	////key ������ �ε��� ������ �����ϸ� value�� ������ �����Ѵ�.
	//cout << Mymap[1] << endl;

	//Mymap[1] = 1000; // value��������

	//cout << Mymap.begin()->second << endl;

	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;
	//
	//Mymap[5];	//�������� �ʴ� key�� �ε��� ���� ���� �� ���Ҹ� ���� ����� ������.

	//cout << "Mymap[5] : " << Mymap[5] << endl;
	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;

	//Mymap[6] = 600;	// ������ �̷������� ���������� ����� value�� �����ϴ� ����

	//cout << "Mymap[6] : " << Mymap[6] << endl;
	//cout << "size : " << Mymap.size() << endl;
	//cout << "-----------------------------" << endl;


	//// ##6. �ߺ� key insert
	//map<int, int> Mymap;

	//Mymap.insert(make_pair(1, 100)); // ���� ok

	//// insert�� pair�� ��ȯ�ϴµ� �� �� value�� bool Ÿ���̴�.
	//// ��ȯ�� pair�� value�� false�� ���´ٸ� ���� �����ߴٶ�� �ǹ�

	//if (false == Mymap.insert(make_pair(1, 200)).second); // ���� no
	//{
	//	cout << "�̹� �����ϴ� key�Դϴ�" << endl;
	//}
	//Mymap.insert(make_pair(1, 300)); // ���� no

	//cout << "size : " << Mymap.size() << endl;
	//cout << "value : " << Mymap[1] << endl;

	// ##7. map�� ���� ����
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