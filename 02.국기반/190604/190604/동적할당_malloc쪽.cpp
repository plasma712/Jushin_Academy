#include <iostream>

using namespace std;

// ##1. �����Ҵ� (Dynamic Allocation)

// Heap ���� : �����Ҵ�� �����Ͱ� ��ϵǴ� ����.
// �Ҵ� ���� : ���α׷��Ӱ� ���� �� ("{"���۽�)
// �Ҹ� ���� : ���α׷��Ӱ� ���� �� ("}"�����)

// Stack�� ������

// char* InputString()
// {
// 	char szInput[32] = "";
// 	cout << "���ڿ� �Է�: ";
// 	cin >> szInput;
// 
// 	return szInput; // ���� ������ �ּҸ� ��ȯ�ϸ� �ȵȴ�. warnning (�ּҰ� �Լ��� �����鼭 �ּҸ� ������ �̿��� �Ұ���)
// }




void main()
{
	// char* pName = InputString();
	// cout << "���: " << pName << endl;

	// ##1. C��� ����� �����Ҵ� (Dynamic Allocation)
	
	// 1. malloc �Լ�
	// malloc(4); // = void* malloc(size_tSize) ��ȯ���� �Ű�Ⱦ��� �ּҰ� �켱����
	
	// intŸ�� 4����Ʈ �޸𸮸� Heap�� �Ҵ�
	// ptr�� ���� �ش� �޸𸮿� ���� ����.
	// int* ptr = (int*)malloc(4);
	// 
	// *ptr = 100;
	// cout << *ptr << endl;
	// 
	// free(ptr); // �޸� ���� �Լ�.
	// ptr = nullptr;	//dangling ������ ����
	// 
	// if (nullptr != ptr)
	// 	*ptr = 200;

	// 2. calloc �Լ�

	// int ������ 3�� ���ӵǰ� heap������ �Ҵ�. ->���� �迭.
	// int* ptr = (int*)calloc(3, sizeof(int));
	// 
	// ptr[0] = 100;
	// ptr[1] = 200;
	// ptr[3] = 300;
	// 
	// cout << &ptr[0] << endl;
	// cout << &ptr[1] << endl;
	// cout << &ptr[2] << endl;

	// ##2. ���� �迭
	// ��Ÿ�� ���߿� �迭�� ���̸� ���� �� �ִ� �迭�̴�.
	// int iCount = 0;
	// 
	// cin >> iCount;
	// 
	// int* ptr = (int*)calloc(iCount, sizeof(int));
	// 
	// for (int i = 0; i < iCount; i++)
	// 	cout << (ptr[i] = i + 1) << endl;
	// 
	// free(ptr);
	// ptr = nullptr;

	// ##3. realloc�Լ�
	int iCount = 0;
	
	cin >> iCount;

	int* ptr = (int*)malloc(iCount * sizeof(int));

	for (int i = 0; i < iCount; i++)
		cout << (ptr[i] = i + 1) << endl;

	cout << "------------------------------------------" << endl;

	cout << "�迭�Ǳ���";
	cin >> iCount;

	int* ptr_2 = (int*)realloc(ptr,iCount * sizeof(int));
	// free(ptr); //ptr�� realloc�Լ� ���ο��� �����ǰ� �����Ƿ� ���� �Ҵ������� ���� �ʿ䰡 ����.

	for(int i =0;i<iCount;i++)
		cout << (ptr_2[i] = i + 1) << endl;



	return;
}