#include <iostream>

using namespace std;

// ##1. Ŭ���� �Ҹ���
// ��ü �Ҹ� �� �Ҹ��ڰ� ȣ��ȴ�.
// ����ڰ� �Ҹ��ڸ� ������� ������ �����Ϸ��� ����Ʈ �Ҹ��ڸ� ������ش�.

// *** ��ü �Ҹ� ����
// �Ҹ��� ȣ�� -> �޸� �ݳ�.


class cTest
{
private:
	int* m_ptr;
public:
	cTest()
	{
		//m_ptr=
	}

	// �Ҹ����� ����
	~cTest()
	{
		// ���� Ŭ������ ��� ���� �� �Ҹ��ڴ� �����ϴ�.
		cout << "�Ҹ��� �Դϴ�." << endl;
	}
};


void main()
{
	// ##2. �����Ҵ� ��
	// cTest obj;

	// cout << "���μ��� ������.." << endl;
	// cout << "���μ��� ������.." << endl;
	// cout << "���μ��� ������.." << endl;
	// ##3. �����Ҵ� ��

	cTest* ptr = new cTest;

	cout << "���μ��� ������.." << endl;
	cout << "���μ��� ������.." << endl;

	delete ptr;
	cout << "���μ��� ������.." << endl;


	


	system("pause");
	return;
}