#include <iostream>

using namespace std;

// ##1. ��� �Լ�
// �ڱ� �ڽ��� ȣ���ϴ� �Լ�
// Ż�� ������ ���ٸ� Stack overflow ������ �Ͼ��.
// ����Լ��� �ٷ� �� �ݵ�� Ż�� ������ �־���Ѵ�.
// �ڵ尡 ����������.
// ���̸� �� �� ���� ��Ȳ(�󸶳� �ݺ����� �𸣴� ��Ȳ)�� ����.


// Ż�������� ���� ����Լ�.
void Recursive()
{
	cout << "Hello" << endl;

	Recursive(); // ��� ȣ��
}

void Recursive_Two(int _n)
{
	if (_n == 0)
		return;

	cout << "Hello" << endl;
	Recursive_Two(_n - 1);
}

// ���丮�� (������)
// 3! = 3 * 2 * 1
// 5! = 5 * 4 * 3 * 2 * 1
// N! = N * N-1 * N-2 * N-3 *---* 1

// ����Լ��� �̿��� ���丮��
int Factorial_(int n)
{
	if (1 == n)
		return n;

	return n * Factorial_(n - 1);
}


// ��������.
void Factorial(int _iNum)
{
	static int k = 1;

	if (_iNum == 0)
	{
		cout << k << endl;
		return;
	}

	k *= _iNum;
	
	Factorial(_iNum-1);
}

void main()
{
	// Ż�� ������ ���� ����Լ�
	// Recursive();

	// ����Լ��� Ż�� ������ �־�� �Ѵ�.
	// Recursive_Two(3);
	Factorial(6);
	return;
}