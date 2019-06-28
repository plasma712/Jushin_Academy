#include <iostream>
#include <typeinfo>
using namespace std;

// ##1. RTTI (RunTime Type Information)
// ��Ÿ�� ���߿� Ÿ���� ������ �˾Ƴ� �� �ִ� C++ ���
// �����Լ� ���̺� ���� Ŭ���� Ÿ�� �̸��� ���� ��ϵ�.


class cBase
{
public:
	virtual ~cBase() {};
};

class cChild : public cBase
{
public:
	virtual void ChildFunc()
	{
		cout << "�ڽ��Լ�" << endl;
	}
};

void main()
{

	// ##1. �ùٸ��� ���� �ٿ� ĳ������ ������.
	// cBase�� �����Լ� ���̺��� cChildFunc�Լ��� �������� �����Ƿ� ��Ÿ�� ����
	// cBase* ptr = new cBase;
	// 
	// // static_cast<cChild*>(ptr)->ChildFunc();
	// // 
	// delete ptr;

	// ##2. typeid ������
	// cBase* ptr1 = new cBase;
	// cBase* ptr2 = new cChild;
	// 
	// cout << typeid(ptr1).name() << endl;
	// cout << typeid(ptr2).name() << endl;
	// 
	// cout << "---------------------------------------" << endl;
	// 
	// cout << typeid(*ptr1).name() << endl;
	// cout << typeid(*ptr2).name() << endl;

	//delete ptr1;
	//delete ptr2;

	// ##3. typeid �����ڷ� �ذ�

	// cBase* ptr = new cBase;
	// cBase* ptr = new cChild;
	// 
	// if (!strcmp("class cChild", typeid(*ptr).name()))
	// 	static_cast<cChild*>(ptr)->ChildFunc();
	// else
	// 	cout << "�ٿ� ĳ������ �ùٸ��� �ʽ��ϴ�." << endl;
	// 
	// delete ptr;

	// ##4. �ᱹ dynamic_cast�� RTTI�� ������� �۵��Ѵ�.
	return;
}