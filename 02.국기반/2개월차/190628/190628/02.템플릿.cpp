#include <iostream>

using namespace std;

template <typename T>
int GetArraySize(T& r) // ���ø��� �̿��� �迭 ���� �ޱ�
{
	return sizeof(r);
}

// auto Ű����δ� ���ø��� ��ü�� �� ����. ������ �������� �Լ��� �������ϴµ�,
// �ƹ��� ������ ���� �ʱ⿡.

// auto Add(auto a, auto b)
// {
// 	return a + b;
// }

template <typename T>
int GetArray(T& r) // ���ø��� �̿��� �迭 ���� �ޱ�
{
	// ���� ��� for�� (c++11 �̻���� ����)
	//	for (auto& element  : r)	//���۷����� ��������� element�� ������.
	for (auto element  : r)	// auto Ű���� (C ++1 �̻���� ����) (element�� �纻��)
		cout << r[] << endl;

	return sizeof(r);
}
template <typename T,int size>
int GetArraySize2(T(&r)[size]) // ���ø��� �̿��� �迭 ���� �ޱ�
{
	for (int i = 0; i < size; i++)
		cout << r[i], < endl;

	return sizeof(r);
}


void main()
{
	int iArr[5] = { 0,1,2,3,4 };
	//int iArraySize = GetArraySize(iArr);
	//cout << iArraySize << "bytes" << endl;

	// int iArraySize = GetArraySize2(iArr);
	// cout << iArraySize << "bytes" << endl;
    // 

	int iArraySize = GetArray(iArr);
	cout << iArraySize << "bytes" << endl;
	/*
	int iArr[3][3] = {1,2,3,4,5,6,7,8,9};


	// ���� ��� for���� �̿��� 2���� �迭 �ٷ��.
	for (auto& Array : iArr)
	{
		for(auto element : Array)
			cout<< element << '\t';

			cout << endl;
	}
	
	*/

	return;
}