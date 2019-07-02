#include<iostream>
#include<vector>

using namespace std;

// ##1. �ݺ��� (iterator)
// �����̳ʸ���(�ڷᱸ������) ���Ҹ� �����ϰ� �����ϴ� ����� ��� �ٸ���.
// ���ҿ� �����ϱ� ���� ����� ���� ���ѳ��� ���� �ٷ� �ݺ����̴�.
// �����̳ʸ��� ���ο� �ݺ��� Ÿ���� ���ǵǾ� ����.

// �ݺ����� �⺻����.
// 1. ������ ��ġ�� ����Ų��. (�̸� ���� ���ҿ� ������ �� ����.)
// 2. �ݺ��ڸ� ���ؼ� �����̳ʸ� ��ȸ�� �� �ִ�.

void main()
{
	//// ##2. vector�� �ݺ��� ����

	//vector <int> vec;

	////�ݺ��� ����
	//vector<int>::iterator	iter;

	//// ##3. �ݺ��ڸ� ���� vecotr�� ��������
	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	//// begin�Լ� : ���� ù��° ������ ��ġ�� ����Ű�� �ݺ��ڸ� ����.
	//vector<int>::iterator iter_begin = vec.begin();

	//// �ݺ��ڿ��Դ� *������ �����ڰ� �����ε�.
	//// cout << *iter_begin << endl; // ���� ����Ű�� �ִ� ��ġ�� ��.
	//// cout << iter_begin << endl; // �����Ͱ� �ƴϴ�!!!!!!!!!!!


	//// end�Լ� : ���� ������ ���� "����" ��ġ�� ����Ű�� �ݺ��ڸ� ����.
	//vector<int>::iterator iter_end = vec.end();


	//// �ݺ��ڸ� �̿��� ���Ҽ�ȸ
	//// �ݺ��ڿ��Դ� �� ������, ���� �����ڰ� �����ε�
	//for (; iter_begin != iter_end; iter_begin++)
	//	cout << *iter_begin << endl;

	// ##4. ����ִ� �����̳��� begin�� end�� ���� ��ġ�̴�.

	//vector<int> vec;
	//if (vec.begin() == vec.end())
	//{
	//	cout << "�������" << endl;
	//}


	// ##5. vector�� �������� �ݺ��ڸ� �����Ѵ�.
	//vector<int> vec;
	//vec.push_back(10);
	//vec.push_back(20);
	//vec.push_back(30);

	////vector<int>::iterator iter_begin = vec.begin();

	////cout << iter_begin[2] << endl;
	////cout << *(iter_begin + 2) << endl;	// ������ �������� ok

	//vector<int>::iterator iter_end = vec.end();

	//cout << *(iter_end - 2) << endl;		// ������ �������� ok

	// ##6. vector�� �߰� ����

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

	//// �߰� ���� ���Ŀ� ���Ҵ� ���簡 �߻��Ѵٸ�
	//// ���� �ݺ����� ��ȿȭ�� ���� ����ȴ�.
	//// ���� �ݺ��ڸ� ���� �ٽ� �޾ƿ;� �Ѵ�.
	//// ����, ���Ҵ� ���簡 �߻����� �ʾҴٸ�
	//// begin�� �״�� ��� ���������� end�� �׻� ���� �޾ƿ;��Ѵ�.

	//iter_begin = vec.begin();
	//iter_end = vec.end();

	//cout << &iter_begin << endl;
	//cout << &iter_end << endl;

	// for (; iter_begin != iter_end; iter_begin++)
	// 	cout << *iter_begin << endl;


	// ##7. vector�� �߰� ����

	vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);


	vector<int>::iterator iter_begin = vec.begin();
	vector<int>::iterator iter_end = vec.end();
	vector<int>::iterator iter_next;

	// erase(where)
	iter_next = vec.erase(iter_begin + 1);

	// erase�� ������ ���� ��ġ�� ��ȯ�Ѵ�.
	cout << *iter_next << endl;

	//vec.erase(iter_begin + 1);
	cout << "-------------------------------" << endl;
	// ���� ���� ���� begin�� ��� ������ end�� �׻� ����.

	iter_end = vec.end();

	for (; iter_begin != iter_end; iter_begin++)
		cout << *iter_begin << endl;


	return;
}