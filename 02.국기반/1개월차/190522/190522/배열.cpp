#include <iostream> 

using namespace std;

void main()
{
	// ##1. �迭
	// ���� �ڷ����� ���� ���� �����͸� ȿ�������� ���� �� ���� �� �� �ִ�.
	// int iCoke = 100, iCider = 200, iFanta = 300;
	
	// �迭�� ���ӵ� �޸𸮸� ���´�.


	// �迭����
	// �ڷ��� �迭�̸�[�迭����];

	// int iDrinkArr1[3] = { 100,200,300 }; // �迭 �ʱ�ȭ.
	// int iDrinkArr2[3] = { 100,200 };	 // ������ ���Ҵ� 0���� �ʱ�ȭ
	// int iDrinkArr3[3] = { 100 };		 // 2, 3��° ���Ҵ� 0 �ʱ�ȭ
	// int iDrinkArr4[3] = {};			 // ��� ���� 0 �ʱ�ȭ.


	// ���� ����(index�� ����)
	// �迭�� �̸��� ���ӵ� �޸��� �������̴�.
	// �迭�� ���ҿ� index�� ������ ������ ���̸� �Ѿ�� �ʰ� ����.
	// �迭�� ���̰� N�� index�� ���� 0 ~ N-1

	// cout << "�ݶ� : "	<< iDrinkArr1[0] << endl;
	// cout << "���̴� : "	<< iDrinkArr1[1] << endl;
	// cout << "ȯŸ : "	<< iDrinkArr1[2] << endl;

	
	// ##2. �迭�� ���� �� �ʱ�ȭ
	
	// int iDrinkArr[3];
	// iDrinkArr = { 100,200,300 }; // error, �迭�� �ʱ�ȭ ������ ����� ���ÿ��� ����

	// �� ������ ���� �ʱ�ȭ�ϰ� �ִ�.
	// iDrinkArr[0] = 100;
	// iDrinkArr[1] = 200;
	// iDrinkArr[2] = 300;


	// ##3. �迭�� �Ǵٸ� �ʱ�ȭ ����

	// �迭�� ���̸� �������� �� {}�ȿ� ������ ������ ������ŭ �޸𸮰� �Ҵ�ȴ�.
	// int iDrinkArr[] = { 100, 200 };
	// int iDrinkArr2[]; // error
	// int iDrinkArr3[] = {}; // error


	// sizeof���� �� �ǿ����ڰ� �迭�� �̸��̶�� �迭�� �� �޸� ũ�Ⱑ ��ȯ�ȴ�.
	// cout << sizeof(iDrinkArr) << endl;

	// ##4. �迭�� ���� ���

	// double iArr[5] = {};

	// cout << "�� �޸� ũ�� : " << sizeof(iArr) << endl;
	// cout << "���� �迭�� ����: " << sizeof(iArr) / sizeof(iArr[0]) << endl;

	// ##5. �����迭

	// int iLength = 0;

	// cout << "�迭�� ���̸� �Է� : ";
	// cin >> iLength;

	// int iArr[iLength];		//error, �迭 ����� �迭�� ���̴� ����� ����


	// const int iMaxcount = 5;
	// 
	// int iArr[iMaxcount] = {};

	// ##6. �迭�� ������ �ڷ���� ������ ��Ģ�� ���� �ִٸ� �ݺ����� Ȱ���϶�.

	// int iArr[1000] = {};
	// 
	// for (int i = 0; i < 1000; i++)
	// {
	// 	iArr[i] = i + 1;
	// }



	return;
}