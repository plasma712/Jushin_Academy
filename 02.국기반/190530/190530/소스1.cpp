#include <iostream> 
using namespace std;

void main()
{

	// ##1. ���� �迭 (���ڿ�)
	// ���ڹ迭�� �ʱ�ȭ�� �� null����('\0')�ڸ����� ����ؾ��Ѵ�.
	// char szName[6] = { 'H','e','l','l','o' };
	// char szName2[6] = "Hello";

	// cout�� char*�� ������ �� �ּҷκ��� null���ڸ� ������ ������ ����Ѵ�.
	// null���ڰ� ������ ���ڿ��� ���� �Ǻ� �� �� ����.
	// cout << szName << endl;
	// cout << szName2 << endl;

	// ##2. ���ڿ� ���
	
	// const char* pName = "Hello";
	// 
	// cout << "Hello" << endl;
	// cout << pName << endl;
	// cout << pName[1] << endl;

	// pName[1] = 'e' // error ����̹Ƿ� �� ���� X

	// ##3. ���ڿ� �Է� �ޱ�
	// char szInput[6] = ""; // ��� ���� 0���� �ʱ�ȭ
	// 
	// cout << "�Է�: ";	// �Է¹��� �� �迭�� ���� �Ѿ�� �ʵ��� ����.
	// cin >> szInput;
	// 
	// cout << "���: " << szInput << endl;

	// �߸��� ���ڿ� �Է�_1
	// char* pInput = nullptr;
	// 
	// cin >> pInput;
	// cout << pInput << endl;

	// �߸��� ���ڿ� �Է�_2
    // char* pInput = "Hello";
	// cin >> pInput;
	// cout << pInput << endl;


	return;
}