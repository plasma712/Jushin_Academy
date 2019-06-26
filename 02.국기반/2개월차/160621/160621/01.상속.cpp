#include <iostream>
using namespace std;

// ##1. 상속.

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
		// : _m_iAge(_iAge)    // 부모의 멤버를 자식이 이니셜라이즈로 초기화 X
		: cPerson(_pName,_iAge)// 부모의 인자있는 생성자 명시적 호출.
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