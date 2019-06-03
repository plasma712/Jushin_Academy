#include <iostream>

using namespace std;

// ##1. ����ü�� ���ؼ� ���� �����͸� �ѹ��� �ְ� ���� �� �ִ�.

struct tagMyVector
{
	float fx;
	float fy;
	float fz;
};

void Func(tagMyVector vec)
{
	cout << "X : " << vec.fx << endl;
	cout << "Y : " << vec.fy << endl;
	cout << "Z : " << vec.fz << endl;

}

void main()
{
	// tagMyVector tVector = { 1.f,2.f,3.f };

	// tVector�� ���� �ִ� ��� ����� ���� vec�� ����� ��� ����ȴ�.
	// Func(tVector);

	// ##1. ����ü�� ���ӵ� �޸𸮸� ���´�.

	// cout << &(tVector.fx) << endl;
	// cout << &(tVector.fy) << endl;
	// cout << &(tVector.fz) << endl;

	// ##2. ����ü ������_1

	// tagMyVector tVector = {};

	// tVector�� ������ tagMyVectorŸ������ tagMyVector*�� �ƴϴ�.
	// ����ü �̸��� �����Ͱ� �ƴϴ�.
	// cout << tVector << endl; // error
	
	// ��, ����ü ������ �ּҴ� �� ù ����� �ּҿ� ����.
	// ����ü �����ʹ� ���� ����ü�� ���� �ּ��̴�.
	// cout << &tVector << endl;
	// cout << &(tVector.fx) << endl;

	// ##3. ����ü ������_2

	tagMyVector tVector = {};

	// ���� ptr�� tVector�� �����ּҸ� �����ִ�.
	// �� �����ּҸ� ���ؼ� ��� ����� ���� �� ������ �� �ִ�.

	tagMyVector* ptr = &tVector;

	// ����ü �������� ��������.
	// (*ptr).fx = 100.f;
	// (*ptr).fy = 200.f;
	// (*ptr).fz = 300.f;

	// ����ü �������� ��������.(����)
	// ->ȭ��ǥ �����ڸ� ����Ѵ�.
	ptr->fx = 100.f;
	ptr->fy = 200.f;
	ptr->fz = 300.f;

	cout << tVector.fx << " , " << tVector.fy << " , " << tVector.fz;


	return;
}