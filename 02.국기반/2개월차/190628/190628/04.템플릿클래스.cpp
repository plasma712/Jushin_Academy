#include <iostream>

using namespace std;

// ##1. Ŭ���� ���ø�.

template <typename T>
class cPoint
{
private:
	T m_X;
	T m_Y;
};


template <typename T, int size = 5>
class cArray
{
private:
	T m_Array[size];	// ���ø��̶� �����ϴ�! ���� �ڵ尡 ��������� �� �ܰ�
};

void main()
{
	// ## 2. ���ø� Ŭ����
	cPoint<int>		intPos;    // �̶� int�� ���� �ڵ尡 ����. (�����Ͻ���)
	cPoint<float>   floatPos;  // �̶� float�� ���� �ڵ尡 ����. (�����Ͻ���)

	cArray<int> array1;
	cArray<float, 10>array2;

	// �Ʒ� �������� �ڵ尡 �����Ǳ� ������ ���� ���� �迭 ���𰡴�.
	cout << sizeof(array1) << endl;
	cout << sizeof(array2) << endl;

	return;
}