#include <iostream> 

using namespace std;

// ##1. Ŭ����
// ��ü�� ǥ���� ��������� �ڷ���. C++ ���� ������ ����.
// ��ü�� �߻�ȭ��.

class cCustomer
{
public:
	// ��� �Լ�
	void OrderProduct()
	{
		cout << "������ �ֹ��մϴ�." << endl;
	}

	void TakeProduct()
	{
		cout << "������ �ǳ� �޽��ϴ�." << endl;
	}

private:
	int m_iMoney;	// ��� ����
};


void main()
{
	// ##2. ��ü(Object)
	// Ŭ������ ��üȭ. ���� �޸𸮿� ��ϵ�. (=instance)

	cCustomer object;

	object.OrderProduct();
	object.TakeProduct();


	system("pause");
	return;
}