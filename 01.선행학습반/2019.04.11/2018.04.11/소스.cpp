#include <iostream> 
using namespace std;

namespace A
{
	void Render()
	{
		cout << "����ȣ1�� ���� �����ִ� ����� ���� �Լ�" << endl;
	}
}

namespace B
{
	void Render()
	{
		cout << "����ȣ2�� ���� �����ִ� ����� ���� �Լ�" << endl;
	}
}

void main()
{
	cout << "Hello World !!!" << endl;
	//A::Render();
	//B::Render();

	int i = 0;
	cout << i << endl;
}