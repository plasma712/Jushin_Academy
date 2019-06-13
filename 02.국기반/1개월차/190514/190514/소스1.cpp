#include <iostream>
using namespace std;

void main()
{
//##1. ������ �ڷ���
	// ���� : ���� �����ϱ� ���� ���� ����. �����ϱ� ����.
	// - ���� ����� ������ �̸��� �ٿ��ִ� ������ �Ѵ�.

	// �ڷ��� : � ������ ������, ���� ������ ũ��� �������� ����.

	// ##2. ���� �̸� ��Ģ.
	// 1. ���ڰ� ���ĺ����� ���� �ͼ� �� �ȴ�.
	// ex) int 2Player; -> error
	//     int P2layer; -> ok
	//
	// 2. Ư�����ڴ� �� �ȴ�. ��, _����ٴ� ���.
	// 3. ���� �̸��� ������ ������ �� ����.int player Hp; �Ұ��� ���鶫 -> int player_Hp; ����
	// 4. �ý��ۿ��� �⺻���� �����ϴ� Ű����� ���� �̸��� ���� �� ����. int, namespace �� ����
	
	// ##3. �ڷ����� ����
	// 1. ���� Ÿ�� : int, short, long, longlong
	// 2. �Ǽ� Ÿ�� : float, double, long double
	// 3. ���� ���� : char, wchar_t
	// 4. �� �ڷ��� : bool (��, ����) -> C++���� �����ϴ� �ڷ���.
	
	// ##4. �� �ڷ����� ũ�� (byte ����)
	// 1byte�ڷ��� = char, bool
	// 2byte�ڷ��� = short
	// 4byte�ڷ��� = int, long, float
	// 8byte�ڷ��� = long long, double, long double

	// ##5. unsigned�� signed
	//unsigned int b; // ����� ǥ���Ѵ�. ����Ÿ�Կ��� �� �� �ִ�.
	//int a;			// ���, ���� �Ѵ� ǥ���Ѵ�. (signed)-> (��ȣ���ִ�.)
	// OO1O (���� ���ڸ��� 0�̸� ��� = >  2
	// 1010 (���� ���ڸ��� 1�̸� ���� = > -2 

	// 1�� ���� => ��Ʈ ���� ex) 0010 - > 1�Ǻ����� 1101 �̴�.
	// 2�� ���� => ��Ʈ���� �� + 0001 ->  2�Ǻ����� 1110 �̴�.

	// 4bits => 16�� ǥ������
	// unsigned 0 ~ 15
	// signed -8 ~ 7

	// ##6. �� �ڷ����� ǥ�� ����
	// 1. unsigend char : char�� ������ ���� Ÿ���̴�. �ƽ�Ű�ڵ�
	// ����, unsigned Ű���带 ����� �� �ִ�.
	// char a = 86; // �ƽ�Ű �ڵ�
	// char b = 'V';
	// cout << a << endl;
	// cout << b << endl;
	// ǥ�� ���� : 0 ~ 255, �� 256���� ����� ǥ��

	// 2. char (signed)
	// ǥ�� ���� : -128 ~ 127, �� 256���� ����, ����� ǥ��.

	int PlayerHp = 10000;
	int PlayerMp = 5000;
	int PlayerAtt = 500;
	int playerDef = 150;

	cout << "�÷��̾��� ü�� : " << PlayerHp << endl;
	cout << "�÷��̾��� ���� : " << PlayerMp << endl;
	cout << "�÷��̾��� ���ݷ� : " << PlayerAtt << endl;
	cout << "�÷��̾��� ���� : " << playerDef << endl;
	return;
}