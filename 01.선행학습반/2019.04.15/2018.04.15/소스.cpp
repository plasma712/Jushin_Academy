#include <iostream>

using namespace std;

void main()
{
	/*
	bool b = true;
	bool b1 = false;
	bool b2 = true, b3 = 'B';

	char A = 'C';
	char ch = 'A';
	char ch1 = 65;
	char ch2 = A;

	short n = 10;



	int i = 32760000000000008;
	n = i;

	cout << n << endl;

	// f Ű���� ���̴� �ӽ� �޸� ���� ���� �� 4byte��� ���� �˷��ֱ� ���� f Ű���带 ����.
	// �ӽ� �޸� ���� : ������ ���� �ӽ÷� �����ϴ� �޸� ����
	float f = 10.22f;

	i = f;

	cout << i << endl;

	cout << b << endl;
	cout << b1 << endl;
 */
 // ������  -> ���׿�����, ���׿�����, ���׿�����
 // �������, sizeof()������, ����Ʈ������, ��������, ��Һ� ������, ��Ʈ���� ������

 // ��� ���� : + , - , * , / , %
	cout << "��� ���� : + , - , * , / , %" << endl;
	cout << 10 + 20 << endl;
	cout << 10 - 20 << endl;
	cout << 10 * 20 << endl;
	cout << 10 / 20 << endl;
	cout << 10 % 2 << endl;
	cout << endl;

	// sizeof() - ���� ������. 
	cout << "sizeof() - ���� ������. " << endl;

	cout << sizeof(int) << endl;
	cout << sizeof(char) << endl;
	long long ll = 200000;
	cout << sizeof(ll) << endl;
	char ch1 = 'A', ch2 = 'B';
	cout << sizeof(ch1 + ch2) << endl;
	cout << endl;

	//��Һ� ������ >, >=, <, <=, == , !=
	cout << "��Һ� ������ >, >=, <, <=, == , !=" << endl;

	int iA = 10, iB = 20;

	cout << (iA > iB) << endl;
	cout << (iA >= iB) << endl;
	cout << (iA < iB) << endl;
	cout << (iA <= iB) << endl;
	cout << (iA == iB) << endl;
	cout << (iA != iB) << endl;
	cout << endl;

	// �� ������ &&(AND), ||(or), !(NOT)
	cout << "�� ������ &&(AND), ||(or), !(NOT)" << endl;
	bool bTrue = true && true;
	bool bTrue1 = true && false;
	bool bTrue2 = false && true;
	bool bTrue3 = false && false;

	/////////////////////////////////
	// &&�������� ��� ù ���� false �� ��� ���� ���� ����� ����� ������� ������ ������ ���� �ʴ´�.
	// ���� bTest�� ��� i�� 99�� ���� �������� , bTest1�� ��� i�� 99�� ����.
	int i = 0;
	bool bTest = false && (i = 99);
	cout << i << endl;
	cout << endl;

	bool bTest1 = (i = 99) && false;
	cout << i << endl;
	cout << endl;
	/////////////////////////////////

	cout << bTrue << endl;
	cout << bTrue1 << endl;
	cout << bTrue2 << endl;
	cout << bTrue3 << endl;

	cout << endl;

	int iAge = 0;
	cin >> iAge;
	cout << iAge << endl;

	bool �̼����� = 0 < iAge && iAge < 20;
	cout << �̼����� << endl;

	////////////////////////////////
	// ||�������� ��� ù ���� true �� ��� ���� ���� ����� ����� ������� ������ ������ ���� �ʴ´�.
	// ���� aTest�� ��� �ڸ� Ȯ���غ��� �ϱ� ������ a�� 99�� ����.

	bool aTrue = true || true;
	bool aTrue1 = true || false;
	bool aTrue2 = false || true;
	bool aTrue3 = false || false;
	int a = 0;
	bool aTest = false || (i = 99);
	cout << a << endl;
	cout << endl;

	cout << aTrue << endl;
	cout << aTrue1 << endl;
	cout << aTrue2 << endl;
	cout << aTrue3 << endl;
	cout << endl;

	// !(NOT)

	cout << !(true) << endl;
	cout << !(false) << endl;

	// �밡���� ǥ���

	bool bOOOO;
	char chOOOOO;
	short nOOOOO;
	int iOOOO;
	float fOOOOO;
	long lOOOO;

	double dOOOO;
	long double ldOOOOO;

	long long llOOOOO;

}