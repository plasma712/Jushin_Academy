#include <iostream>

using namespace std;

// ���� ����
// { } �ȿ� ����� ������ ���ϸ� ����� { } �ȿ����� ������ �� �ִ�.

void MyFunc()
{
	int iA = 10, iB = 20;
	int iC = 100;
}


void main()
{
	// iA�� iB�� MyFunc�Լ��� ������ ����Ǿ� �����Ƿ� ���� �Ұ�!
	// cout << iA << " , " << iB << endl;


	// �̸��� �������� ������ �ٸ��� ���� �ٸ� �����̴�.
	// int iC = 1000;
	// cout << iC << endl;

	// for (int i = 0; i < 10; i++)
	// {
	// 	int iA = 0;
	// 	iA += i;
	// }

	// cout << i << endl;	 // error 
	// cout << iA << endl;	 // error 

	// if (true)
	// {
	// 	int iA = 100;
	// } �ش� ������ ����� ���� iA�� Stack���� �Ҹ�.
	//  
	// cout << iA << endl; // error

	return;
}