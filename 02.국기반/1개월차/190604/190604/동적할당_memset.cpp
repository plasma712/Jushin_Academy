#include <iostream>

using namespace std;

// char* InputString()
// {
// 	char* ptr = (char*)calloc(32, sizeof(char));
// 
// 	cout << "���ڿ� �Է�:";
// 	cin >> ptr;
// 
// 	return ptr;
// }

void main()
{
	// char* pName = InputString();
	// cout << "��� : " << pName << endl;
	// 
	// free(pName);
	// pName = nullptr;

	// ******* malloc�� calloc�� ����

	int* ptr_1 = (int*)malloc(3 * sizeof(int)); // �����Ⱚ ����

	// �޸� �ʱ�ȭ �Լ�.
	// memset(�޸� ���۹���, �ʱ�ȭ��, �ʱ�ȭ�� �޸� ��ü ũ��
	memset(ptr_1, 0, 3 * sizeof(int));	
	for (int i = 0; i < 3; i++)
		cout << ptr_1[i] << endl;
	free(ptr_1);

	// for (int i = 0; i < 3; i++)
	// 	cout << ptr_1[i] << endl;
	// 
	// cout << "-------------------------------------" << endl;
	// 
	// int* ptr_2 = (int*)calloc(3, sizeof(int)); // 0 �ʱ�ȭ
	// 
	// for (int i = 0; i < 3; i++)
	// 	cout << ptr_2[i] << endl;
	// 

	
	// free(ptr_1);
	// free(ptr_2);

}