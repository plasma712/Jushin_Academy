#include <iostream>

using namespace std;

void main()
{
	// ##1. ���ڿ� ���� ���ϴ� ǥ�� �Լ�. <string.h> ���� ����
	// null���ڸ� ������ ���� ���ڿ� ���̸� ���Ѵ�.
	// size_t strlen(const char* ) => const char*�� ���������� char* �ڿ� �ִ� ���� �������� �ʵ��� �ϴ� ��ȣ��

	// char szName[6] = "world";
	// 
	// cout << "���� : " << strlen(szName) << endl;
	// cout << "�޸� ũ�� : " << sizeof(szName) << endl;
	// 
	// cout << "���� : " << strlen("HelloWorld") << endl;
	// cout << "�޸� ũ�� : " << sizeof("HelloWorld") << endl;


	// ##2. ���ڿ� ���ϴ� ǥ�� �Լ�. <string.h>���� ��
	// int strcmp(const char* , const char*)
	// ���ϴ� �� ���ڿ��� ������ 0�� ��ȯ. �ٸ��� 0�� �ƴѰ� ��ȯ

	// char szName_1[32] = "Hello";
	// char szName_2[32] = "Hello";

	// ���ڿ��� ���ϴ°��� �ƴ϶� �ּҰ��� ���ϱ⿡ �ٸ��ٰ� ���´�.
	// if (szName_1 == szName_2)
	// 	cout << "�� ���ڿ��� �����ϴ�." << endl;
	// else
	// 	cout << "�� ���ڿ��� �ٸ��ϴ�." << endl; 

	// if(!strcmp(szName_1,szName_2)) ���ڿ� �� �Լ�
	//  	cout << "�� ���ڿ��� �����ϴ�." << endl;
	//  else
	//  	cout << "�� ���ڿ��� �ٸ��ϴ�." << endl; 

	// ##3. ���ڿ� �����ϴ� ǥ���Լ�. <string.h>���� ����
	// strcpy_s()

	// char szName_1[32] = "";
	// char szName_2[32] = "Hello";

	// �迭�� �̸��� ��������ʹ�.
	// szName_1 = szName_2; // error
	 
	// strcpy_s(szName_1, szName_2);			// strcpy�� Ȯ�����.
	// cout << "szName_1 : " << szName_1 << endl;
	// cout << "szName_2 : " << szName_2 << endl;

	// char* ptr = szName_1;

	// ù ���ڰ� �迭�� �̸��� �ƴ� �ܼ� char*�� ��� ������ ũ�⸦ �� �������� �Ѵ�.
	// ��� ���ڴ� ������ ũ�⺸�� ���ų� Ŀ���Ѵ�.
	// strcpy_s(ptr, 6, szName_2);


	// ##4. ���ڿ� �̾���̴� ǥ���Լ�. <string.h>���� ����
	// strcat_s()

	// char szName_1[32] = "Hello";
	// char szName_2[32] = "World";

	// szName_1�� ������ �ִ� null���� �ڸ��� szName_2�� �̾� ���δ�.
	// szName_1�� �迭 ũ��� ���� ���� ũ�⺸�� �˳��ؾ��Ѵ�.
	// strcat_s(szName_1, szName_2);
	// cout << szName_1 << endl;

	// ù���ڰ� �迭�� �̸��� �ƴ� char* �̸� ��� ũ�⸦ �� ���������Ѵ�.
	// ��� ���ڴ� ������ ���ڿ��� ũ�⺸�� �۾Ƽ� �ȵȴ�.
	
	return;
}