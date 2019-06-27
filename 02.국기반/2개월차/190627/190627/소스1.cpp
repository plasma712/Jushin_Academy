#include <iostream>

using namespace std;


// ** �Լ� ��ü �����ε��� ���� ����.
// 1. �������Ƿ� ���� �ζ��� ȭ�� �Ͼ �� �ִ�. (�Լ� �����Ϳ� ���� �ӵ��� ������.) // �Լ� �����ʹ� �ζ��� ȭ�� �ƿ� �Ұ���.
// 2. Ŭ������ ����� ������ ��������� ���� �� �ִ�.
// 3. �Լ� �������� ��� Ÿ���� �쿬���� ���Ͻ� �ϴٸ�, �Լ������Ͱ� ȣ�� �� �� �ִ�.
//    ������ �Լ� ��ü �����ε��� �ڽ� Ŭ������ �ƴ� �̻� ���� �� �� ����.
// 4. Ŭ������ ���� 4�� �Ӽ��� ��� ��� �� �� �ִ�.
class cSortRule
{
public:
	
	virtual bool operator()(int a, int b) = 0;
};

// ��������
class cGreater : public cSortRule
{
public:
	virtual bool operator() (int a, int b)
	{
		return a > b; // ���� ����. (�ڷ� ������ �۾����� �Ѵٴ� �ǹ�)
	}
};

// ��������
class cLess : public cSortRule
{
public:
	virtual bool operator() (int a, int b)
	{
		return a < b; // ���� ����. (�ڷ� ������ �۾����� �Ѵٴ� �ǹ�)
	}

};

void BubbleSort(int ptr[], int length, cSortRule& functor)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - 1; j++)
		{
			if (functor(ptr[j + 1], ptr[j]))
			{
				int itemp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = itemp;
			}
		}
	}
}



void main()
{
	cLess less;
	cGreater greater;


	int iArr[5] = { 5,1,4,3,2 };

	BubbleSort(iArr, 5, less ); // �ӽð�ü ȣ�� ... Ȯ���غ���

	for (int i = 0; i < 5; i++)
	{
		cout << iArr[i] << endl;
	}

	return;
}