#include <iostream>

using namespace std;

// ##1. Ŭ���� ������
// ��ü ���� �� ������ �ڵ� ȣ��Ǵ� �Լ��� ����.
// ����ڰ� �����ڸ� ������� ������ �����Ϸ��� ����Ʈ �����ڸ� ������ش�.
// Ŭ���� ��� �ʱ�ȭ �� �����ϴ�.
 
// *** ��ü�� ���� ����
// �޸� �Ҵ� -> ������ ȣ��.

class cTest
{
private:
	int m_Value;
public:
	// ����Ʈ �������� ����
	cTest()
	{
		m_Value = 0;
		cout << "����Ʈ ������ �Դϴ�." << endl;
	}

	// �����ִ� ������.
	// ����ڰ� �����ڸ� ����ϴ� ���� �����Ϸ��� ����Ʈ �����ڸ� ��������� �ʴ´�.
	cTest(int n)
	{
		cout << "m_Value�� ("<< n << ")������ �ʱ�ȭ�ϴ� �����ִ� ������ �Դϴ�." << endl;
		m_Value = n;
	}
	

};


void main()
{
	// // ##1. �����Ҵ� �� ������ ȣ��
	// cTest obj; // ���ھ��� (����Ʈ) ������ ȣ��.
	// cTest obj2(200);

	// ##2. �����Ҵ� �� ������ ȣ��
	cTest* ptr1 = nullptr;
	ptr1 = new cTest; // ���ھ���(����Ʈ) ������ ȣ��.

	cTest* ptr2 = nullptr;
	ptr2 = new cTest(200);	// �����ִ� ������ ȣ��.

	cTest* ptr3 = (cTest*)malloc(sizeof(cTest));

	system("pause");
	return;
}