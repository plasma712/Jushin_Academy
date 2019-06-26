#include <iostream>

using namespace std;

// ��ü���� ���α׷���(OOP , Object Oriented Programming)

// ##1. ��������(Shallow copy)�� ��������(Deep copy)

class cObj
{
private:
	char* m_phone;

public:
	cObj(const char* pName)
	{
		int iLength = strlen(pName);
		m_phone = new char[iLength + 1];

		strcpy_s(m_phone, iLength + 1, pName);
	}

	// cObj(const cObj& _obj)
	// {
	// 	// ��������
	// 	// ���� �����ؾߵ� ����� "NeoPeople"������
	// 	// �ܼ� �ּ� ������ �����ϰ� �ִ�.
	// 	// ����, ������ �纻�� ���� �޸� ������ �ٶ󺸰� �ֱ� ������
	// 	// ���� ��۸� ������ ������ �߻��Ѵ�.
	// 	m_phone = _obj.m_phone;
	// }

	// ��������

	cObj(const cObj& _obj)
	{
		int iLength = strlen(_obj.m_phone);

		m_phone = new char[iLength + 1];
		// ��������� ���� ���� �����Ѵ�.
		strcpy_s(m_phone, iLength + 1, _obj.m_phone);
	}

	~cObj()
	{
		delete[] m_phone;
	}
public:
	void WhatIsYourName()
	{
		cout << m_phone << endl;
	}
};

void main()
{

	cObj objA("NeoPeople");
	objA.WhatIsYourName();

	cObj objB = objA;
	objB.WhatIsYourName();
	return;
}