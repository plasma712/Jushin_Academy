#include <iostream>

using namespace std;

class cTest
{
private:

public:
	cTest()
	{
		cout << "������" << endl;
	}
	~cTest()
	{
		cout << "�Ҹ���" << endl;
	}
};



void main()
{
	// ##1. ��ü �迭
	
	// ���� �迭
	// cTest Arr[3] = {};

	// ���� �迭
	// cTest ��ü�� heap������ ���ӵǰ� ��ġ.
	cTest* ptr = new cTest[3]; // ������
	delete[] ptr;	// �Ҹ���

	// ##2. ��ü ������ �迭
	// cTest��ü�� heap������ �񿬼ӵǰ� ��ġ
	cTest* Arr[3] = {new cTest,new cTest, new cTest};
	delete[] Arr[0];
	delete[] Arr[1];
	delete[] Arr[2];


	system("pause");
	return;
}