#include <iostream>

using namespace std;

// ##1. ĸ��ȭ (encapsulation)
// Ŭ���� ������(�������)�� ���(����Լ�)�� �ϳ��� ���� 
// �������(��ü�� ���� ���)�� �ܺηκ��� �����.

class c�๰��
{
public:
	void ����()
	{
		cout << "�๰�� �½��ϴ�." << endl;
	}

};

class c��ä���
{
public:
	void ����()
	{
		cout << "��ä�Ⱑ �½��ϴ�." << endl;
	}
};

class c�ڸ�����
{
public:
	void ����()
	{
		cout << "�ڸ����� �½��ϴ�." << endl;
	}
};

class cContac600
{
public :
	void ����()
	{
		cap1.����();
		cap2.����();
		cap3.����();

	}
private:
	c�๰�� cap1;
	c��ä��� cap2;
	c�ڸ����� cap3;
};


void main()
{
	// c�๰�� cap1;
	// c��ä��� cap2;
	// c�ڸ����� cap3;
	// 
	// cap1.����();
	// cap2.����();
	// cap3.����();

	cContac600 cap;
	cap.����();
	

	system("pause");
	return;
}