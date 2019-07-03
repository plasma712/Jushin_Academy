#include<iostream>
#include<algorithm>
#include<vector>
#include <functional>

using namespace std;

bool IsEven(int n)
{
	if (n % 2 == 0)
		return true;
	else
		return false;
};

void SafeDelete(int*& ptr)
{
	if (ptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

void Print(int n)
{
	cout << n << endl;
}

bool Greater(int a, int b)
{
	return a > b;
}

void main()
{
	// ##1. count_if �˰��� �Լ�.
	// �����̳ʰ� ���� �ִ� ���� �߿� ���ǿ� �´� ���Ұ� � �ִ��� �����ִ� �Լ�.
	//int iArr[5] = { 1,2,3,4,5 };
	//// int count_if(begin, end, ����������)
	//int iCount = count_if(iArr, iArr + 5, IsEven);
	//cout << "¦���� ���� : " << iCount << "�� �Դϴ�." << endl;


	// Vector ������� count_if;
	//vector<int> vec{ 1,2,3,4,5 }; // ������ �ʱ�ȭ(c++ 11�̻�)


	//int iCount = count_if(vec.begin(), vec.end(), IsEven);
	//cout << "¦���� ���� : " << iCount << "�� �Դϴ�." << endl;

	// ##2. for_each �˰��� �Լ�. <algorithm>���� ����

	//vector<int*> vec;

	//vec.push_back(new int);
	//vec.push_back(new int);
	//vec.push_back(new int);
	//
	//// ���� �����̳ʸ� ��ȸ�ϸ鼭
	//// ����° ���ڷ� ���� ���� �Լ��� �ݺ� ȣ���ϰ� �ִ� ������ �˰���


	//for_each(vec.begin(), vec.end(), SafeDelete());
	//vec.clear();

	// ##3. sort �˰��� <algorithm>���� ����
	vector<int> vec{ 5,1,4,3,2 };
	sort(vec.begin(), vec.end()); // �⺻ �������� ����
	sort(vec.begin(), vec.end(), Print);

	// sort �Լ��� ���������ڸ� �����.
	


	// begin�� end�� �������� ���ɾ��Ѵ�.
	for_each(vec.begin(), vec.end(), Greater);

	greater<int> functor;
	sort(vec.begin(), vec.end(), functor);
	sort(vec.begin(), vec.end(), Greater); // �����ڸ� �̿��� ��������


	// <functional���� �����ϴ� �Լ���ü
	// less<ing> 

	return;
}