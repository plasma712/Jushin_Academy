#include <iostream>

using namespace std;

void main()
{
	// ##1. �� ������ (and, or, not)

	// && (and ������)
	// �� ���� ������ ��� ���̸� ����� ��.
	// �ϳ��� �����̸� ����� ��.
	// cout << (true && true) << endl;
	// cout << (true && false) << endl;
	// cout << (false && true) << endl;
	// cout << (false && false) << endl;

	//int a = 10, b = 200, c = 30;

	// cout << (a < b < c) << endl;	// ��� ����. a<b�� ������� true -> 1�� �ٲ� 1<C�� ���� �ٲ�� true�� ����.
	// cout << (a < b && b < c) << endl;

	// int d = 0;
	// (true) && (d = 100);
	// (false) && (d = 100);
	// ���� ������ ������ ��� ���� ������ �˻����� �ʴ´�.(���� ���� ����.)
	// �� ��� �ٷ� ���� ��ȯ ���� d�� 100�� ���Ե��� ���Ѵ�. *
	// cout << d << endl;


	// || (or ������)
	// �� ���� ���� �� �ϳ��� ���̸� ����� ��.
	// �� �� �����̾�� ����� ����.
	// cout << (true || true) << endl;
	// cout << (true || false) << endl;
	// cout << (false || true) << endl;
	// cout << (false || false) << endl;
	
	// int d = 0;
	// (false) || (d = 100);
	// (true) || (d = 100);
	// ���� ������ ���� ��� ���� ������ �˻����� �ʴ´�.(���� ���� ����.)
	// �� ��� �ٷ� �� ��ȯ ���� d�� 100�� ���Ե��� ���Ѵ�. *
	// cout << d << endl;

	// !  (not ������)
	// �� ����.

	// cout << !true << endl;
	// cout << !false << endl;


	// ##2. ��� ������ (+=, -=, *=, /=, %=)
	// int a = 100;
	// a = a + 50;
	// a += 50;

	// int b = 1, c = 2, d = 3;

	// ��� �����ڵ� ���� �����ڿ� �������ڷ� �����ʺ��� ���� ������ ����ȴ�.
	// b += c += d += 50;

	// cout << b << endl;
	// cout << c << endl;
	// cout << d << endl;



	return; 
}