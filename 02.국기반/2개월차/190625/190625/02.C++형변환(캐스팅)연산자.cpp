#include <iostream>

using namespace std;




class cBase
{
public:
	virtual ~cBase() {}
public:
	void Func()
	{
		cout << "Base ��� �Լ�" << endl;
	}

};

class cChild : public cBase
{
public:
	void Func()
	{
		cout << "Child ��� �Լ�" << endl;
	}
};

void main()
{
	// ##1. Static_cast�� ������
	// cBase* ptr = new cBase;

	// static_cast�� �ش� �ٿ�ĳ������ �ùٸ� ������ �߸��� ������ �ľ� ����.
	// �θ�Ŭ������ �ڽ�Ŭ������ ����Լ�,������ ����� �� ����.
	// static_cast<cChild*>(ptr)->Func();

	// ##2. dynamic_cast
	// ����ȯ ���� : ��Ÿ��
	// Ŭ���������� ����� ������ ������.
	// ������� : Ŭ���� ���ο� virtual Ű���尡 �ݵ�� �����ؾ� ��.

	// cBase* ptr = new cBase;
	// //cChild* ptr2 = static_cast<cChild*>(ptr);
	// 
	// cChild* ptr2 = dynamic_cast<cChild*>(ptr);
	// 
	// if (ptr2 == nullptr)
	// 	cout << "�߸��� �ٿ�ĳ���� �Դϴ�." << endl;
	// 
	// cout << "�ùٸ� �ٿ�ĳ���� �Դϴ�." << endl;
	// 
	// delete ptr;

	// ##3. dynamic_cast�� ����ȯ ����� Ŭ������ �����ͳ� ���۷��� Ÿ���̾���Ѵ�.
	cBase base;
	cChild child = dynamic_cast<cChild>(base);

}