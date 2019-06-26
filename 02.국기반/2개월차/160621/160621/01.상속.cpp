#include <iostream>
using namespace std;

// ##1. ���.

class cPerson
{
private:
	char m_szName[32];
	int m_iAge;
public:
	cPerson() = default;
	cPerson(const char* _pName, int _iAge) :m_iAge(_iAge)
	{
		strcpy_s(m_szName, _pName);
	}

	void WhatIsYourName()
	{
		cout << "My Name is " << m_szName << endl;
	}

	void HowOldAreYou()
	{
		cout << "I`m " << m_iAge << "year`s old" << endl;
	}
};

class cStudent :public cPerson
{
private:
	char m_szMajor[32];
public:
	cStudent() = default;
	cStudent(const char* _pName, const char* _pMajor, int _iAge)
		// : _m_iAge(_iAge)    // �θ��� ����� �ڽ��� �̴ϼȶ������ �ʱ�ȭ X
		: cPerson(_pName,_iAge)// �θ��� �����ִ� ������ ����� ȣ��.
	{
		strcpy_s(m_szMajor, _pMajor);
	}
};

void main()
{
	cPerson person("John", 22);
	person.WhatIsYourName();
	person.HowOldAreYou();

	return;
}